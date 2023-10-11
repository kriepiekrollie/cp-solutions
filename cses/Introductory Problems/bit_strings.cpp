#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n, x = 2, res = 1;
    cin >> n;
    while (n)
    {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    cout << res << '\n';

    return 0;
}
