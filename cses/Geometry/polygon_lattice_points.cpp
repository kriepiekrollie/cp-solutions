#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll det(ll a, ll b, ll c, ll d)
{
    return a * d - b * c;
}
 
ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
 
int n;
ll x[10001], y[10001];
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    x[n] = x[0], y[n] = y[0];
 
    ll a = 0;
    for (int i = 0; i < n; i++)
        a += det(x[i], x[i+1], y[i], y[i+1]);
 
    a = abs(a);
 
    ll b = 0;
    for (int i = 0; i < n; i++)
        b += abs(gcd(y[i+1] - y[i], x[i+1] - x[i]));
 
    // pick's theorem
    ll i = (a - b) / 2 + 1;
    cout << i << ' ' << b << '\n';
 
    return 0;
}
