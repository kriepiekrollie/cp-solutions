#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n, res = 0;
    cin >> n;
    while (n)
        res += (n /= 5);
    cout << res << '\n';

    return 0;
}
