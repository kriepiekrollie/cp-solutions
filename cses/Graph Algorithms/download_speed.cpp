#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;

const ull FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
struct custom_hash 
{
    static ull splitmix64(ull x) // http://xorshift.di.unimi.it/splitmix64.c
    {x+=0x9e3779b97f4a7c15,x=(x^(x>>30))*0xbf58476d1ce4e5b9,x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    uint operator()(ull x)const{return splitmix64(x+FIXED_RANDOM);}
    template<typename A,typename B>
    uint operator()(pair<A,B>x)const{return splitmix64(x.first+FIXED_RANDOM)^(splitmix64(x.second+FIXED_RANDOM)>>1);}
};
template<typename A,typename B>using umap=gp_hash_table<A,B,custom_hash>; // use unordered_map or map for strings
 
int n, m;
umap<int, ll> C[501];
 
bool vis[501];
int par[501];
bool bfs(int src, int goal)
{
    queue<int> q;
    q.push(src);
    memset(vis, false, sizeof(bool) * (n + 1));
    vis[src] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto [v, c] : C[u])
            if (c > 0 && !vis[v])
            {
                vis[v] = true;
                par[v] = u;
                q.push(v);
            }
    }
    return vis[goal];
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++)
    {
        cin >> a >> b >> c;
        C[a][b] += c;
    }
 
    ll maxflow = 0;
    while (bfs(1, n))
    {
        ll flow = 1e18;
        for (int u = n; u != 1; u = par[u])
            flow = min(flow, C[par[u]][u]);
        maxflow += flow;
        for (int u = n; u != 1; u = par[u])
        {
            C[par[u]][u] -= flow;
            C[u][par[u]] += flow;
        }
    }
    cout << maxflow << '\n';
 
    return 0;
}
