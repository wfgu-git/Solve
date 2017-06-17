#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, k, tot;
int head[maxn], sz[maxn], depth[maxn], belong[maxn];
struct Edge {
    int u, v, d;
    int next;
} edge[maxn << 1];
void add_edge (int u, int v, int d) {
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].d = d;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void init() {
    tot = 0;
    memset (head, -1, sizeof (head));
}
void getsz(int u, int p){
    sz[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next){
        int v = edge[i].v;
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void getroot(int u, int p, int tot, int &root){

}
int dfs(int u, int p){

}
int main() {
    while (scanf ("%d%d", &n, &k) == 2 && (n + k)) {
        init();
        int u, v, d;
        for (int i = 0; i < n - 1; i++) {
            scanf ("%d%d%d", &u, &v, &d);
            if (d > k) continue;
            add_edge (u, v, d);
            add_edge (v, u, d);
        }
        getsz();
    }
    return 0;
}
