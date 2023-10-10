#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll n, k;
ll t[8];
ll lcms[256];
ll cnt[256];

ll events(ll years)
{
    ll res = 0;
    for (int bit = 1; bit < (1 << n); bit++)
        if (cnt[bit] % 2 == 1)
            res += years / lcms[bit];
        else
            res -= years / lcms[bit];
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> t[i];

    for (int bit = 1; bit < (1 << n); bit++)
    {
        lcms[bit] = 1, cnt[bit] = 0;
        for (int i = 0; i < n; i++)
            if (bit & (1 << i))
                lcms[bit] = lcm(lcms[bit], t[i]), cnt[bit]++;
    }

    ll lo = 0, hi = LLONG_MAX;

    while (lo < hi)
    {
        ll mid = (lo + hi) / 2;
        if (events(mid) < k)
            lo = mid + 1;
        else
            hi = mid;
    }

    cout << 2020 + hi << '\n';

    return 0;
}
