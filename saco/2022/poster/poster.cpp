#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct rect
{
    ll x1, y1, x2, y2;
};

const int MaxN = 2500;
ll W, H, w, h, n;
rect p[MaxN];

set<ll> xvals, yvals;

int cntX = 0, cntY = 0;
unordered_map<ll, int> smolX, smolY;
ll bigX[MaxN], bigY[MaxN];
ll grid[MaxN][MaxN] = {0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> W >> H >> w >> h >> n;

    xvals = {0LL, w, W - w, W};
    yvals = {0LL, h, H - h, H};

    for (ll i = 0, x1, y1, x2, y2; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        xvals.insert(max(0LL, x1 - w));
        xvals.insert(x1);
        xvals.insert(x2);
        xvals.insert(min(W, x2 + w));

        yvals.insert(max(0LL, y1 - h));
        yvals.insert(y1);
        yvals.insert(y2);
        yvals.insert(min(H, y2 + h));

        p[i] = {x1, y1, x2, y2};
    }

    for (ll xval : xvals)
    {
        smolX[xval] = cntX;
        bigX[cntX] = xval;
        cntX++;
    }

    for (ll yval : yvals)
    {
        smolY[yval] = cntY;
        bigY[cntY] = yval;
        cntY++;
    }

    for (int i = 0; i < n; i++)
    {
        int x1 = smolX[p[i].x1], y1 = smolY[p[i].y1];
        int x2 = smolX[p[i].x2], y2 = smolY[p[i].y2];
        grid[x1 + 1][y1 + 1]++;
        grid[x2 + 1][y1 + 1]--;
        grid[x1 + 1][y2 + 1]--;
        grid[x2 + 1][y2 + 1]++;
    }

    for (int x = 1; x < cntX; x++)
        for (int y = 1; y < cntY; y++)
            grid[x][y] += grid[x-1][y] + grid[x][y-1] - grid[x-1][y-1];

    for (int x = 1; x < cntX; x++)
        for (int y = 1; y < cntY; y++)
            grid[x][y] = (grid[x][y] > 0) * (bigX[x] - bigX[x-1]) * (bigY[y] - bigY[y-1]) + grid[x-1][y] + grid[x][y-1] - grid[x-1][y-1];

    ll A = w * h, X = 0, Y = 0;
    for (int y1 = 0; y1 < cntY; y1++) 
        if (smolY.find(bigY[y1] + h) != smolY.end())
        {
            int y2 = smolY[bigY[y1] + h];
            for (int x1 = 0; x1 < cntX; x1++)
                if (smolX.find(bigX[x1] + w) != smolX.end())
                {
                    int x2 = smolX[bigX[x1] + w];
                    ll area = grid[x2][y2] - grid[x1][y2] - grid[x2][y1] + grid[x1][y1];
                    if (A > area) 
                        A = area, X = bigX[x1], Y = bigY[y1];
                }
        }

    cout << A << ' ' << X << ' ' << Y << '\n';
    return 0;
}

