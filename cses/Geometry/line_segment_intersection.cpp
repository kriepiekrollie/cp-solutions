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
 
    int T; 
    ll x1, y1, x2, y2, x3, y3, x4, y4, d, t, u;
    cin >> T;
    while (T--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        d = det(x1 - x2, x3 - x4, y1 - y2, y3 - y4);
        if (d == 0)
        {
            if (((y3 - y1) * (x2 - x1) == (x3 - x1) * (y2 - y1)) && 
               !(max(x1, x2) < min(x3, x4) || max(x3, x4) < min(x1, x2) ||
                max(y1, y2) < min(y3, y4) || max(y3, y4) < min(y1, y2)))
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }

        t = det(x1 - x3, x3 - x4, y1 - y3, y3 - y4);
        u = det(x1 - x3, x1 - x2, y1 - y3, y1 - y2);
        if (d < 0) t *= -1, u *= -1, d *= -1;
        cout << ((0 <= t && t <= d && 0 <= u && u <= d) ? "YES\n" : "NO\n");
    }
    return 0;
}
