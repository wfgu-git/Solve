// copy from lonelam...
// dp is ok, either...
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

int nn;
void build(int *seg, int *val, int l = 0, int r = nn + 1, int rt = 1) {
    if (r - l == 1) {
        seg[rt] = val[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(seg, val, lch);
    build(seg, val, rch);
    seg[rt] = min(seg[rt << 1], seg[rt << 1 | 1]);
}

int query(int *seg, int L, int R, int l = 0, int r = nn + 1, int rt = 1) {
    if (L >= r || R <= l) return inf;
    if (L <= l && r <= R) {
        return seg[rt];
    }
    int ret = inf;
    int m = l + (r - l) / 2;
    if (L < m) ret = min(ret, query(seg, L, R, lch));
    if (R > m) ret = min(ret, query(seg, L, R, rch));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin >> kase;
    while (kase--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                grid[i + n][j] = grid[i][j + n] = grid[i + n][j + n] =
                    grid[i][j];
            }
        }
        int ans = 0;
        nn = 2 * n;
        for (int i = 0; i < n; i++) {
            cumrow[i][0] = 0;
            cumcol[i][0] = 0;
            cumldiag[i][0] = 0;
            cumrdiag[i][0] = 0;
            for (int j = 0; j < nn; j++) {
                cumrow[i][j + 1] = cumrow[i][j] + grid[i + n][j];
                cumcol[i][j + 1] = cumcol[i][j] + grid[j][i + n];
                cumldiag[i][j + 1] = cumldiag[i][j] + grid[j][(i + j) % nn];
                cumrdiag[i][j + 1] =
                    cumrdiag[i][j] + grid[j][(i + nn - j) % nn];
            }
            build(segrow[i], cumrow[i]);
            build(segcol[i], cumcol[i]);
            build(segldiag[i], cumldiag[i]);
            build(segrdiag[i], cumrdiag[i]);
            for (int j = 0; j < n; j++) {
                ans = max(ans, cumrow[i][j + n] - query(segrow[i], j, j + n));
                ans = max(ans, cumcol[i][j + n] - query(segcol[i], j, j + n));
                ans =
                    max(ans, cumldiag[i][j + n] - query(segldiag[i], j, j + n));
                ans =
                    max(ans, cumrdiag[i][j + n] - query(segrdiag[i], j, j + n));
            }
        }
        cout << ans << endl;
    }
}
