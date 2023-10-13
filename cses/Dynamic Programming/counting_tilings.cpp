#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

const uint MOD = 1000000007;

uint n, m;
vector<uint> g[1024];

bool bad[1024] = {false};
uint dp[1000][1024] = {0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    uint mx = (1 << n);
    for (uint x = 0; x < mx; x++)
    {
        int cnt = 0;
        for (uint i = 0; i < n && !bad[x]; i++)
            if (x & (1 << i))
                bad[x] |= (cnt & 1), cnt = 0;
            else
                cnt++;
        if (cnt & 1)
            bad[x] = true;
    }

    for (uint a = 0; a < mx; a++)
    {
        uint complement = (mx - 1) & (~a);
        for (uint b = complement; b > 0; b = (b - 1) & complement)
            if (!bad[a | b])
                g[a].push_back(b);

        if (!bad[a])
            g[a].push_back(0);
    }

    dp[0][0] = 1;
    for (uint i = 1; i < m; i++)
        for (uint a = 0; a < mx; a++)
            for (uint b : g[a])
                dp[i][a] = (dp[i][a] + dp[i-1][b]) % MOD;

    uint res = 0;
    for (uint x = 0; x < mx; x++)
        if (!bad[x])
            res = (res + dp[m-1][x]) % MOD;

    cout << res << '\n';

    return 0;
}
