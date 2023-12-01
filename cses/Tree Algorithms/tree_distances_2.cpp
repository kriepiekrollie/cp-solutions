#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
using namespace std;
typedef long long ll;

const int MAX_N = 200000;

int n;
vector<int> g[MAX_N + 1];
int sz[MAX_N + 1], dist[MAX_N + 1];
ll res[MAX_N + 1];

void dfs1(int u, int p = -1)
{
    sz[u] = 1;
    for (int v : g[u])
        if (v != p)
        {
            dist[v] = dist[u] + 1;
            dfs1(v, u);
            sz[u] += sz[v];
        }
}

void dfs2(int u, int p = -1)
{
    for (int v : g[u])
        if (v != p) 
        {
            res[v] = res[u] + n - 2 * sz[v];
            dfs2(v, u);
        }
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

    dfs1(1);

    res[1] = 0;
    for (int i = 1; i <= n; i++)
        res[1] += dist[i];

    dfs2(1);

    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}
