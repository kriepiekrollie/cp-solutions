#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 100000;
int n, x[MAX], y[MAX]; 

set<pair<int, int>> ld, rd; 

int num_boxes = 0;
struct box {
    int left, right, top, bottom;
} boxes[MAX];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int max_x = 0, max_y = 0;
    cin >> n;
    set<pair<pair<int, int>, int>> pts_x, pts_y;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        pts_x.insert({{x[i], y[i]}, i});
        pts_y.insert({{y[i], x[i]}, i});
        max_x = max(max_x, x[i]);
        max_y = max(max_y, y[i]);
    }

    while (pts_x.size() && pts_y.size()) {
        auto left = pts_x.begin()->second;
        auto right = pts_x.rbegin()->second;
        auto top = pts_y.rbegin()->second;
        auto bottom = pts_y.begin()->second;

        bool flag = false;
        if (left == top) {
            ld.insert({x[left], left});
            pts_x.erase({{x[left], y[left]}, left});
            pts_y.erase({{y[left], x[left]}, left});
        } else if (right == top) {
            rd.insert({x[right], right});
            pts_x.erase({{x[right], y[right]}, right});
            pts_y.erase({{y[right], x[right]}, right});
        } else if (left == bottom) {
            rd.insert({x[left], left});
            pts_x.erase({{x[left], y[left]}, left});
            pts_y.erase({{y[left], x[left]}, left});
        } else if (right == bottom) {
            ld.insert({x[right], right});
            pts_x.erase({{x[right], y[right]}, right});
            pts_y.erase({{y[right], x[right]}, right});
        } else {
            boxes[num_boxes++] = {left, right, top, bottom};
            pts_x.erase({{x[left], y[left]}, left});
            pts_y.erase({{y[left], x[left]}, left});
            pts_x.erase({{x[right], y[right]}, right});
            pts_y.erase({{y[right], x[right]}, right});
            pts_x.erase({{x[top], y[top]}, top});
            pts_y.erase({{y[top], x[top]}, top});
            pts_x.erase({{x[bottom], y[bottom]}, bottom});
            pts_y.erase({{y[bottom], x[bottom]}, bottom});
        }
    }
    int cur_x = 0, cur_y = 0;
    vector<pair<int, int>> res;
    for (int i = num_boxes - 1; i >= 0; i--) {
        auto [l, r, t, b] = boxes[i];
        cur_y = y[b];
        res.push_back({cur_x, cur_y});
        if (cur_x < x[b]) {
            cur_x = x[r];
            res.push_back({cur_x, cur_y});
            cur_y = y[t];
            res.push_back({cur_x, cur_y});
            cur_x = x[l];
            res.push_back({cur_x, cur_y});
        } else {
            cur_x = x[l];
            res.push_back({cur_x, cur_y});
            cur_y = y[t];
            res.push_back({cur_x, cur_y});
            cur_x = x[r];
            res.push_back({cur_x, cur_y});
        }
    }
    cur_y = 0;
    res.push_back({cur_x, cur_y});

    bool parity = 1;
    for (auto [_, i] : rd) {
        if (parity) {
            cur_x = x[i];
            res.push_back({cur_x, cur_y});
            cur_y = y[i];
        } else {
            cur_y = y[i];
            res.push_back({cur_x, cur_y});
            cur_x = x[i];
        }
        parity ^= 1;
    }

    vector<pair<int, int>> ldv(ld.begin(), ld.end());

    if (parity) {
        cur_x = min(max_x + 100, 1000000000);
        reverse(ldv.begin(), ldv.end());
    } else {
        cur_y = min(max_y + 100, 1000000000);
    }
    res.push_back({cur_x, cur_y});
    parity ^= 1;

    for (auto [_, i] : ldv) {
        if (parity) {
            cur_x = x[i];
            res.push_back({cur_x, cur_y});
            cur_y = y[i];
        } else {
            cur_y = y[i];
            res.push_back({cur_x, cur_y});
            cur_x = x[i];
        }
        parity ^= 1;
    }
    res.push_back({cur_x, cur_y});
        
    cout << res.size() << '\n';
    for (auto [x, y] : res)
        cout << x << ' ' << y << '\n';

    return 0;
}
