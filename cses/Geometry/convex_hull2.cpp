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

inline ll dist2(const pt &A, const pt &B)
{
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

inline pt dir(const pt &A, const pt &B)
{
    return {B.x - A.x, B.y - A.y};
}

inline ll dot(const pt &A, const pt &B)
{
    return A.x * B.y - A.y * B.x;
}

inline ll area(const pt &A, const pt &B, const pt &C)
{
    return dot(dir(A, B), dir(A, C));
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].x >> pts[i].y;
        if (pts[i].x < pts[0].x || (pts[i].x == pts[0].x && pts[i].y < pts[0].y))
            swap(pts[0], pts[i]);
    }

    sort(pts + 1, pts + n, [] (const pair<ll, ll> &A, const pair<ll, ll> &B) 
    {
        if ((A.y - pts[0].y) * (B.x - pts[0].x) == (B.y - pts[0].y) * (A.x - pts[0].x))
            return dist2(A, pts[0]) < dist2(B, pts[0]);
        return (A.y - pts[0].y) * (B.x - pts[0].x) > (B.y - pts[0].y) * (A.x - pts[0].x);
    });

    stck[++top] = pts[0];
    stck[++top] = pts[1];
    for (int i = 2; i < n; i++)
    {
        while (top >= 1 && area(stck[top-1], stck[top], pts[i]) > 0)
            top--;
        stck[++top] = pts[i];
    }

    for (int i = n - 2; i >= 0; i--)
        if ((pts[i].y - pts[0].y) * (stck[top].x - pts[0].x) == (stck[top].y - pts[0].y) * (pts[i].x - pts[0].x))
            stck[++top] = pts[i];
        else break;

    cout << top + 1 << '\n';
    for (int i = 0; i <= top; i++)
        cout << stck[i].x << ' ' << stck[i].y << '\n';
 
    return 0;
}
