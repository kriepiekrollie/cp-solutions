#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow9[20];

ll count(ll x)
{
    if (x < 0) return 0;
    if (x == 0) return 1;

    string s = to_string(x);
    int k = s.size();

    ll res = 0;
    for (int i = 0; i < k; i++)
    {
        res += (s[i] - '0' - (i > 0 && s[i-1] < s[i])) * pow9[k-1-i];
        if (i > 0 && s[i-1] == s[i])
            break;
    }

    bool yes = true;
    for (int i = 0; i < k - 1; i++)
    {
        res += pow9[i];
        yes &= (s[i] != s[i+1]);
    }

    return res + yes;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    pow9[0] = 1;
    for (int i = 1; i < 20; i++)
        pow9[i] = pow9[i-1] * 9;

    ll a, b;
    cin >> a >> b;
    cout << count(b) - count(a-1) << '\n';

    return 0;
}
