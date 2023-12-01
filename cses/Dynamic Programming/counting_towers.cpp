#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

struct Matrix
{
    ll a, b, c, d;
};

const Matrix id = {1, 0, 0, 1};
const Matrix P = {4, 1, 1, 2};

inline Matrix operator*(const Matrix &X, const Matrix &Y)
{
    return {
        (X.a * Y.a + X.b * Y.c) % MOD,
        (X.a * Y.b + X.b * Y.d) % MOD,
        (X.c * Y.a + X.d * Y.c) % MOD,
        (X.c * Y.b + X.d * Y.d) % MOD,
    };
}

int n, t;
Matrix ans, p;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        n--;
        ans = id;
        p = P;
        while (n)
        {
            if (n & 1)
                ans = ans * p;
            p = p * p;
            n >>= 1;
        }
        cout << (ans.a + ans.b + ans.c + ans.d) % MOD << '\n';
    }

    return 0;
}
