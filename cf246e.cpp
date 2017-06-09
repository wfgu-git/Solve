#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int skip[maxn], sz[maxn], dep[maxn], ans[maxn];
string name[maxn];
map<string, int > cnt[maxn];
vector<vector<int> > g;
vector<int> rt;
vector<pair<int, int> > qry[maxn];
int n, m;
void add(int u, int p, bool t) {
    // cnt[u].insert(name[u]);
    if (t) {
        cnt[dep[u]][name[u]]++;
    } else {
        cnt[dep[u]][name[u]]--;
        if (cnt[dep[u]][name[u]] == 0)
            cnt[dep[u]].erase(name[u]);
    }
    for (auto v : g[u]) {
        if (v == p || skip[v]) continue;
        add(v, u, t);
    }
}
void getinfo(int u, int d) {
    sz[u] = 1;
    dep[u] = d;
    for (auto v : g[u]) {
        getinfo(v, d + 1);
        sz[u] += sz[v];
    }
}
void dfs(int u, int p, bool keep) {
    int Max = -1, bigChild = -1;
    for (auto v : g[u]) {
        if (v == p) continue;
        if (Max < sz[v]) {
            Max = sz[v];
            bigChild = v;
        }
    }
    for (auto v : g[u]) {
        if (v != p && v != bigChild)
            dfs(v, u, 0);
    }
    if (bigChild != -1) dfs(bigChild, u, 1), skip[bigChild] = 1;
    add(u, p, 1);
    for (auto q : qry[u]) {
        ans[q.second] = cnt[q.first + dep[u]].size();
    }
    if (bigChild != -1) skip[bigChild] = 0;
    if (keep == false) add(u, p, 0);
}
void init() {
    g.resize(n + 2);
    g.clear();
    memset(sz, 0, sizeof(sz));
    memset(dep, 0, sizeof(dep));
    memset(skip, 0, sizeof(skip));
    memset(ans, 0, sizeof(ans));
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    init();
    for (int i = 1, fa; i <= n; i++) {
        cin >> name[i] >> fa;
        if (fa == 0)
            rt.push_back(i);
        else
            g[fa].push_back(i);
    }

    cin >> m;
    for (int i = 1, v, h; i <= m; i++) {
        cin >> v >> h;
        qry[v].push_back({h, i});
    }
    for_each(rt.begin(), rt.end(), [](int x) { getinfo(x, 0); });
    for_each(rt.begin(), rt.end(), [](int x) { dfs(x, 0, 0); });
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}

