#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const ld eps = 1e-6;
ld C(ld n, ld m) {
    if (m < n - m) m = n - m;
    ld ans = 1;
    for (int i = m + 1; i <= n; i++) ans *= i;
    for (int i = 1; i <= n - m; i++) ans /= i;
    return ans;
}
int main() {
    int n, x;
    while (scanf("%d%d", &n, &x) == 2) {
        if (n == 1) printf("%.6f\n", 1.0);
        else {
            int m = ceil(1.0 * n / 5.0);
            ld p = (1.0 * x + 1.0) / 100.0;
            ld ans = 0;
            for (int i = 0.0; i < m; i++) {
                ans += 1.0 * C(n - 1, i) * pow(p, i) * pow((ld)(1.0 - p), n - 1 -i);
            }
            if (ans < eps) printf("Happy Yaoge!\n");
            else printf("%.6llf\n", ans);
        }
    }
    return 0;
}

