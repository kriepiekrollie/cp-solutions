#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n;
ll x[1001], y[1001];
 
ll det(ll a, ll b, ll c, ll d)
{
    return a * d - b * c;
}
 
int main() 
{
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    x[n] = x[0], y[n] = y[0];
 
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += det(x[i], x[i+1], y[i], y[i+1]);
 
    cout << abs(res) << '\n';
 
    return 0;
}
