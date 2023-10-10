#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, h[200002] = {0};
int L[200002], R[200002];

pair<int,int> join(pair<int,int> A, pair<int,int> B)
{
    return make_pair(A.second - A.first, make_pair(A.second, A.first)) > make_pair(B.second - B.first, make_pair(B.second, B.first)) ? A : B;
}

struct Node
{
    pair<int, int> val;
    Node *l, *r;
    Node() : l(nullptr), r(nullptr), val(make_pair(0, -1)) {}
    Node(pair<int, int> val) : l(nullptr), r(nullptr), val(val) {}
    Node(Node *l, Node *r) : l(l), r(r), val(make_pair(0, -1))
    {
        if (l) val = join(val, l->val);
        if (r) val = join(val, r->val);
    }
};

Node *update(Node *x, int tl, int tr, int idx, pair<int, int> val)
{
    if (idx < tl || tr < idx)
        return x;

    if (tl == tr)
    {
        if (x == nullptr || join(val, x->val) != x->val)
            return new Node(val);
        return x;
    }
    int tm = (tl + tr) / 2;
    if (x == nullptr)
        return new Node(update(nullptr, tl, tm, idx, val), update(nullptr, tm + 1, tr, idx, val));
    return new Node(update(x->l, tl, tm, idx, val), update(x->r, tm + 1, tr, idx, val));
}

pair<int, int> query(Node *x, int tl, int tr, int l, int r)
{
    if (x == nullptr || r < tl || tr < l)
        return {0, -1};
    if (l <= tl && tr <= r)
        return x->val;
    int tm = (tl + tr) / 2;
    return join(query(x->l, tl, tm, l, r), query(x->r, tm + 1, tr, l, r));
}

Node *seg[200002] = {nullptr};

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int q, b;
    cin >> n >> q >> b;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    vector<int> idx;
    idx.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (h[idx.back()] >= h[i])
            idx.pop_back();
        L[i] = idx.back() + 1;
        idx.push_back(i);
    }

    idx = vector<int>();
    idx.push_back(n+1);
    for (int i = n; i >= 1; i--)
    {
        while (h[idx.back()] >= h[i])
            idx.pop_back();
        R[i] = idx.back() - 1;
        idx.push_back(i);
    }

    vector<pair<int, int>> ranges(n);
    for (int i = 1; i <= n; i++)
        ranges[i-1] = {L[i], R[i]};
    sort(ranges.begin(), ranges.end(), [] (const pair<int,int> &A, const pair<int,int> &B) {return A.second < B.second;});

    seg[0] = new Node();
    for (int r = 1, i = 0; r <= n; r++)
    {
        seg[r] = seg[r-1];
        while (i < n && ranges[i].second < r)
            i++;
        while (i < n && ranges[i].second == r)
        {
            seg[r] = update(seg[r], 1, n, ranges[i].first, ranges[i]);
            i++;
        }
    }

    int l, r, x, y, z = 0;
    pair<int, int> ans;
    while (q--)
    {
        cin >> x >> y;
        l = (x - 1 + b * abs(z)) % n + 1;
        r = (y - 1 + b * abs(z)) % n + 1;
        ans = query(seg[r], 1, n, l, n);
        if (ans.second < ans.first)
        {
            cout << "-1\n";
            z = -1;
        }
        else
        {
            cout << ans.first << ' ' << ans.second << '\n';
            z = ans.first;
        }
    }

    return 0;
}
