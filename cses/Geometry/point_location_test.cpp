#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll det(ll a, ll b, ll c, ll d)
{
    return a * d - b * c;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll t, x1, x2, x3, y1, y2, y3;
    cin >> t;
    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll d = det(x2 - x1, x3 - x1, y2 - y1, y3 - y1);

        if (d == 0)
            cout << "TOUCH\n";
        else if (d < 0)
            cout << "RIGHT\n";
        else
            cout << "LEFT\n";
    }

    return 0;
}
