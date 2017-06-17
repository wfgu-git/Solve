#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
__int64  a[maxn];
__int64 blk[maxn];
__int64 cnt[1000005];
__int64 blksz, blkid, l, r;
__int64 n, m;
__int64 ret, ans[maxn];
struct query {
    int l, r;
    int id;
} qry[maxn];
bool cmp(query a, query b) {
    if(blk[a.l] == blk[b.l]) {
        return a.r < b.r;
    } else {
        return a.l < b.l;
    }
}

inline void add(int val) {
    ret += val * (1 + 2 * cnt[val]++);
}
inline void del(int val) {
    ret -= val * (-1 + 2 * cnt[val]--);
}

int main(int argc, char const *argv[]) {
    scanf("%I64d%I64d", &n, &m);
    blksz = ceil(sqrt(1.0 * n));
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        blk[i] = (i - 1) / blksz;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &qry[i].l, &qry[i].r);
        qry[i].id = i;
    }
    sort(qry, qry + m, cmp);
    ret = 0;
    l = 1, r = 0;
    for(int i = 0; i < m; i++) {
        blkid = qry[i].id;

        while(r < qry[i].r) add(a[++r]);
        while(r > qry[i].r) del(a[r--]);
        while(l < qry[i].l) del(a[l++]);
        while(l > qry[i].l) add(a[--l]);
        ans[blkid] = ret;

        // debug
        // cout << "res of  (" << qry[i].l << ", " << qry[i].r << ") = " << ret << endl;
    }

    for(int i = 0; i < m; i++) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}