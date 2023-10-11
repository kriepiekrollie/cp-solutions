#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int x[1000];
int K, n, m;
int bonus[26][26] = {0};
ll dp[1000][26][101];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> s >> K >> m;
    n = s.size();
    for (int i = 0; i < n; i++)
        x[i] = s[i] - 'a';
    for (int i = 0; i < m; i++)
    {
        char a, b;
        cin >> a >> b;
        cin >> bonus[a - 'a'][b - 'a'];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k <= K; k++)
                dp[i][j][k] = LLONG_MIN / 2;

    dp[0][x[0]][0] = 0;
    for (int i = 1; i < n; i++)
        dp[i][x[i]][0] = dp[i-1][x[i-1]][0] + bonus[x[i-1]][x[i]];

    for (int k = 1; k <= K; k++)
    {
        for (int a = 0; a < 26; a++)
            dp[0][a][k] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][x[i]][k] = dp[i][x[i]][k-1];
            for (int b = 0; b < 26; b++)
                dp[i][x[i]][k] = max(dp[i][x[i]][k], dp[i-1][b][k] + bonus[b][x[i]]);
            for (int a = 0; a < 26; a++) if (a != x[i])
                for (int b = 0; b < 26; b++)
                    dp[i][a][k] = max(dp[i][a][k], dp[i-1][b][k-1] + bonus[b][a]);
        }
    }
    ll res = LLONG_MIN;
    for (int a = 0; a < 26; a++)
        res = max(res, dp[n-1][a][K]);
    cout << res << '\n';

    return 0;
}
