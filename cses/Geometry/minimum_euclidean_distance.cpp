#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pt;
 
#define x first
#define y second
 
ll dist(const pt &a, const pt &b)
{
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    int n;
    cin >> n;
 
    vector<pt> pts(n);
    for (int i = 0; i < n; i++)
        cin >> pts[i].x >> pts[i].y;
 
    sort(pts.begin(), pts.end(), [](const pt &a, const pt &b)
        { return make_pair(a.y, a.x) < make_pair(b.y, b.x); });
    
    set<pt> close;
    ll ans = dist(pts[0], pts[1]);
    int j = 1;
    for (int i = 0; i < n - 1; i++)
    {
        close.erase(pts[i]);
        j = max(j, i+1);
        while (j < n && (pts[j].y - pts[i].y) * (pts[j].y - pts[i].y) <= ans) 
            close.insert(pts[j++]);
 
        auto lo = close.lower_bound({pts[i].x - ans, pts[i].y});
        auto hi = close.upper_bound({pts[i].x + ans, pts[i].y});
        if (lo == close.end()) continue;
 
        for (auto it = lo; it != hi; it++)
            ans = min(ans, dist(pts[i], *it));
 
        while (j-1 > i && (pts[j-1].y - pts[i].y) * (pts[j-1].y - pts[i].y) > ans) 
            close.erase(pts[--j]);
    }

    cout << ans << '\n';

    return 0;
}
