#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char, int> mp = {{'A', 0}, {'C', 1}, {'T', 2}, {'G', 3}};

struct TrieNode
{
    bool is_end;
    TrieNode *children[4];
    TrieNode()
    {
        is_end = false;
        for (int i = 0; i < 4; i++)
            children[i] = nullptr;
    }
};

void insert(TrieNode *root, const string &s)
{
    TrieNode *p = root;
    for (char c : s)
    {
        int idx = mp[c];
        if (p->children[idx] == nullptr)
            p->children[idx] = new TrieNode();
        p = p->children[idx];
    }
    p->is_end = true;
}

int n, m;
string s;
int dp[5001];

int main()
{
    cin >> n >> m >> s;

    TrieNode *root = new TrieNode();
    while (m--)
    {
        int k;
        string t;
        cin >> k >> t;
        reverse(t.begin(), t.end());
        insert(root, t);
    }

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;

        TrieNode *p = root;
        for (int j = i - 1; j >= 0; j--)
        {
            p = p->children[mp[s[j]]];
            if (p == nullptr) break;

            if (p->is_end && dp[j] != INT_MAX)
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    if (dp[s.size()] == INT_MAX)
        cout << "-1\n";
    else
        cout << dp[s.size()] << '\n';

    return 0;
}
