#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int par[100001] = {0};

set<int> g[100001];
int sz[100001];
int dfs_sizes(int u, int p = -1)
{
    sz[u] = 1;
    for (int v : g[u])
        if (v != p)
            sz[u] += dfs_sizes(v, u);
    return sz[u];
}
int find_centroid(int u, int p = -1)
{
    for (int v : g[u])
        if (v != p && sz[v] > n / 2)
            return find_centroid(v, u);
    return u;
}

vector<int> find_centroids()
{
    dfs_sizes(1);
    int c = find_centroid(1);
    vector<int> centroids = {c};
    for (int v : g[c])
        if (2 * sz[v] == n)
            centroids.push_back(v);
    return centroids;
}

string rbs(int u, int p = -1)
{
    vector<string> sub;
    for (int v : g[u])
        if (v != p)
            sub.push_back(rbs(v, u));
    sort(sub.begin(), sub.end());

    string res = "(";
    for (string s : sub)
        res += s;
    res += ")";

    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    set<string> result;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        n = 1;
        int u = 1;
        for (char c : s)
            if (c == '0')
            {
                par[++n] = u;
                u = n;
            }
            else
                u = par[u];

        for (int i = 1; i <= n; i++)
            g[i] = set<int>();
        for (int i = 2; i <= n; i++)
        {
            g[par[i]].insert(i);
            g[i].insert(par[i]);
        }

        vector<int> centroids = find_centroids();
        if (centroids.size() == 2)
        {
            int u = centroids[0], v = centroids[1];
            g[u].erase(v);
            g[v].erase(u);
            n++;
            g[n].insert(u);
            g[n].insert(v);
            centroids = {n};
        }

        int c = centroids[0];

        result.insert(rbs(c));
    }
    cout << result.size() << '\n';

    return 0;
}
