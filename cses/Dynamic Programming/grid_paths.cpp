#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int n, dp[1001][1001] = {0};
char c;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            if (c == '*')
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }

    cout << dp[n][n] << '\n';

    return 0;
}

