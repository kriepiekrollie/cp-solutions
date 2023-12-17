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
 
umap<ll, ll> sumz(vector<ll> &a)
{
    int m = a.size();
    umap<ll, ll> cnt;
 
    for (int i = 0; i < (1 << m); i++)
    {
        ll sum = 0;
        for (int j = 0; j < m; j++)
            if (i & (1 << j))
                sum += a[j];
 
        if (cnt.find(sum) == cnt.end())
            cnt[sum] = 0;
        cnt[sum]++;
    }
 
    return cnt;
}
 
int n;
ll x;
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> x;
    vector<ll> a(n/2), b(n-(n/2));
    for (int i = 0; i < n/2; i++)
        cin >> a[i];
    for (int i = n / 2; i < n; i++)
        cin >> b[i - n/2];
 
    umap<ll, ll> cntA = sumz(a), cntB = sumz(b);
 
    ll res = 0;
    for (auto [val, cnt] : cntA)
        if (cntB.find(x - val) != cntB.end())
            res += cnt * cntB[x - val];
 
    cout << res << '\n';
 
    return 0;
}
