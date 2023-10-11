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
    
    if (n % 4 == 0)
    {
        cout << "YES\n";

        cout << n / 2 << '\n';
        for (int i = 1; i + 3 <= n; i += 4)
            cout << i << ' ' << i + 3 << ' ';
        cout << '\n';

        cout << n / 2 << '\n';
        for (int i = 2; i + 1 <= n; i += 4)
            cout << i << ' ' << i + 1 << ' ';
        cout << '\n';

        return 0;
    }

    if (n % 4 == 3)
    {
        cout << "YES\n";

        cout << n / 2 + 1 << '\n';
        cout << "1 2 ";
        for (int i = 4; i + 3 <= n; i += 4)
            cout << i << ' ' << i + 3 << ' ';
        cout << '\n';

        cout << n / 2 << '\n';
        cout << "3 ";
        for (int i = 5; i + 1 <= n; i += 4)
            cout << i << ' ' << i + 1 << ' ';
        cout << '\n';

        return 0;
    }
    cout << "NO\n";

    return 0;
}
