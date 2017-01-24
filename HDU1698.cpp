#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int maxn = 100010;
int sum[maxn << 2];
int lazy[maxn << 2];

void PushUp (int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void PushDown (int l, int r, int rt)
{
    if (lazy[rt] == -1)
        return ;
    lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
    int m = (l + r) >> 1;
    sum[rt << 1] = lazy[rt] * (m - l + 1);
    sum[rt << 1 | 1] = lazy[rt] * (r - m);
    lazy[rt] = -1;
}

void build (int l, int r, int rt)
{
    lazy[rt] = -1;
    if (l == r) {
        sum[rt] = 1;
 //       lazy[rt]=-1 wrong  only (k,k)=-1  others=0;
        return ;
    }
    int m = (l + r) >> 1; //l+(r-l)>>1;
    build (lch);
    build (rch);
    PushUp (rt);
}

void update (int L, int R, int k, int l, int r, int rt)
{
    if (L <= l && r <= R) {
        lazy[rt] = k;
        sum[rt] = lazy[rt] * (r - l + 1);
    } else {
        PushDown (l, r, rt);
        int m = (r + l) >> 1;
        if (L <= m)  update (L, R, k, lch);
        if (R > m)  update (L, R, k, rch);
        PushUp (rt);
    }
}

int query_sum (int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) {
        return sum[rt];
    }
    PushDown (l, r, rt);
    int m = (l + r) >> 1;
    int res = 0;
    if (L <= m)  res += query_sum (L, R, lch);
    if (R > m)  res += query_sum (L, R, rch);
    return res;
}

int main (void)
{
    int t, kase = 0;
    scanf ("%d", &t);
    while (t--) {
        int n;
        scanf ("%d", &n);
        build (1, n, 1);
        int q;
        scanf ("%d", &q);
        for(int i=1;i<=q;i++) {
            int L, R, p;
            scanf ("%d%d%d", &L, &R, &p);
            update (L, R, p, 1, n, 1);
        }
        printf ("Case %d: The total value of the hook is %d.\n", ++kase, sum[1]);
    }
    return 0;
}
