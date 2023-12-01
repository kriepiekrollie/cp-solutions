#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
using namespace std;
typedef long long ll;

int n, m;
string s, t;
int dp[5001][5001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> s >> t;
    n = s.size(), m = t.size();

    dp[n][m] = 0;
    for (int i = n - 1; i >= 0; i--)
        dp[i][m] = dp[i+1][m] + 1;
    for (int j = m - 1; j >= 0; j--)
        dp[n][j] = dp[n][j+1] + 1;

    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            dp[i][j] = min({dp[i][j+1] + 1, dp[i+1][j] + 1, dp[i+1][j+1] + (s[i] != t[j])});

    cout << dp[0][0] << '\n';

    return 0;
}
