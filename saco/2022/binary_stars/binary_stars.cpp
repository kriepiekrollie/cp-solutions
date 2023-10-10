#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;

#define max_bit 29 

struct node
{
    node *children[2];
    bool is_end;
    int cnt;
    node()
    {
        cnt = 0;
        is_end = false;
        for (int i = 0; i < 2; i++)
            children[i] = nullptr;
    }
    void process()
    {
        cnt = is_end;
        for (int i = 0; i < 2; i++)
            if (children[i])
            {
                children[i]->process();
                cnt += children[i]->cnt;
            }
    }
};

void insert(node *root, uint x)
{
    node *p = root;
    for (int k = 0, idx; k <= max_bit; k++)
    {
        idx = x & 1;
        if (p->children[idx] == nullptr)
            p->children[idx] = new node();

        p = p->children[idx];
        x >>= 1;
    }
    p->is_end = true;
}

int search(node *root, uint x, uint r)
{
    node *p = root;
    int res = 0;
    for (node *p = root; p != nullptr && p->cnt != 0; x >>= 1, r >>= 1)
    {
        if (p->is_end)
            return res + 1;

        if ((r & 1) > 0 && p->children[x & 1] != nullptr)
            res += p->children[x & 1]->cnt;

        p = p->children[(x ^ r) & 1];
    }
    return res;
}

uint reverse_bits(uint x)
{
    uint res = 0;
    for (int k = 0; k <= max_bit; k++)
        res |= ((x >> k) & 1) << (max_bit - k);
    return res;
}

const int MaxN = 100000;

uint n;
uint R, s[MaxN], x[MaxN];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    node *root = new node();

    cin >> n >> R;
    R = reverse_bits(R);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(s, s + n); 
    for (int i = 0; i < n; i++)
    {
        x[i] = reverse_bits(s[i]);
        insert(root, x[i]);
    }

    root->process();

    int best = -1;
    uint ans = 0;
    for (int i = 0, res; i < n; i++)
    {
        res = search(root, x[i], R);
        if (res > best)
            ans = s[i], best = res;
    }
    cout << ans << '\n';

    return 0;
}
