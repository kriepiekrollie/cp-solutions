#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;

int n, k, m, dp[1000001] = {0};
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> k >> n;
    for (m = 0; dp[n] < k; m++)
        for (int x = n; x > 0; x--)
            dp[x] += 1 + dp[x - 1];
    cout << m << '\n';

    return 0;
}
