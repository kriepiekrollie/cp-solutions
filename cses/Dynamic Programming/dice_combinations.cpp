#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

struct Matrix
{
    ll m[6][6];
};

Matrix operator*(const Matrix &A, const Matrix &B)
{
    Matrix result;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
        {
            result.m[i][j] = 0;
            for (int k = 0; k < 6; k++)
                result.m[i][j] = (result.m[i][j] + A.m[i][k] * B.m[k][j]) % MOD;
        }
    return result;
}

Matrix res = {{
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
}};

Matrix P = {{
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1},
}};

ll n;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    while (n)
    {
        if (n & 1)
            res = P * res;
        P = P * P;
        n >>= 1;
    }
    cout << res.m[5][5] << '\n';

    return 0;
}
