#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a, b;
vector<int> g[10000];

vector<int> bfs(int src)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
            if (dist[v] == INT_MAX)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    return dist;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> a >> b;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> distA = bfs(a);
    vector<int> distB = bfs(b);

    int ans = -1, best = INT_MAX;
    for (int i = 1; i <= n; i++)
        if (max(distA[i], distB[i]) < best)
        {
            best = max(distA[i], distB[i]);
            ans = i;
        }
            
    cout << ans << '\n';

    return 0;
}
