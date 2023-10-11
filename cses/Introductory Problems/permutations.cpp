#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    if (n == 1)
        return cout << "1\n", 0;
    if (n <= 3)
        return cout << "NO SOLUTION\n", 0;

    for (int i = 2; i <= n; i += 2)
        cout << i << ' ';
    for (int i = 1; i <= n; i += 2)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
