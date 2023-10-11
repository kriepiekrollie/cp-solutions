#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << (((a + b) % 3 == 0 && b <= 2 * a && a <= 2 * b) ? "YES\n" : "NO\n");
    }

    return 0;
}
