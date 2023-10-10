#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = 1000000;

int n;
int h[MaxN + 2];
int l[MaxN + 2];
int r[MaxN + 2];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    h[0] = h[n+1] = INT_MAX;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (h[s.top()] < h[i])
            s.pop();
        l[i] = i - s.top() - 1;
        s.push(i);
    }

    s = stack<int>();
    s.push(n+1);
    for (int i = n; i >= 1; i--)
    {
        while (h[s.top()] < h[i])
            s.pop();
        r[i] = s.top() - i - 1;
        s.push(i);
    }

    for (int i = 1; i <= n; i++)
        if (l[i] + r[i] == n - 1)
            cout << "infinite\n";
        else if (l[i] == i - 1 || r[i] == n - i)
            cout << "semi infinite\n";
        else
            cout << l[i] + r[i] << '\n';

    return 0;
}
