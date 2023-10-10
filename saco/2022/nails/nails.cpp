#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = 300000;

int n;
pair<int,int> banner[MaxN];
bool nailed[MaxN];
set<int> nails;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> banner[i].first >> banner[i].second;
    sort(banner, banner + n);

    int k = 0;
    for (int i = n - 1; i >= 0; i--)
        if (!nailed[i])
        {
            nails.insert(banner[i].first);
            k++;
            for (int j = i; j >= 0 && banner[j].second >= banner[i].first; j--)
                nailed[j] = true;
        }

    cout << k << '\n';
    for (int nail : nails)
        cout << nail << ' ';
    cout << '\n';

    return 0;
}
