#include <bits/stdc++.h>
using namespace std;
#define lch l, m, rt << 1
#define rch m + 1, r, rt << 1 | 1

int kase, n;
const int maxn = 2020;
int grid[maxn][maxn];
int cumrow[maxn][maxn];
int cumcol[maxn][maxn];
int cumldiag[maxn][maxn];
int cumrdiag[maxn][maxn];
int segrow[maxn][maxn << 1];
int segcol[maxn][maxn << 1];
int segldiag[maxn][maxn << 1];
int segrdiag[maxn][maxn << 1];

void build(int l, int r, int rt) {
    if (l == r) {
        return;
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin >> kase;
    while (kase--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        int ans = 0;
    }
}
