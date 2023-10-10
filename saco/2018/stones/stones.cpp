#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M, Q;
ll bit[1001][1001] = {0};

void update(int y, int x, int d_val)
{
    for (int i = y; i <= N; i += (i & (-i)))
        for (int j = x; j <= M; j += (j & (-j)))
            bit[i][j] += d_val;
}

ll sum(int y, int x)
{
    ll res = 0;
    for (int i = y; i >= 1; i -= (i & (-i)))
        for (int j = x; j >= 1; j -= (j & (-j)))
            res += bit[i][j];
    return res;
}

ll sum(int y1, int x1, int y2, int x2)
{
    x1 = max(1, x1), y1 = max(1, y1), x2 = min(M, x2), y2 = min(N, y2);
    return sum(y2, x2) - sum(y2, x1 - 1) - sum(y1 - 1, x2) + sum(y1 - 1, x1 - 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> Q;
    for (int i = 1, x; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> x;
            update(i, j, x);
        }
        
    while (Q--)
    {
        int t, a, b;
        ll k;
        cin >> t >> a >> b >> k;
        a++, b++;

        if (t == 1)
        {
            update(a, b, -sum(a, b, a, b));
            update(a, b, k);
        }
        else
        {
            ll cost = 0, prev = 0;
            
            for (int i = 0; k > 0 && (a + i <= N || b + i <= M || a - i >= 1 || b - i >= 1); i++)
            {
                ll block = sum(a - i, b - i, a + i, b + i);
                block -= prev;

                if (block >= k)
                    cost += k * i * 2, k = 0;
                else
                    cost += block * i * 2, k -= block;

                prev += block;
            }
            cout << (k == 0 ? cost : -1) << '\n';
        }
    }

    return 0;
}
