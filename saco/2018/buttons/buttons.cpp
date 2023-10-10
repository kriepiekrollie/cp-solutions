#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll A, N, M;
    cin >> A >> N >> M;

    ll cnt = 0;
    while (N < M)
    {
        // increase to next multiple of A.
        ll inc = A - (M % A);
        if (inc == A) inc = 0;

        cnt += inc;
        M += inc;

        // divide by A.
        cnt++;
        M /= A;
    }
    cout << cnt + (N - M) << '\n';

    return 0;
}
