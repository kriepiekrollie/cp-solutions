#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 200000;
 
int n, q;
ll x[MAX_N + 1];
vector<int> g[MAX_N + 1];
int sz[MAX_N + 1], par[MAX_N + 1], top[MAX_N + 1], in[MAX_N + 1], out[MAX_N + 1], h[MAX_N + 1];
int t[4 * MAX_N];
 
void update(int i, int val)
{
    t[i += n] = val;
    for (i /= 2; i; i /= 2)
        t[i] = max(t[i * 2], t[i * 2 + 1]);
}
 
int query(int l, int r)
{
    int res = 0;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2)
    {
        if (l & 1)
            res = max(res, t[l++]);
        if (r & 1)
            res = max(res, t[--r]);
    }
    return res;
}
 
void dfs_sz(int u)
{
    sz[u] = 1;
    for (int &v : g[u])
        if (v != par[u])
        {
            h[v] = h[u] - 1;
            par[v] = u;
            dfs_sz(v);
            sz[u] += sz[v];
            if (sz[v] > sz[g[u][0]])
                swap(v, g[u][0]);
        }
}
 
int cnt = 0;
void dfs_hld(int u)
{
    in[u] = cnt++;
    update(in[u], x[u]);
 
    for (int v : g[u])
        if (v != par[u])
        {
            top[v] = (v == g[u][0] ? top[u] : v);
            dfs_hld(v);
        }
 
    out[u] = cnt;
}
 
int path(int u, int v)
{
    int res = 0;
    while (top[u] != top[v])
    {
        if (h[top[u]] > h[top[v]])
            swap(u, v);
 
        res = max(res, query(in[top[u]], in[u]));
        u = par[top[u]];
    }
    if (h[u] < h[v])
        swap(u, v);
    res = max(res, query(in[u], in[v]));
    return res;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 0, a, b; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
 
    par[1] = 1;
    dfs_sz(1);
    top[1] = 1;
    dfs_hld(1);
 
    ll t, a, b;
    while (q--)
    {
        cin >> t >> a >> b;
        if (t == 1)
        {
            x[a] = b;
            update(in[a], x[a]);
        }
        else
            cout << path(a, b) << ' ';
    }
    cout << '\n';
 
    return 0;
}
