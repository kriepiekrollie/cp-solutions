#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
vector<pair<int, ll>> g[2001];

set<int> bad[2001][2001];
ll dist[2001][2001];
bool vis[2001][2001];
pair<int, int> par[2001][2001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 0, a, b, l; i < m; i++)
    {
        cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }

    for (int i = 0, a, b, c; i < k; i++)
    {
        cin >> a >> b >> c;
        bad[a][b].insert(c);
    }

    pair<int, int> start = {0, 1};

    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push({0LL, start});

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dist[i][j] = LLONG_MAX;
    dist[start.first][start.second] = 0LL;
    par[start.first][start.second] = start;

    pair<ll, pair<int, int>> ans = {LLONG_MAX, start};

    while (!pq.empty())
    {
        auto [a, b] = pq.top().second;
        pq.pop();
        if (vis[a][b]) continue;
        if (b == n)
        {
            ans = min(ans, {dist[a][b], {a, b}});
            break;
        }
        vis[a][b] = true;
        for (auto [c, l] : g[b])
        {
            if (vis[b][c]) continue;
            if (bad[a][b].find(c) != bad[a][b].end()) continue;
            if (dist[b][c] <= dist[a][b] + l) continue;

            dist[b][c] = dist[a][b] + l;
            par[b][c] = {a, b};

            pq.push({-dist[b][c], {b, c}});
        }
    }

    if (ans.first == LLONG_MAX)
    {
        cout << "-1\n";
        return 0;
    }

    cout << ans.first << "\n1 ";

    pair<int, int> u = ans.second;
    vector<int> path;
    while (u.first != 0)
    {
        path.push_back(u.second);
        u = par[u.first][u.second];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
