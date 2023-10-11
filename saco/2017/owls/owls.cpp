#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}

ll binpow(ll x, ll n)
{
    ll res = 1;
    for (; n; n >>= 1, x = x * x % MOD)
        if (n & 1) res = res * x % MOD;
    return res;
}
ll fac[1001], inv[1001];
ll choose(int N, int K)
{
    if (K < 0 || N < K) return 0;
    return (fac[N] * inv[K] % MOD) * inv[N-K] % MOD;
}

struct Line
{
    // Ax + By + C = 0;
    ll A, B, C;
    Line(ll x1, ll y1, ll x2, ll y2)
    {
        A = y1 - y2;
        B = x2 - x1;
        C = x1 * y2 - y1 * x2;
        if (C < 0 || (C == 0 && A > B))
            A *= -1, B *= -1, C *= -1;
        ll g = gcd(A, gcd(B, C));
        A /= g, B /= g, C /= g;
    }
};
bool operator<(const Line &P, const Line &Q)
{
    return make_pair(P.A, make_pair(P.B, P.C)) < make_pair(Q.A, make_pair(Q.B, Q.C));
}

int n, k;
ll x[1000], y[1000];
ll cnt[1000] = {0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    fac[0] = 1;
    for (int i = 1; i <= 1000; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[1000] = binpow(fac[1000], MOD - 2);
    for (int i = 1000; i >= 1; i--)
        inv[i - 1] = inv[i] * i % MOD;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    map<Line, set<int>> pts;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            Line L(x[i], y[i], x[j], y[j]);
            if (pts.find(L) == pts.end())
                pts[L] = set<int>();
            pts[L].insert(i);
            pts[L].insert(j);
        }

    ll bad = 0;

    if (k == 3)
    {
        for (auto [L, s] : pts)
            bad = (bad + choose(s.size(), 3)) % MOD;
    }

    if (k == 4)
    {
        for (auto [L, s] : pts)
        {
            bad = (bad + choose(s.size(), 3) * choose(n - s.size(), 1)) % MOD;
            bad = (bad + choose(s.size(), 4)) % MOD;
        }
    }

    if (k == 5)
    {
        for (auto [L, s] : pts)
        {
            bad = (bad + choose(s.size(), 3) * choose(n - s.size(), 2)) % MOD;
            bad = (bad + choose(s.size(), 4) * choose(n - s.size(), 1)) % MOD;
            bad = (bad + choose(s.size(), 5)) % MOD;
        }
        for (auto [L, s] : pts)
        {
            ll x = choose(s.size() - 1, 2);
            for (int i : s)
            {
                bad = (bad - x * cnt[i]) % MOD;
                cnt[i] = (cnt[i] + x) % MOD;
            }
        }
    }

    cout << (choose(n, k) - bad + MOD) % MOD << '\n';
    return 0;
}
