#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll q, x, y, d;
    cin >> q;
    while (q--)
    {
        cin >> y >> x;
        d = max(x, y) - 1;
        if (d % 2) swap(x, y);
        cout << d * (d + 1) + x - y + 1 << '\n';
    }


    return 0;
}
