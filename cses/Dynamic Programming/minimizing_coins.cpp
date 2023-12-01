#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x, c[100];
ll dp[1000001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    dp[0] = 0;
    for (int j = 1; j <= x; j++)
    {
        dp[j] = INT_MAX;
        for (int i = 0; i < n && c[i] <= j; i++)
            dp[j] = min(dp[j], 1 + dp[j - c[i]]);
    }
    cout << ((dp[x] == INT_MAX) ? -1 : dp[x]) << '\n';

    return 0;
}
