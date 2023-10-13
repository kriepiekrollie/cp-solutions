#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
using namespace std;
typedef long long ll;

struct Project
{
    int start, stop, reward;
};

bool operator<(const Project &A, const Project &B)
{
    return A.stop < B.stop;
}

const int MaxN = 200001;
int n;
Project p[MaxN];
ll dp[MaxN];
ll mx[MaxN];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    p[0] = {0, 0, 0};
    for (int i = 1; i <= n; i++)
        cin >> p[i].start >> p[i].stop >> p[i].reward;

    sort(p, p + n + 1);

    dp[0] = mx[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int lo = 0, hi = i, mid;
        while (lo < hi)
        {
            mid = (lo + hi + 1) / 2;
            if (p[mid].stop < p[i].start)
                lo = mid;
            else
                hi = mid - 1;
        }
        dp[i] = mx[lo] + p[i].reward;
        mx[i] = max(mx[i-1], dp[i]);
    }

    cout << mx[n] << '\n';

    return 0;
}
