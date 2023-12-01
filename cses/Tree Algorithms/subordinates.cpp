#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 200000;

int n, sz[MAX_N + 1];
vector<int> children[MAX_N + 1];
int calc(int u)
{
    sz[u] = 1;
    for (int v : children[u])
        sz[u] += calc(v);
    return sz[u];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 2, p; i <= n; i++)
    {
        cin >> p;
        children[p].push_back(i);
    }

    calc(1);
    for (int i = 1; i <= n; i++)
        cout << sz[i] - 1 << ' ';
    cout << '\n';

    return 0;
}
