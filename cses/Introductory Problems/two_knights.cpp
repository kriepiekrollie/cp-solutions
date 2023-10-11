#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;
    for (ll k = 1; k <= n; k++)
        cout << (k - 1) * (k + 4) * (k * k - 3 * k + 4) / 2 << '\n';

    return 0;
}
