#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Event
{
    int x, y, idx, type;
};

bool operator<(const Event &a, const Event &b)
{
    return make_pair(a.x, a.type) < make_pair(b.x, b.type);
}

int n, q, h;

int e[100001];
int find(int u)
{
    return e[u] < 0 ? u : e[u] = find(e[u]);
}
void unite(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    if (e[u] > e[v])
        swap(u, v);
    e[u] += e[v], e[v] = u;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q >> h;
    
    vector<Event> events;
    for (int i = 1, x, y, l; i <= n; i++)
    {
        cin >> x >> y >> l;
        events.push_back({x, y, i, +1});
        events.push_back({x + l, y, i, -1});
        e[i] = -1;
    }

    sort(events.begin(), events.end());

    set<pair<int, int>> cur;
    for (auto [x, y, idx, type] : events)
    {
        if (type == -1)
        {
            cur.erase({y, idx});
            continue;
        }

        auto it = cur.insert({y, idx}).first;

        if (it != cur.begin() && y - prev(it)->first <= h)
            unite(idx, prev(it)->second);

        if (next(it) != cur.end() && next(it)->first - y <= h)
            unite(idx, next(it)->second);
    }

    int a, b;
    while (q--)
    {
        cin >> a >> b;
        cout << (find(a) == find(b) ? "YES\n" : "NO\n");
    }

    return 0;
}
