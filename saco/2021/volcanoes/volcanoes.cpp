#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;

int n;
int segH[500000];
int segR[500000];

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        segH[v] = 500;
        segR[v] = 500;
        return;
    }

    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    segH[v] = max(segH[v*2], segH[v*2+1]);
    segR[v] = segR[v*2] + segR[v*2+1];
}

void update_height(int v, int tl, int tr, int idx, int val)
{
    if (tl == tr)
    {
        segH[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (idx <= tm)
        update_height(v*2, tl, tm, idx, val);
    else
        update_height(v*2+1, tm+1, tr, idx, val);
    segH[v] = max(segH[v*2], segH[v*2+1]);
}

void update_dist(int v, int tl, int tr, int idx, int val)
{
    if (tl == tr)
    {
        segR[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (idx <= tm)
        update_dist(v*2, tl, tm, idx, val);
    else
        update_dist(v*2+1, tm+1, tr, idx, val);
    segR[v] = segR[v*2] + segR[v*2+1];
}

int max_height(int v, int tl, int tr, int l, int r)
{
    if (r < l || r < tl || tr < l)
        return 0;
    if (l <= tl && tr <= r)
        return segH[v];
    int tm = (tl + tr) / 2;
    return max(max_height(v*2, tl, tm, l, r), max_height(v*2+1, tm+1, tr, l, r));
}

int sum_dist(int v, int tl, int tr, int l, int r)
{
    if (r < l || r < tl || tr < l)
        return 0;
    if (l <= tl && tr <= r)
        return segR[v];
    int tm = (tl + tr) / 2;
    return sum_dist(v*2, tl, tm, l, r) + sum_dist(v*2+1, tm+1, tr, l, r);
}

int query_pos(int v, int tl, int tr, int idx)
{
    if (tl == tr)
        return segR[v];
    int tm = (tl + tr) / 2;
    if (idx <= tm)
        return query_pos(2 * v, tl, tm, idx);
    return segR[2 * v] + query_pos(2 * v + 1, tm + 1, tr, idx);
}

int query_first_ge(int v, int tl, int tr, int val)
{
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (segR[2 * v] < val)
        return query_first_ge(2 * v + 1, tm + 1, tr, val - segR[2 * v]);
    return query_first_ge(2 * v, tl, tm, val);
}

int query_first_g(int v, int tl, int tr, int val)
{
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (segR[2 * v] <= val)
        return query_first_g(2 * v + 1, tm + 1, tr, val - segR[2 * v]);
    return query_first_g(2 * v, tl, tm, val);
}

int query(int i, int K)
{
    // we want to find minimal l, maximal r such that 
    // pos[r] - pos[idx] <= K
    // pos[idx] - pos[l] <= K
    // which is the same as
    // pos[r] <= pos[idx] + K
    // pos[l] >= pos[idx] + K
    
    int x = query_pos(1, 0, n - 1, i); // Find the current x-coordinate of mountain i.
    int r = segR[1] <= x + K ? n - 1 : query_first_g(1, 0, n - 1, x + K) - 1; // Find the last mountain with x-coordinate <= pos + K.
    int l = query_first_ge(1, 0, n - 1, x - K); // Find the first mountain with x-coordinate >= pos - K.

    return max(max_height(1, 0, n - 1, i + 1, r), max_height(1, 0, n - 1, l, i - 1));
}

struct event
{
    int y, idx, v;
    char t;
};

bool operator<(const event &X, const event &Y)
{
    return X.y < Y.y;
}

event e[500000];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int a, b;
    cin >> n >> a >> b;
    build(1, 0, n-1);
    for (int i = 0; i < a; i++)
        cin >> e[i].y >> e[i].idx >> e[i].t >> e[i].v;
    for (int i = a; i < a + b; i++)
    {
        cin >> e[i].y >> e[i].idx >> e[i].v;
        e[i].t = 'A';
    }
    sort(e, e + a + b);
    for (int i = 0; i < a + b; i++)
        if (e[i].t == 'H')
            update_height(1, 0, n-1, e[i].idx, e[i].v);
        else if (e[i].t == 'D')
            update_dist(1, 0, n-1, e[i].idx, e[i].v);
        else
            cout << query(e[i].idx, e[i].v) << '\n';

    return 0;
}
