#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int t, tot;
int g[maxn + 5][maxn + 5];
bool vis[maxn + 5];
vector < int > path;
map < int, vector < int > > ans;
int fa[maxn + 5];
int fnd(int x) {
    if (x != fa[x]) fa[x] = fnd(fa[x]);
    return fa[x];
}
void merge(int a, int b) {
    a = fnd(a);
    b = fnd(b);
    if (a == b) return;
    fa[a] = b;
}
void init(int n = 22) {
    tot = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    memset(vis, 0, sizeof(vis));
    memset(g, 0, sizeof(g));
    ans.clear();
    path.clear();
}
void print(const vector <int > &x) {
    for (int i = 0; i < x.size(); i++) {
        if (i) printf(" ");
        printf("%d", x[i]);
        if (i == x.size() - 1) printf("\n");
    }
}
void dfs(int u) {
    if (u == t) {
        ans[++tot] = path;
        return;
    }
    for (int v = 2; v <= 22; v++) {
        if (vis[v] == false && g[u][v] == 1) {
            vis[v] = true;
            path.push_back(v);
            dfs(v);
            vis[v] = false;
            path.pop_back();
        }
    }
}
int main() {
    int kase = 0;
    while (scanf("%d", &t) != EOF) {
        init();
        int u, v;
        for (; scanf("%d%d", &u, &v) && (u + v);) {
            merge(u, v);
            g[u][v] = 1;
            g[v][u] = 1;
        }
        printf("CASE %d:\n", ++kase);
        if (fnd(1) != fnd(t)) {
            printf("There are %d routes from the firestation to streetcorner %d.\n", 0, t);
        } else {
            vis[1] = true;
            path.push_back(1);
            dfs(1);
            for (auto kv : ans) {
                print(kv.second);
            }
            printf("There are %d routes from the firestation to streetcorner %d.\n", tot, t);
        }
    }
    return 0;
}
