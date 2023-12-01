#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int n, x, c[100];
int dp[1000001] = {0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = c[i]; j <= x; j++)
            dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
    
    cout << dp[x] << '\n';

    return 0;
}

