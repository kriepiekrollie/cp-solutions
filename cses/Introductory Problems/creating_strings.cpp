#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, p = "";
int n, fac[10], cnt[26] = {0};

void solve(int i = 0)
{
    if (i == n)
    {
        cout << p << '\n';
        return;
    }
    for (char c = 'a'; c <= 'z'; c++)
        if (cnt[c - 'a'] > 0)
        {
            p.push_back(c);
            cnt[c - 'a']--;

            solve(i + 1);

            p.pop_back();
            cnt[c - 'a']++;
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> s;
    n = s.size();
    for (char c : s)
        cnt[c - 'a']++;

    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i-1] * i;

    int num = fac[n];
    for (char c = 'a'; c <= 'z'; c++)
        num /= fac[cnt[c - 'a']];

    cout << num << '\n';
    solve();

    return 0;
}
