#include <bits/stdc++.h>
using namespace std;

const int maxn = 50005;
int n, m;
int a[maxn], b[maxn], c[maxn];
int blksz, blk[maxn];
int ret[maxn];
struct Interval{ int l, r, id;}qry[maxn];
bool cmp (Interval a, Interval b) {
    if (blk[a.l] == blk[b.l])
        return a.r < b.r;
    return blk[a.l] < blk[b.l];
}

inline int lowbit (int x) { return x & -x; }
int get_sum (int x) {
    int ret = 0 ;
    while (x > 0) { ret += c[x]; x -= lowbit (x); }
    return ret;
}
void update (int x, int k) {
    while (x <= n) {
        c[x] += k;
        x += lowbit (x);
    }
}
void init() {
    memset (c, 0, sizeof (c));
}
int main()
{
    while (scanf ("%d", &n) == 1) {
        init();
        blksz = ceil (sqrt (1.0 * n));
        for (int i = 1; i <= n; i++) { scanf ("%d", &a[i]); b[i] = a[i]; blk[i] = (i - 1) / blksz; }
        scanf ("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf ("%d%d", &qry[i].l, &qry[i].r);
            qry[i].id = i;
        }
        sort (qry, qry + m, cmp);
        sort (b + 1, b + 1 + n);
        int sz = unique (b + 1, b + 1 + n) - (b + 1);
        for (int i = 1; i <= n; i++) { a[i] = lower_bound (b + 1, b + 1 + sz, a[i]) - b; }
        // Äª¶Ó
        int ans = 0, l = 1, r = 0;
        for (int i = 0; i < m; i++) {
            int qry_id = qry[i].id;
            int ql = qry[i].l;
            int qr = qry[i].r;
            while (r < qr) {
                update (a[++r], 1);
                ans += (r - l + 1 - get_sum (a[r]));
            }
            while (r > qr) {
                ans -= (r - l + 1 - get_sum (a[r]));
                update (a[r--], -1);
            }
            while (l < ql) {
                ans -= get_sum (a[l] - 1);
                update (a[l++], -1);
            }
            while (l > ql) {
                update (a[--l], 1);
                ans += get_sum (a[l] - 1);
            }
            ret[qry_id] = ans;
        }
        for (int i = 0; i < m; i++) printf ("%d\n", ret[i]);
    }
    return 0;
}
