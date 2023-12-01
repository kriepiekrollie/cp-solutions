#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x;
bitset<100001> possible;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    possible[0] = 1;
    while (n--)
    {
        cin >> x;
        possible |= possible << x;
    }

    cout << possible.count() - 1 << '\n';

    for (int i = 1; i <= 100000; i++)
        if (possible[i])
            cout << i << ' ';
    cout << '\n';

    return 0;
}
