#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 50005;
int seg[maxn << 2];
int val[maxn];
int n;
void build(int l = 1, int r = n + 1, int rt = 1) {
    if(r - l == 1) {
        seg[rt] = val[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(l, m, rt << 1);
    build(m, r, rt << 1 | 1);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void update(int p, int k, int l = 1, int r = n + 1, int rt = 1) {
    if(p == l && r - l == 1) {
        seg[rt] += k;
        return;
    }
    int m = l + (r - l) / 2;
    if(p < m) update(p, k, l, m, rt << 1);
    else update(p, k, m, r, rt << 1 | 1);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

int query(int L, int R, int l = 1, int r = n + 1, int rt = 1) {
    if(L <= l && r <= R) {
        return seg[rt];
    }
    int m = l + (r - l) / 2;
    int ret = 0;
    if(L < m) ret += query(L, R, l, m, rt << 1);
    if(R > m) ret += query(L, R, m, r, rt << 1 | 1);
    return ret;
}

int main(int argc, char const *argv[]) {
    int T;
    // cin >> T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        // cout << "Case " << kase << ":\n";
        printf("Case %d:\n", kase);
        memset(seg, 0, sizeof(seg));
        memset(val, 0, sizeof(val));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)  scanf("%d", &val[i]);
        build();
        char op[10];
        int a, b;
        while(~scanf("%s", op)) {
            if(op[0] == 'E') break;
            scanf("%d%d", &a, &b);
            if(op[0] == 'Q') {
                printf("%d\n", query(a, b + 1));
            } else if(op[0] == 'S') {
                update(a, -b);
            } else if(op[0] == 'A') {
                update(a, b);
            }
        }
    }
    return 0;
}