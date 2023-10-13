#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll pref[5001], dp[5001][5001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    pref[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i][i];
        pref[i] = pref[i-1] + dp[i][i];
    }

    for (int w = 2; w <= n; w++)
        for (int l = 1, r = w; r <= n; l++, r++)
            dp[l][r] = pref[r] - pref[l-1] - min(dp[l+1][r], dp[l][r-1]);

    cout << dp[1][n] << '\n';

    return 0;
}
