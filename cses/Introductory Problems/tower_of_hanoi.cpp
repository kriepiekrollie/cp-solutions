#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void hanoi(int n, char a = '1', char b = '2', char c = '3')
{
    if (n == 0)
        return;
    hanoi(n - 1, a, c, b);
    cout << a << ' ' << c << '\n';
    hanoi(n - 1, b, a, c);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    hanoi(n);

    return 0;
}
