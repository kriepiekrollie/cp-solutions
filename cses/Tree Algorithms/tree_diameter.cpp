#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
using namespace std;
typedef long long ll;

const int MAX_N = 200000;

int n;
vector<int> g[MAX_N + 1];

int dist[MAX_N + 1];
void dfs(int u, int p = -1)
{
    for (int v : g[u])
        if (v != p)
        {
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
}

pair<int, int> furthest(int src)
{
    dist[src] = 0;
    dfs(src);
    int ans = 1;
    for (int i = 1; i <= n; i++)
        if (dist[i] > dist[ans])
            ans = i;
    return {ans, dist[ans]};
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << furthest(furthest(1).first).second << '\n';

    return 0;
}
