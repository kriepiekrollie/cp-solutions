#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll N; 
    cin >> N;

    if (__builtin_popcountl(N) <= 1)
        return cout << "-1\n", 0;

    ll k;
    for (k = 2; k <= N; k++)
        if ((N - k * (k - 1) / 2) % k == 0)
            break;

    ll S = (N - k * (k - 1) / 2) / k;
    ll T = k + S - 1;
    
    if (S <= 0 || T <= 0)
        return cout << "-1\n", 0;

    cout << S << ' ' << T << '\n';
    
    return 0;
}
