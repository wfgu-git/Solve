#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 200005;
struct Edge {
    int u, v;
    int next;
} edge[maxn << 1];
int n, tot;
int retid, retsum;
int sz[maxn], head[maxn];
void add_edge(int u, int v) {
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void init() {
    tot = 0;
    retid = 0;
    retsum = 0x3f3f3f3f;
    memset(head, -1, sizeof(head));
}
void dfs(int u, int p) {
    sz[u] = 1;
    int temp = -1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        temp = max(temp, sz[v]);
    }
    temp = max(temp, n - sz[u]);
    if (temp < retsum || (temp == retsum && u < retid)) {
        retid = u;
        retsum = temp;
    }
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        init();
        scanf("%d", &n);
        int u, v;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        dfs(1, -1);
        printf("%d %d\n", retid, retsum);
    }
}