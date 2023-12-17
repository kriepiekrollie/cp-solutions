#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
 
#define x first
#define y second

int n;
pt pts[200000];

pt stck[200000];
int top = -1;

int ans = 0;
pt convex_hull[200000];
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; 
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pts[i].x >> pts[i].y;
    sort(pts, pts + n);

    stck[++top] = pts[0];
    stck[++top] = pts[1];
    for (int i = 2; i < n; i++)
    {
        while (top >= 1)
        {
            if ((stck[top].y - stck[top-1].y)*(pts[i].x - stck[top-1].x) < (pts[i].y - stck[top-1].y)*(stck[top].x - stck[top-1].x))
                top--;
            else break;
        }
        stck[++top] = pts[i];
    }
    for (int i = 0; i <= top; i++)
        convex_hull[ans++] = stck[i];

    top = -1;
    stck[++top] = pts[0];
    stck[++top] = pts[1];
    for (int i = 2; i < n; i++)
    {
        while (top >= 1)
        {
            if ((stck[top].y - stck[top-1].y)*(pts[i].x - stck[top-1].x) > (pts[i].y - stck[top-1].y)*(stck[top].x - stck[top-1].x))
                top--;
            else break;
        }
        stck[++top] = pts[i];
    }
    for (int i = 1; i < top; i++)
        convex_hull[ans++] = stck[i];
 
    cout << ans << '\n';
    for (int i = 0; i < ans; i++)
        cout << convex_hull[i].x << ' ' << convex_hull[i].y << '\n';
 
    return 0;
}
