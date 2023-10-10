#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int S = 400;
int n, m;
int pos[100001], a[100001], z[100000];
bool _scan[800001];
bool *scan = &_scan[600000]; // suspicious pointer business to allow negative indices.

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> z[i];
        scan[z[i]] = true;
    }

    deque<int> dq;
    int i = m - 1;
    for (int t = 0; t < n - z[0] + 1; t++)
    {
        // maintain the blocks currently being scanned.
        while (i >= 0 && z[i] + t > 0)
            dq.push_back(z[i--]);
        while (dq.size() > 0 && dq.front() + t > n)
            dq.pop_front();

        if (dq.size() <= S)
        {
            int mn = INT_MAX, p = -1;
            for (int j : dq)
                if (a[j + t] < mn)
                    mn = a[j + t], p = j + t;
            cout << p << ' ';
        }
        else
        {
            for (int i = 1; i <= n; i++)
                if (pos[i] - t >= -600000 && scan[pos[i] - t])
                {
                    cout << pos[i] << ' ';
                    break;
                }
        }
    }
    cout << '\n';
    return 0;
}
