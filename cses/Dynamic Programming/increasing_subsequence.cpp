#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x; 
vector<int> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int lo = 0, hi = dp.size(), mid;
        while (lo < hi)
        {
            mid = (lo + hi) / 2;
            if (dp[mid] < x)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (lo == dp.size())
            dp.push_back(x);
        else
            dp[lo] = x;
    }

    cout << dp.size() << '\n';

    return 0;
}
