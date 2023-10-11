#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
bool vis[9][9] = {false};
int p[48];
int solve(int i, int j, int idx)
{
    if (vis[i][j + 1] && vis[i][j - 1] && !vis[i + 1][j] && !vis[i - 1][j]) 
        return 0;
    if (vis[i + 1][j] && vis[i - 1][j] && !vis[i][j + 1] && !vis[i][j - 1]) 
        return 0;
    if (idx == 48) 
        return (i == 7 && j == 1);
    if (i == 7 && j == 1) 
        return (idx == 48);
 
    vis[i][j] = true;
    int res = 0;
    if (p[idx] >= 0 && !vis[i + dy[p[idx]]][j + dx[p[idx]]])
       res += solve(i + dy[p[idx]], j + dx[p[idx]], idx + 1);
    else if (p[idx] == -1) 
        for (int d = 0; d < 4; d++)
            if (!vis[i + dy[d]][j + dx[d]])
                res += solve(i + dy[d], j + dx[d], idx + 1);
    vis[i][j] = false;
 
    return res;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
   
    string s;
    cin >> s;
    for (int i = 0; i < 48; i++)
    {
        if (s[i] == '?') p[i] = -1;
        if (s[i] == 'R') p[i] = 0;
        if (s[i] == 'D') p[i] = 1;
        if (s[i] == 'L') p[i] = 2;
        if (s[i] == 'U') p[i] = 3;
    }
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            vis[i][j] = (i == 0 || i == 8 || j == 0 || j == 8);
 
    cout << solve(1,1,0) << '\n';
    
    return 0;
}
