#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 3e3 + 10;
int n;
int mx[MAXN][MAXN], mn[MAXN][MAXN];
int a[MAXN], f[MAXN][MAXN]; // f[i][j] : [i, j] 最多能分成多少块
void init() {
    for(int i = 1; i <= n; i++) {
        mx[i][i] = mn[i][i] = a[i];
        for(int j = i + 1; j <= n; j++) {
            mx[i][j] = max(mx[i][j - 1], a[j]);
            mn[i][j] = min(mn[i][j - 1], a[j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        int cnt = 1;
        f[i][i] = 1;
        for(int j = i + 1; j <= n; j++) {
            if(mn[i][j - 1] != mn[i][j]) cnt = 0;
            if(j - i == mx[i][j] - mn[i][j]) f[i][j] = ++cnt;
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(f, 0, sizeof f);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        init();
        int ans = f[1][n];
        for(int i = 1; i <= n; i++) { // 枚举要交换的左端 [i, j]，判断合法并寻找交换的右端
            for(int j = i; j <= n; j++) {
                if(f[i][j]) {
                    if(i == 1 || (mn[1][i - 1] == 1 && mx[1][i - 1] - mn[1][i - 1] == i - 2)) {
                        int x = mx[i][j];
                        if(x == n || (mx[x + 1][n] == n && mx[x + 1][n] - mn[x + 1][n] == n - x - 1)) {
                            for(int k = x; k > j; k--) {
                                if(f[k][x] && mn[k][x] == i) {
                                    ans = max(ans, f[1][i - 1] + 1 + f[j + 1][k - 1] + 1 + f[x + 1][n]);
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
