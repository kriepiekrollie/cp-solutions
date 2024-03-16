#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
using namespace std;
typedef long long ll;
 
int n, k;
vector<int> g[200001];
int sz[200001];
bool done[200001];
 
int find_size(int u, int p = -1)
{
    sz[u] = 1;
    for (int v : g[u])
        if (v != p && !done[v])
            sz[u] += find_size(v, u);
    return sz[u];
}
 
int find_centroid(int u, int n, int p = -1)
{
    for (int v : g[u])
        if (v != p && !done[v] && sz[v] * 2 >= n)
            return find_centroid(v, n, u);
    return u;
}
 
ll ans = 0, cnt[200001]; 
int mx_dist;
void dfs1(int u, int dist, int p)
{
    if (dist > k)
        return;
    ans += cnt[k - dist];
    for (int v : g[u])
        if (!done[v] && v != p)
            dfs1(v, dist + 1, u);
}
void dfs2(int u, int dist, int p)
{
    if (dist > k)
        return;
    mx_dist = max(mx_dist, dist);
    cnt[dist]++;
    for (int v : g[u])
        if (!done[v] && v != p)
            dfs2(v, dist + 1, u);
}
 
void centroid_decomposition(int u)
{
    int c = find_centroid(u, find_size(u));
    done[c] = true;
 
    if (sz[u] < k)
        return;
 
    cnt[0] = 1, mx_dist = 0;
    for (int v : g[c])
        if (!done[v])
        {
            dfs1(v, 1, c);
            dfs2(v, 1, c);
        }
 
    for (int i = 1; i <= mx_dist; i++)
        cnt[i] = 0;
 
    for (int v : g[c])
        if (!done[v])
            centroid_decomposition(v);
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> k;
    for (int i = 0, a, b; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    centroid_decomposition(1);
    cout << ans << '\n';
 
    return 0;
}
