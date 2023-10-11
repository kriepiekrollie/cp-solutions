#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;
    char cur = '.';
    int cnt = 0, mx = 0;
    for (char c : s)
    {
        if (c == cur)
            cnt++;
        else
        {
            mx = max(mx, cnt);
            cnt = 1;
            cur = c;
        }
    }
    mx = max(mx, cnt);
    cout << mx << '\n';

    return 0;
}
