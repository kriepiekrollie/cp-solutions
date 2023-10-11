#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, D;

struct Star
{
    int x, y, idx;
};
bool operator<(const Star &A, const Star &B)
{
    return make_pair(A.y, A.x) < make_pair(B.y, B.x);
}

Star p[100000];
vector<int> g[100000];

int e[100000];
int find(int u)
{
    return e[u] < 0 ? u : e[u] = find(e[u]);
}
void unite(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v) return;
    if (e[u] > e[v]) swap(u, v);
    e[u] += e[v], e[v] = u;
}

const int MX = 2000000;
int t[4*MX+4];
void build(int v = 1, int tl = 0, int tr = MX)
{
    if (tl == tr)
    {
        t[v] = INT_MAX;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}
void update(int idx, int val, int v = 1, int tl = 0, int tr = MX)
{
    if (tl == tr)
    {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (idx <= tm)
        update(idx, val, 2 * v, tl, tm);
    else
        update(idx, val, 2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}
int query(int l, int r, int v = 1, int tl = 0, int tr = MX)
{
    if (r < l || r < tl || tr < l)
        return INT_MAX;
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(query(l, r, 2 * v, tl, tm), query(l, r, 2 * v + 1, tm + 1, tr));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> D;
    for (int i = 0, X, Y; i < n; i++)
    {
        cin >> X >> Y;
        p[i] = {X + Y, X - Y + 1000000, i};
    }
    for (int t = 0; t < 4; t++)
    {
        sort(p, p + n, [] (const Star &A, const Star &B) {return A.x < B.x;});

        build();
        vector<set<int>> Range(MX + 1);
        for (int i = 0, l = 0, r = 0; i < n; i++)
        {
            while (r < n && p[r].x <= p[i].x + D)
            {
                Range[p[r].y].insert(p[r].idx);
                update(p[r].y, *Range[p[r].y].begin());
                r++;
            }
            while (l < n && p[l].x < p[i].x)
            {
                Range[p[l].y].erase(p[l].idx);
                update(p[l].y, Range[p[l].y].size() ? *Range[p[l].y].begin() : INT_MAX);
                l++;
            }
            int j = query(p[i].y, p[i].y + D); 
            if (j < p[i].idx)
                g[p[i].idx].push_back(j);
        }

        for (int i = 0; i < n; i++)
        {
            int x = p[i].y, y = 2000000 - p[i].x;
            p[i].x = x, p[i].y = y;
        }
    }

    for (int i = 0; i < n; i++)
        e[i] = -1;

    for (int u = 0; u < n; u++)
    {
        for (int v : g[u])
            unite(u, v);
        cout << -e[find(u)] << '\n';
    }

    return 0;
}
