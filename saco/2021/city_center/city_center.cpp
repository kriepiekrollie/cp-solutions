#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = 500000;

int n;
vector<pair<int, int>> g[MaxN];

int dist[MaxN] = {0};
int par[MaxN];
int find_furthest(int u, int p = -1)
{
    int res = u;
    for (auto [v, l] : g[u])
        if (v != p)
        {
            dist[v] = dist[u] + l;
            par[v] = u;
            int x = find_furthest(v, u);
            if (dist[x] > dist[res])
                res = x;
        }
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0, a, b, l; i < n - 1; i++)
    {
        cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }

    par[0] = 0, dist[0] = 0;
    int a = find_furthest(0);
    par[a] = a, dist[a] = 0;
    int b = find_furthest(a);

    int ans = dist[b], i = b;
    while (i != a)
    {
        ans = min(ans, max(dist[b] - dist[i], dist[i]));
        i = par[i];
    }

    cout << ans << '\n';
    return 0;
}
