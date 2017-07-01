//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5;
bool vis[maxn * 2 + 5];
int fa[maxn * 2 + 5];
void init(const int &n) {
    for (int i = 1; i <= n * 2 + 5; i++) fa[i] = i;
}
int fnd(int x) {
    if (x != fa[x]) fa[x] = fnd(fa[x]);
    return fa[x];
}
void mrg(int a, int b) {
    a = fnd(a);
    b = fnd(b);
    if (a == b) return;
    fa[a] = b;
}
bool same(int a, int b) {
    return fnd(a) == fnd(b);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        memset(vis, 0, sizeof(vis));
        char op[5];
        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'A') {
//                if (!vis[a] || !vis[b]) printf("Not sure yet.\n");
                if (same(a, b)) printf("In the same gang.\n");
                else if (same(a, b + n)) printf("In different gangs.\n");
                else printf("Not sure yet.\n");
            } else {
//                vis[a] = true;
//                vis[b] = true;
                mrg(a, b + n);
                mrg(b, a + n);
            }
        }
    }
    return 0;
}

