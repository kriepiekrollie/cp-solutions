#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x;
int h[1001], s[1001];
int dp[1001][100001] = {0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= x; j++)
            if (h[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], s[i] + dp[i-1][j-h[i]]);

    cout << dp[n][x] << '\n';

    return 0;
}
