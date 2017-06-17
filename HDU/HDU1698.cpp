#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;
struct segtree {
    int val, lazy;
} seg[maxn << 2];
int n, m;
void pushDown(int l, int r, int rt) {
    if(seg[rt].lazy == 0)
        return;

    int m = l + (r - l) / 2;
    seg[rt << 1].lazy = seg[rt << 1 | 1].lazy = seg[rt].lazy;
    seg[rt << 1].val = (m - l) * seg[rt].lazy;
    seg[rt << 1 | 1].val = (r - m) * seg[rt].lazy;
    seg[rt].lazy = 0;
}

void build(int l = 1, int r = n + 1, int rt = 1) {
    seg[rt].lazy = 0;
    if(r - l == 1) {
        seg[rt].val = 1;
        return;
    }
    int m = l + (r - l) / 2;
    build(l, m, rt << 1);
    build(m, r, rt << 1 | 1);
    seg[rt].val = seg[rt << 1].val + seg[rt << 1 | 1].val;
}

void update(int ul, int ur, int k, int l = 1, int r = n + 1, int rt = 1) {
    if(ul <= l && r <= ur) {
        seg[rt].lazy = k;
        seg[rt].val = (r - l) * k;
        return;
    }
    pushDown(l, r, rt);
    int m = l + (r - l) / 2;
    if(ul < m) update(ul, ur, k, l, m, rt << 1);
    if(ur > m) update(ul, ur, k, m, r, rt << 1 | 1);
    seg[rt].val = seg[rt << 1].val + seg[rt << 1 | 1].val;
}

int query(int ql, int qr, int l = 1, int r = n + 1, int rt = 1) {
    if(ql <= l && r <= qr) {
        return seg[rt].val;
    }
    pushDown(l, r, rt);
    int m = l + (r - l) / 2;
    int ret = 0;
    if(ql < m) ret += query(ql, qr, l, m, rt << 1);
    if(qr > m) ret += query(ql, qr, m, r, rt << 1 | 1);
    return ret;
}

int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        memset(seg, 0, sizeof(seg));
        scanf("%d%d", &n, &m);
        // update(1, n + 1, 1);
        build();
        for(int i = 0; i < m; i++) {
            int ql, qr, k;
            scanf("%d%d%d", &ql, &qr, &k);
            update(ql, qr + 1, k);
        }
        printf("Case %d: The total value of the hook is %d.\n", kase, query(1, n + 1));
    }
    return 0;
}