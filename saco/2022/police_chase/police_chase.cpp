#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = 1000000;

int n;
vector<int> g[MaxN];

int dp(int u, int p = -1)
{
    vector<int> mx(3, -1);
    for (int v : g[u])
        if (v != p)
        {
            mx[2] = dp(v, u);
            for (int i = 0; i < 2; i++)
                if (mx[2] > mx[i])
                    swap(mx[2], mx[i]);
        }
    if (mx[0] == -1)
        return 1;
    return max(mx[0], mx[1] + 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << dp(0) << '\n';

    return 0;
}
