#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define lch l,m,rt<<1
#define rch m,r,rt<<1|1

const int maxn = 1e5 + 10;
int n, m, nn;
int dfs_clock;
int st[maxn], ft[maxn];
int seg[maxn << 2];
bool vis[maxn];
vector<vector<int> > g;
void dfs(int u) {
    st[u] = ++dfs_clock;
    vis[u] = true;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (vis[v]) continue;
        dfs(v);
    }
    ft[u] = dfs_clock + 1;
}

void build(int l = 1, int r = nn + 1, int rt = 1) {
    if (r - l == 1) {
        seg[rt] = 1;
        return;
    }
    int m = l + (r - l) / 2;
    build(lch);
    build(rch);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void update(const int &p, int l = 1, int r = nn + 1, int rt = 1) {
    if (p == l && r - l == 1) {
        seg[rt] ^= 1;
        return;
    }
    int m = l + (r - l) / 2;
    if (p < m) update(p, lch);
    else update(p, rch);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

int query(const int &ql, const int &qr, int l = 1, int r = nn + 1, int rt = 1) {
    if (ql <= l && r <= qr) {
        return seg[rt];
    }
    int m = l + (r - l) / 2;
    int ret = 0;
    if (ql < m) ret += query(ql, qr, lch);
    if (qr > m) ret += query(ql, qr, rch);
    return ret;
}

int main(int argc, char const *argv[]) {
    while (~scanf("%d", &n)) {
        g.resize(n + 2);
        g.clear();
        dfs_clock = 0;
        memset(vis, 0, sizeof(vis));
        // memset(seg, 0 , sizeof(seg));
        // memset(st, 0, sizeof(st));
        // memset(ft, 0, sizeof(ft));
        nn = n;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        build();
        dfs(1);

        char op[5];
        int x, qr, ql, p, ans;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%s%d", op, &x);
            if (op[0] == 'C') {
                p = st[x];
                update(p);
            } else {
                ql = st[x];
                qr = ft[x];
                ans = query(ql, qr);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

