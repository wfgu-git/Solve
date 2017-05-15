#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200020;
int seg[maxn << 2];
int val[maxn];
int n, m;
void build(int l = 1, int r = n + 1, int rt = 1) {
    if(r - l == 1) {
        scanf("%d", &seg[rt]);
        return;
    }
    int m = l + (r - l) / 2;
    build(l, m, rt << 1);
    build(m, r, rt << 1 | 1);
    seg[rt] = max(seg[rt << 1] , seg[rt << 1 | 1]);
}

void update(int p, int k, int l = 1, int r = n + 1, int rt = 1) {
    if(p == l && r - l  == 1) {
        seg[rt] = k;
        return;
    }
    int m = l + (r - l) / 2;
    if(p < m) update(p, k, l, m, rt << 1);
    else update(p, k, m, r, rt << 1 | 1);
    seg[rt] = max(seg[rt << 1] , seg[rt << 1 | 1]);
}

int query(int ql, int qr, int l = 1, int r = n + 1, int rt = 1) {
    if(ql <= l && r <= qr) {
        return seg[rt];
    }
    int m = l + (r - l) / 2;
    int ret = -1;
    if(ql < m) ret = max(ret, query(ql, qr, l, m, rt << 1));
    if(qr > m) ret = max(ret, query(ql, qr, m, r, rt << 1 | 1));
    return ret;
}

int main(int argc, char const *argv[]) {
    while(scanf("%d%d", &n, &m) == 2) {
        memset(seg, 0, sizeof(seg));
        build();
        char op[10];
        int a, b;
        for(int i = 0; i < m; i++) {
            scanf("%s%d%d", op, &a, &b);
            if(op[0] == 'Q') {
                printf("%d\n", query(a, b + 1));
            } else {
                update(a, b);
            }
        }
    }
    return 0;
}