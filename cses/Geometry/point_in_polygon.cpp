#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n, m;
ll X, Y;
ll x[1001], y[1001];
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    x[n] = x[0], y[n] = y[0];
    
    while (m--)
    {
        cin >> X >> Y;
 
        bool on_boundary = false;
        int intersect_cnt = 0;
 
        for (int i = 0; i < n; i++)
        {
            if ((Y-y[i])*(x[i+1]-x[i]) == (y[i+1]-y[i])*(X-x[i]) && 
                min(y[i],y[i+1]) <= Y && Y <= max(y[i],y[i+1]) &&
                min(x[i],x[i+1]) <= X && X <= max(x[i],x[i+1]))
            {
                on_boundary = true;
                break;
            }
 
            if (max(x[i],x[i+1]) < X) continue;
 
            if (min(y[i], y[i+1]) <= Y && Y < max(y[i], y[i+1]))
            {
                ll rhs = (Y - y[i]) * (x[i+1] - x[i]);
                ll den = (y[i+1] - y[i]);
                if (den >= 0 && (X - x[i]) * den <= rhs) 
                    intersect_cnt++;
                else if (den <= 0 && (X - x[i]) * den >= rhs)
                    intersect_cnt++;
            }
        }
 
        if (on_boundary)
            cout << "BOUNDARY\n";
        else if (intersect_cnt % 2 == 0)
            cout << "OUTSIDE\n";
        else
            cout << "INSIDE\n";
    }
 
    return 0;
}
