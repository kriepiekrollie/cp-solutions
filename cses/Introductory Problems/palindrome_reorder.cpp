#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[26] = {0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;
 
    for (char c : s)
        cnt[c - 'A']++;
 
    int cnt_odd = 0;
    char mid = '#';
    for (char c = 'A'; c <= 'Z'; c++)
        if (cnt[c - 'A'] % 2)
            cnt_odd++, mid = c;
 
    if (cnt_odd > 1)
        return cout << "NO SOLUTION\n", 0;
 
    string res = "";
    for (char c = 'A'; c <= 'Z'; c++)
        if (c != mid)
            res += string(cnt[c - 'A'] / 2, c);
 
    if (cnt_odd)
        res += string(cnt[mid - 'A'], mid);
 
    for (char c = 'Z'; c >= 'A'; c--)
        if (c != mid)
            res += string(cnt[c - 'A'] / 2, c);
 
    cout << res << '\n';

    return 0;
}
