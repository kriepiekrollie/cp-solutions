#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, dp[1000001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    iota(dp, dp + n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int x = i; x > 0; x /= 10)
            dp[i] = min(dp[i], 1 + dp[i - x % 10]);
    
    cout << dp[n] << '\n';

    return 0;
}

