#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll p[20];
ll sum = 0;
 
ll min_split(int i = 0, ll x = 0)
{
    if (i == n) return abs(sum - 2 * x);
    return min(min_split(i + 1, x), min_split(i + 1, x + p[i]));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        sum += p[i];
    }
 
    cout << min_split() << '\n';

    return 0;
}
