#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> g[100000];
vector<int> temp[100000];

int dist[100000];
bool vis[100000];
void dfs(int u)
{
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v])
        {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
}

vector<vector<pair<int, int>>> res;
void Slice()
{
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            dist[i] = 0;
            dfs(i);
        }

    m = 0;
    for (int i = 0; i < n; i++)
        temp[i] = vector<int>();

    res.push_back(vector<pair<int,int>>());
    for (int u = 0; u < n; u++)
        for (int v : g[u]) 
            if (v < u)
            {
                if (dist[u] % 2 == dist[v] % 2)
                {
                    temp[u].push_back(v);
                    temp[v].push_back(u);
                    m++;
                }
                else if (dist[u] % 2 == 0)
                    res.back().push_back({u, v});
                else
                    res.back().push_back({v, u});
            }
    swap(g, temp);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int k;
    cin >> n >> m >> k;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    while (m)
        Slice();

    cout << res.size() << '\n';
    for (auto v : res)
    {
        cout << v.size() << '\n';
        for (auto [x, y] : v)
            cout << x + 1 << ' ' << y + 1 << '\n';
    }

    return 0;
}
