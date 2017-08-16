#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int fa[maxn + 2], rk[maxn + 2];
void init(const int &n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        rk[i] = 0;
    }
}
int fnd(int x) {
    if (x != fa[x]) {
        int t = fa[x];
        fa[x] = fnd(fa[x]);
        rk[x] += rk[t];
    }
    return fa[x];
}
void mrg(int a, int b, int d) {
    int ta = fnd(a);
    int tb = fnd(b);
    rk[tb] = rk[a] + d - rk[b];
    fa[tb] = ta;
}
int main() {
    int n, m, q;
    while (scanf("%d%d%d", &n, &m, &q) == 3) {
        init(n);
        for (int i = 0; i < m; i++) {
            int a, b, d;
            scanf("%d%d%d", &a, &b, &d);
            mrg(a, b, d);
        }
        for (int i = 0; i < q; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            int ta = fnd(a);
            int tb = fnd(b);
            if (ta == tb) {
                printf("%d\n", rk[b] - rk[a]);
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}
