#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 200000;

int n;
vector<int> g[MAX_N + 1];

int dp[MAX_N + 1][2];
void dfs(int u, int p = -1)
{
    dp[u][0] = dp[u][1] = 0;
    int best = 0;
    for (int v : g[u])
        if (v != p)
        {
            dfs(v, u);
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][0];
            best = max(best, 1 + dp[v][1] - dp[v][0]);
        }
    dp[u][0] += best;
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

    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';

    return 0;
}
