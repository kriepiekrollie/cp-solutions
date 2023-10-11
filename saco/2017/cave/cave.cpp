#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

char cave[500][500];
int dist[500][500][51] = {0};

struct State
{
    int y, x, d;
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K;
    int startX, startY;
    int goalX, goalY;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> cave[i][j];
            if (cave[i][j] == 'S') startX = j, startY = i;
            if (cave[i][j] == 'E') goalX = j, goalY = i;
        }

    queue<State> q;
    q.push({startY, startX, K});
    dist[startY][startX][K] = 1;

    while (!q.empty())
    {
        State U = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = U.x + dx[i], ny = U.y + dy[i];
            if (nx < 0 || M <= nx) continue;
            if (ny < 0 || N <= ny) continue;

            if (cave[ny][nx] == '#')
            {
                if (U.d > 0 && !dist[ny][nx][U.d-1])
                {
                    dist[ny][nx][U.d-1] = dist[U.y][U.x][U.d] + 1;
                    q.push({ny, nx, U.d - 1});
                }
            }
            else if (!dist[ny][nx][U.d])
            {
                dist[ny][nx][U.d] = dist[U.y][U.x][U.d] + 1;
                q.push({ny,nx,U.d});
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= K; i++)
    {
        if (dist[goalY][goalX][i])
            ans = min(ans, dist[goalY][goalX][i]);
    }

    return cout << (ans == INT_MAX ? -1 : ans - 1) << '\n', 0;
}
