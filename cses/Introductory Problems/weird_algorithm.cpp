#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;
    cout << n;
    while (n > 1)
    {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
        cout << ' ' << n;
    }
    cout << '\n';

    return 0;
}
