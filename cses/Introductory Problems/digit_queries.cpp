#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    int q;
    cin >> q;
 
    int d;
    ll k, pow10;
    while (q--)
    {
        cin >> k;
        for (d = 1, pow10 = 1; d <= 17 && pow10 * 9 * d < k; d++, pow10 *= 10)
            k -= pow10 * 9 * d;
 
        ll num = (k - 1) / d;
        ll mod = (k - 1) % d;
 
        cout << to_string(pow10 + num)[mod] << '\n';
    }
 
    return 0;
}
