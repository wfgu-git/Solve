#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef __int64 ll;
const int maxn = 100010;
ll seg[maxn << 2];
ll lazy[maxn << 2];
int n, m;
void pushDown(int l, int r, int rt) {
    if(!lazy[rt])
        return;

    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    int m = l + (r - l) / 2;
    seg[rt << 1] += (m - l) * lazy[rt];
    seg[rt << 1 | 1] += (r - m) * lazy[rt];
    lazy[rt] = 0;
}

void build(int l = 1, int r = n + 1, int rt = 1) {
    lazy[rt] = 0;
    if(r - l == 1) {
        scanf("%I64d", &seg[rt]);
        return;
    }
    int m = l + (r - l) / 2;
    build(l, m, rt << 1);
    build(m, r, rt << 1 | 1);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void update(int ul, int ur, int c, int l = 1, int r = n + 1, int rt = 1) {
    if(ul <= l && r <= ur) {
        lazy[rt] += c;
        seg[rt] += (r - l) * (ll)c;
        return;
    }
    pushDown(l, r, rt);
    int m = l + (r - l) / 2;
    if(ul < m) update(ul, ur, c, l, m, rt << 1);
    if(ur > m) update(ul, ur, c, m, r, rt << 1 | 1);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

ll query(int ql, int qr, int l = 1, int r = n + 1 , int rt = 1) {
    if(ql <= l && r <= qr) {
        return seg[rt];
    }
    pushDown(l, r, rt);
    int m = l + (r - l) / 2;
    ll ret = 0;
    if(ql < m) ret += query(ql, qr, l, m, rt << 1);
    if(qr > m) ret += query(ql, qr, m, r, rt << 1 | 1);
    return ret;
}

int main(int argc, char const *argv[]) {
    while(scanf("%d%d", &n, &m) == 2) {
        memset(seg, 0, sizeof(seg));
        // memset(lazy, 0, sizeof(lazy));
        build();
        char op[10];
        for(int i = 0; i < m; i++) {
            scanf("%s", op);
            if(op[0] == 'Q') {
                int ql, qr;
                scanf("%d%d", &ql, &qr);
                printf("%I64d\n", query(ql, qr + 1));
            } else if(op[0] == 'C') {
                int ul, ur, k;
                scanf("%d%d%d", &ul, &ur, &k);
                update(ul, ur + 1, k);
            }
        }
    }
    return 0;
}