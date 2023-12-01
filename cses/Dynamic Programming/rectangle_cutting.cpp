#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, dp[501][501];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> a >> b;

    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
        {
            dp[i][j] = (i == j ? 0 : INT_MAX);
            for (int k = 1; 2 * k <= j; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            for (int k = 1; 2 * k <= i; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
        }

    cout << dp[a][b] << '\n';

    return 0;
}
