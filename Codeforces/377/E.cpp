// I love coding...
// ...acm without girlfriend
#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
int n, m;
pair<int, int> so[maxn];
int a[maxn], b[maxn];
struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return a.first < b.first;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    // cin.tie(0);

    cin >> n >> m;
    multiset<pair<int, int>, cmp> co;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        co.insert({x, i});
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        so[i] = {x, i};
    }
    sort(so + 1, so + 1 + m);
    int u = 0;
    for (int i = 1; i <= m; i++) {
        for (int cntAdapter = 0, x = so[i].first;; cntAdapter++, x = (x + 1) / 2) {
            auto it = co.find({x, -1});
            if (it != co.end()) {
                a[so[i].second] = cntAdapter;
                u += cntAdapter;
                b[it->second] = so[i].second;
                co.erase(it);
                break;
            }
            if (x == 1) break;
        }
    }
    cout << n - co.size() << " " << u << endl;
    for (int i = 1; i <= m; i++) cout << a[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
    return 0;
}
