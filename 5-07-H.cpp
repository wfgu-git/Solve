#include <bits/stdc++.h>
using namespace std;
#define lch l, m, rt << 1
#define rch m, r, rt << 1 | 1

int kase, n;
const int maxn = 2020;
const int inf = INT_MAX;
int grid[maxn][maxn];
int cumrow[maxn][maxn];
int cumcol[maxn][maxn];
int cumldiag[maxn][maxn];
int cumrdiag[maxn][maxn];
int segrow[maxn][maxn << 1];
int segcol[maxn][maxn << 1];
int segldiag[maxn][maxn << 1];
int segrdiag[maxn][maxn << 1];


void build(int *seg, int *val, int l = 0, int r = nn + 1, int rt = 0) {
    if(r - l == 1) {
        seg[rt] = val[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(seg, val, lch);
    build(seg, val, m, rch);
    seg[rt] = min(seg[rt << 1], seg[rt << 1 | 1]);
}

int query(int *seg, int L, int R, int l = 0, int r = nn + 1, int rt = 0) {
    if(L >= r || R <= l) return inf;
    if(L <= l && r <= R) {
        return seg[rt];
    }
    int ret = inf;
    int m = l + (r - l) / 2;
    if(L < m)  ret = min(ret, query(seg, L, R, lch));
    if(R > m) ret = min(ret, query(seg, L, R, rch));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin >> kase;
    while(kase--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        int ans = 0;
    }
}
