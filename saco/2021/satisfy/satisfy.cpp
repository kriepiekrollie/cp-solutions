#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, V;
int grid[1000][1000];
bool vis[1000][1000];
int dist[1000][1000];

int dp[2001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> V;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    queue<pair<int,int>> q;
    q.push({0, 0});

    vis[0][0] = true;
    dist[0][0] = 0;

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            if (i + dy[d] < 0 || n <= i + dy[d])
                continue;
            if (j + dx[d] < 0 || m <= j + dx[d])
                continue;
            if (grid[i+dy[d]][j+dx[d]] < 0)
                continue;
            if (vis[i+dy[d]][j+dx[d]])
                continue;
            vis[i+dy[d]][j+dx[d]] = true;
            dist[i+dy[d]][j+dx[d]] = dist[i][j] + 1;
            q.push({i+dy[d], j+dx[d]});
        }
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] > 0)
                v.push_back({grid[i][j], dist[i][j]});
    int t = v.size();

    dp[0] = 0;
    for (int val = 1; val <= 2000; val++)
    {
        dp[val] = 2e6;
        for (int i = 0; i < t; i++)
            if (v[i].first <= val)
                dp[val] = min(dp[val], dp[val - v[i].first] + v[i].second);
    }

    int steps = INT_MAX;
    for (int val = V; val <= 2000; val++)
        steps = min(steps, dp[val]);
    cout << 2 * steps << '\n';

    return 0;
}
