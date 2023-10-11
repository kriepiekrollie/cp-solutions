#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void gray(int n, string &s, bool rev = false)
{
    if (n == 0)
    {
        cout << s << '\n';
        return;
    }

    s[s.size() - n] = rev ? '1' : '0';
    gray(n - 1, s, false);

    s[s.size() - n] = rev ? '0' : '1';
    gray(n - 1, s, true);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    string s(n, '0');
    gray(n, s);

    return 0;
}
