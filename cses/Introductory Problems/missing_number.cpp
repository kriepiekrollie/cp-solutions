#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n, res, x;
    cin >> n;
    res = n * (n + 1) / 2;
    while (--n)
    {
        cin >> x;
        res -= x;
    }
    cout << res << '\n';

    return 0;
}
