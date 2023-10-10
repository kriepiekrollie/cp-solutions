#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = 1000001;
int n, m, k;
vector<int> g[MaxN];
bool vis[MaxN] = {false};

vector<vector<int>> cycles;
vector<vector<int>> paths;

vector<int> cur;
void dfs(int u)
{
    vis[u] = true;
    cur.push_back(u);
    for (int v : g[u])
        if (!vis[v])
            dfs(v);
}

int assign(int d)
{
    int res = 0;
    for (vector<int> &cycle : cycles)
        res += max(1, (int)cycle.size() / d);
    for (vector<int> &path : paths)
        res += 1 + (path.size() - 1) / d;
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // find all paths
    for (int i = 1; i <= n; i++)
        if (!vis[i] && g[i].size() < 2)
        {
            cur = vector<int>();
            dfs(i);
            paths.push_back(cur);
        }

    // find all cycles
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            cur = vector<int>();
            dfs(i);
            cycles.push_back(cur);
        }

    if (cycles.size() + paths.size() >= k)
    {
        cout << "infinity\n";
        int cnt = 0;
        for (int i = 0; i < cycles.size() && cnt < k; i++, cnt++)
            cout << cycles[i][0] << ' ';

        for (int i = 0; i < paths.size() && cnt < k; i++, cnt++)
            cout << paths[i][0] << ' ';
        cout << '\n';

        return 0;
    }

    int lo = 0, hi = 2 * n;
    while (lo < hi)
    {
        int mid = lo + (hi - lo + 1) / 2;
        if (assign(mid) >= k)
            lo = mid;
        else
            hi = mid - 1;
    }

    int d = lo;
    cout << d << '\n';

    int cnt = 0;
    for (int i = 0; i < cycles.size() && cnt < k; i++)
        for (int j = 0; j < max(1, (int) cycles[i].size() / d) && cnt < k; j++)
        {
            cout << cycles[i][j * d] << ' ';
            cnt++;
        }

    for (int i = 0; i < paths.size() && cnt < k; i++)
        for (int j = 0; j < 1 + (paths[i].size() - 1) / d && cnt < k; j++)
        {
            cout << paths[i][j * d] << ' ';
            cnt++;
        }
    cout << '\n';

    return 0;
}
