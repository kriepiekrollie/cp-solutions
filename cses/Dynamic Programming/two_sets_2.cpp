#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

ll n, cnt[70000];
ll binpow(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    if (n * (n + 1) % 4 != 0)
        return cout << "0\n", 0;

    cnt[0] = 1;
    for (int x = 1; x <= n; x++)
        for (int s = n * (n + 1) / 4 - x; s >= 0; s--)
            cnt[s + x] = (cnt[s + x] + cnt[s]) % MOD;

    cout << (cnt[n * (n + 1) / 4] * binpow(2, MOD - 2) % MOD) << '\n';

    return 0;
}
