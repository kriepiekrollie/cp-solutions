#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[1000000], b[1000000];
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j + 1 < m && b[j + 1] <= a[i])
            j++;
        if (j + 1 < m)
            ans = max(ans, min(abs(a[i] - b[j]), abs(b[j + 1] - a[i])));
        else
            ans = max(ans, abs(a[i] - b[j]));
    }
    cout << ans << '\n';

    return 0;
}
