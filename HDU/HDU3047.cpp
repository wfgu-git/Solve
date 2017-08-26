#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000;
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
        rk[x] = (rk[x] + rk[t]) % 300;
    }
    return fa[x];
}
int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        init(n);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int a, b, x;
            scanf("%d%d%d", &a, &b, &x);
            int ta = fnd(a);
            int tb = fnd(b);
            if (ta == tb) {
                if ((rk[b] - rk[a] + 300) % 300 != x)
                    ans++;
            } else {
                rk[tb] = (rk[a] + x - rk[b] + 300) % 300;
                fa[tb] = ta;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
