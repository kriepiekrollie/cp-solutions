#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cl[8], rd[15], ld[15], open[8][8] = {false};

ll solve(const int &i = 0)
{
    if (i == 8)
        return 1;
 
    ll res = 0;
    for (int j = 0; j < 8; j++)
        if (!cl[j] && !rd[j + i] && !ld[7 + j - i] && open[i][j])
        {
            cl[j] = rd[j + i] = ld[7 + j - i] = true;
            res += solve(i + 1);
            cl[j] = rd[j + i] = ld[7 + j - i] = false;
        }
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    char c;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            cin >> c;
            open[i][j] = (c == '.');
        }

    cout << solve() << '\n';

    return 0;
}
