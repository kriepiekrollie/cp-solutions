#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll N, q;
    cin >> N >> q;

    ll n = N;
    vector<pair<ll,int>> pfactors;
    for (ll p = 2; p * p <= n; p++)
    {
        int k = 0;
        while (n % p == 0)
        {
            n /= p;
            k++;
        }
        if (k > 0)
            pfactors.emplace_back(p, k);
    }
    if (n > 1)
    {
        pfactors.emplace_back(n, 1);
        n = 1;
    }

    set<ll> divisors = {1};
    for (const auto &[p, k] : pfactors)
    {
        set<ll> newdivisors;
        ll P = p;
        for (int i = 0; i < k; i++)
        {
            for (const ll &x: divisors)
                newdivisors.insert(x * P);
            P *= p;
        }
        for (const ll &x : newdivisors)
            divisors.insert(x);
    }

    for (ll j = 0, a, b; j < q; j++)
    {
        cin >> a >> b;
        auto it = divisors.lower_bound(N / b);

        while (N / *it > b) it++;

        if (N / *it >= a)
            cout << *it << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}
