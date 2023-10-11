#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n, x, mx = 0, ans = 0;
    cin >> n;
    while (n--)
    {
        cin >> x;
        mx = max(mx, x);
        ans += max(0LL, mx - x);
    }
    cout << ans << '\n';


    return 0;
}
