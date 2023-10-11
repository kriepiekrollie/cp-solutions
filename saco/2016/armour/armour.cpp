#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, t;
ll x[10001], p[10001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, t;
    cin >> n >> t;
    p[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        p[i] = x[i] + p[i-1];
    }

    int d;
    while (t--)
    {
        cin >> d;
        ll ans = 0, best = 0;
        for (int l = 1, r = d; r <= n; l++, r++)
            if (p[r] - p[l-1] > best)
                ans = l, best = p[r] - p[l-1];
        cout << ans << ' ' << best << '\n';
    }

    return 0;
}
