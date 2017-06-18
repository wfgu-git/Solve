#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int n, c, d;
int ret;
int segcoin[maxn << 2];
int segdiam[maxn << 2];
pair<int, int> coin[maxn];
pair<int, int> diam[maxn];
void update(int *seg, int pos, int k, int l = 1, int r = maxn + 1, int rt = 1) {
    if (pos == l && r - l == 1) {
        seg[rt] = max(seg[rt], k);
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos < mid) update(seg, pos, k, l, mid, rt << 1);
    else update(seg, pos, k, mid, r, rt << 1 | 1);
    seg[rt] = max(seg[rt << 1], seg[rt << 1 | 1]);
}
int query(int *seg, int L, int R, int l = 1, int r = maxn + 1, int rt = 1) {
    if (L >= r || R <= l) return -1;
    if (L <= l && r <= R) return seg[rt];

    int ret = -inf;
    int mid = l + (r - l) / 2;
    if (L < mid) ret = max(ret, query(seg, L, R, l, mid, rt << 1));
    if (R > mid) ret = max(ret, query(seg, L, R, mid, r, rt << 1 | 1));
    return ret;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> c >> d;
    memset(coin, 0, sizeof(coin));
    memset(diam, 0, sizeof(diam));
    int cbmax = -inf;
    int dbmax = -inf;
    int ctot = 0, dtot = 0;
    for (int i = 0; i < n; i++) {
        int b, p;
        char t;
        cin >> b >> p >> t;
        if (t == 'C' && c >= p) {
            coin[ctot++] = {p, b};
            cbmax = max(cbmax, b);
        } else if (t == 'D' && d >= p) {
            diam[dtot++] = {p, b};
            dbmax = max(dbmax, b);
        }
    }
    ret = cbmax + dbmax;

    memset(segcoin, -1, sizeof(segcoin));
    for (int i = 0; i < ctot; i++) {
        if (coin[i].first < c) {
            int temp = query(segcoin, 0, c - coin[i].first + 1);
            update(segcoin, coin[i].first, coin[i].second);
            if (temp != -1) ret = max(ret, temp + coin[i].second);
        }
    }

    memset(segdiam, -1, sizeof(segdiam));
    for (int i = 0; i < dtot; i++) {
        if (diam[i].first < d) {
            int temp = query(segdiam, 0, d - diam[i].first + 1);
            update(segdiam, diam[i].first, diam[i].second);
            if (temp != -1) ret = max(ret, temp + diam[i].second);
        }
    }
    if (ret < 0) cout << 0 << endl;
    else cout << ret << endl;
    return 0;
}


