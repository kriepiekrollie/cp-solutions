#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int MaxN = 100001;

int N, L;
pair<int, int> ledge[MaxN];
ll dp[MaxN] = {0};
ll t[2 * MaxN] = {0};

ll sum(int l, int r)
{
    ll res = 0;
    for (l += MaxN, r += MaxN + 1; l < r; l /= 2, r /= 2)
    {
        if (l & 1) res += t[l++];
        if (r & 1) res += t[--r];
        res %= mod;
    }
    return res;
}

void update(int i, ll val)
{
    t[i += MaxN] += val;
    for (i /= 2; i > 0; i /= 2)
        t[i] = (t[2 * i] + t[2 * i + 1]) % mod;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> L;
    for (int i = 0; i < N; i++)
        cin >> ledge[i].second >> ledge[i].first;

    sort(ledge, ledge + N);

    for (int i = 0; i < N; i++)
    {
        dp[i] = (1 + sum(max(0, ledge[i].second - L), min(MaxN - 1, ledge[i].second + L))) % mod;
        update(ledge[i].second, dp[i]);
    }
    cout << dp[N-1] << '\n';

    return 0;
}
