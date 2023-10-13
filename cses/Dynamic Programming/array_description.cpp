#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int n, m, x[100001];
ll dp[100001][111] = {0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    for (int j = 1; j < 111; j += 3)
        dp[0][j] = 1;

    for (int i = 1; i <= n; i++)
        if (x[i] != 0)
            dp[i][x[i]] = (dp[i-1][x[i]-1] + dp[i-1][x[i]] + dp[i-1][x[i]+1]) % MOD;
        else
            for (int j = 1; j <= m; j++)
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;

    ll res = 0;
    for (int j = 1; j < 111; j++)
        res = (res + dp[n][j]) % MOD;
    cout << res << '\n';

    return 0;
}
