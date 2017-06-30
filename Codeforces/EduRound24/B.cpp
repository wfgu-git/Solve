#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n, m;
int a[maxn + 2], l[maxn + 2];
int used[maxn + 2];
void print(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", a[i]); 
        if (i == n) printf("\n");
    }
}
bool ok() {
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= n; j++) {
                if (!used[j]) {
                    a[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
    }
    bool vis[105];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (vis[a[i]]) return false;
        vis[a[i]] = true;
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &m);
    bool flag = true;
    for (int i = 0; i < m; i++) scanf("%d", l + i);
    for (int i = 0; i < m - 1; i++) {
        // print(a, n);
        int dx = (l[i + 1] - l[i] + n) % n;
        if (dx == 0) dx = n;
        if (a[l[i]] && a[l[i]] != dx) {
            flag = false;
            break;
        }
        a[l[i]] = dx;
        used[dx] = true;
    }
    if (flag && ok()) {
        print(a, n);
    } else {
        cout << -1 << endl;
    }
    return 0;
}