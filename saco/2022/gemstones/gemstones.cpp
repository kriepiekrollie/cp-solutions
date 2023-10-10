#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mp make_pair

const int MaxN = 200000;
int n, x[MaxN], y[MaxN], z[MaxN], c[MaxN], cnt[MaxN] = {0};
vector<int> g[MaxN];
bool vis[MaxN];
int dp[MaxN][2];

void dfs(const int &u, const int &p = -1)
{
    vis[u] = true;
    for (int i = 0; i < 2; i++)
        dp[u][i] = i;
    for (const int &v : g[u])
        if (v != p && c[v] == c[u])
        {
            dfs(v, u);
            dp[u][1] += dp[v][0];
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    unordered_map<ll, pair<int,int>> tri;
    for (int i = 0; i < n - 2; i++)
    {
        cin >> x[i] >> y[i] >> z[i] >> c[i];
        x[i]--, y[i]--, z[i]--;
        if (x[i] > y[i]) swap(x[i], y[i]);
        if (x[i] > z[i]) swap(x[i], z[i]);
        if (y[i] > z[i]) swap(y[i], z[i]);
        tri[n * x[i] + y[i]] = {-1, -1};
        tri[n * x[i] + z[i]] = {-1, -1};
        tri[n * y[i] + z[i]] = {-1, -1};
    }

    for (int i = 0; i < n - 2; i++)
    {
        if (tri[n * x[i] + y[i]].first == -1)
            tri[n * x[i] + y[i]].first = i;
        else
            tri[n * x[i] + y[i]].second = i;

        if (tri[n * x[i] + z[i]].first == -1)
            tri[n * x[i] + z[i]].first = i;
        else
            tri[n * x[i] + z[i]].second = i;

        if (tri[n * y[i] + z[i]].first == -1)
            tri[n * y[i] + z[i]].first = i;
        else
            tri[n * y[i] + z[i]].second = i;
    }

    for (const pair<ll, pair<int,int>> &edge : tri)
    {
        if (edge.second.second == -1)
            continue;
        g[edge.second.first].push_back(edge.second.second);
        g[edge.second.second].push_back(edge.second.first);
    }

    int ans = 0;
    for (int i = 0; i < n - 2; i++)
        if (!vis[i])
        {
            dfs(i);
            cnt[c[i]] += max(dp[i][0], dp[i][1]);
            ans = max(ans, cnt[c[i]]);
        }

    cout << ans << '\n';
    return 0;
}
