#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
using namespace std;
typedef long long ll;

const int MAX_N = 200000;

int n;
vector<int> g[MAX_N + 1];

int dp[MAX_N + 1][2];
int c[MAX_N + 1];
void dfs1(int u, int p = -1)
{
    dp[u][0] = dp[u][1] = 0;
    c[u] = 0;
    for (int v : g[u])
        if (v != p)
        {
            dfs1(v, u);
            if (dp[v][0] + 1 > dp[u][0])
                dp[u][1] = dp[u][0], dp[u][0] = dp[v][0] + 1, c[u] = v;
            else if (dp[v][0] + 1 > dp[u][1])
                dp[u][1] = dp[v][0] + 1;
        }
}

void dfs2(int u, int p = -1)
{
    for (int v : g[u])
        if (v != p)
        {
            if (c[u] == v)
            {
                if (dp[u][1] + 1 > dp[v][0])
                    dp[v][1] = dp[v][0], dp[v][0] = dp[u][1] + 1, c[v] = u;
                else if (dp[u][1] + 1 > dp[v][1])
                    dp[v][1] = dp[u][1] + 1;
            }
            else
                dp[v][1] = dp[v][0], dp[v][0] = dp[u][0] + 1, c[v] = u;
            dfs2(v, u);
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << dp[i][0] << ' ';
    cout << '\n';

    return 0;
}
