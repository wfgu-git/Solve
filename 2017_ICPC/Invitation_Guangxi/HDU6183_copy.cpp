#include <bits/stdc++.h>

#define MAXN 1000005
#define lson l, mid
#define rson mid + 1, r
#define INF 0x3f3f3f3f

using namespace std;

int tree[55], LL[MAXN << 2], RR[MAXN << 2], val[MAXN << 2];
int cnt;

void update(int &k, int need, int v, int l, int r) {
    if (k == 0) {
        k = ++cnt;
        val[k] = v;
    }
    val[k] = min(val[k], v);
    if (l == r) {
        return ;
    }
    int mid = l + r >> 1;
    if (need <= mid) {
        update(LL[k], need, v, lson);
    } else {
        update(RR[k], need, v, rson);
    }
}

bool ok;

void query(int L, int R, int x, int v, int l, int r) {
    if (x == 0 || ok) {
        return ;
    }
    if (L <= l && r <= R) {
        if (val[x] <= v) {
            ok = true;
        }
        return ;
    }
    int mid = l + r >> 1;
    if (L <= mid) {
        query(L, R, LL[x], v, lson);
    }
    if (R > mid) {
        query(L, R, RR[x], v, rson);
    }
}

int main() {
    int opt, x, y, c, y1, y2, ans;
    while (true) {
        scanf("%d", &opt);
        switch (opt) {
            case 0:
                memset(tree, 0, sizeof(tree));
                memset(LL, 0, sizeof(LL));
                memset(RR, 0, sizeof(RR));
                cnt = 0;
                break;
            case 1:
                scanf("%d %d %d", &x, &y, &c);
                update(tree[c], y, x, 1, MAXN - 5);
                break;
            case 2:
                scanf("%d %d %d", &x, &y1, &y2);
                ans = 0;
                if (y1 > y2) {
                    swap(y1, y2);
                }
                for (int i = 0; i <= 50; i++) {
                    ok = false;
                    query(y1, y2, tree[i], x, 1, MAXN - 5);
                    if (ok) {
                        ans++;
                    }
                }
                printf("%d\n", ans);
                break;
            case 3:
                return 0;
        }
    }
}
