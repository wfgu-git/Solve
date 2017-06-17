#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
struct Edge {
    int u, v, d, next;
} e[maxn << 1];
int head[maxn], tot, n, ret[maxn];
int maxdist[maxn], maxid[maxn];
int secdist[maxn], secid[maxn];
void add_edge(int u, int v, int d) {
    e[tot].u = u;
    e[tot].v = v;
    e[tot].d = d;
    e[tot].next = head[u];
    head[u] = tot++;
}

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

void dfs_subtree(int u, int p) {
    maxdist[u] = 0;
    secdist[u] = 0;
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        int d = e[i].d;
        if (v == p) continue;
        dfs_subtree(v, u);
        if (secdist[u] < maxdist[v] + d) {
            secdist[u] = maxdist[v] + d;
            secid[u] = v;
            if (secdist[u] > maxdist[u]) {
                swap(secdist[u], maxdist[u]);
                swap(secid[u], maxid[u]);
            }
        }
    }
}

void dfs_fa(int u, int p) {
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        int d = e[i].d;
        if (v == p) continue;
        if (v == maxid[u]) {
            if (secdist[v] < secdist[u] + d) {
                secdist[v] = secdist[u] + d;
                secid[v] = u;
                if (secdist[v] > maxdist[v]) {
                    swap(secdist[v], maxdist[v]);
                    swap(secid[v], maxid[v]);
                }
            }
        } else {
            if (secdist[v] < maxdist[u] + d) {
                secdist[v] = maxdist[u] + d;
                secid[v] = u;
                if (secdist[v] > maxdist[v]) {
                    swap(secdist[v], maxdist[v]);
                    swap(secid[v], maxid[v]);
                }
            }
        }
        dfs_fa(v, u);
    }
}

void debug() {
    for (int i = 1; i <= n; i++) {
        cout << "v = " << i << "  " << "max = " << maxdist[i] << "  sec = " << secdist[i] << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << "maxid = " << maxid[i] << "  secid = " << secid[i] << endl;
    }
}

int main(int argc, char const *argv[]) {
    while (scanf("%d", &n) == 1) {
        init();
        for (int u = 2; u <= n; u++) {
            int v, d;
            scanf("%d%d", &v, &d);
            add_edge(u, v, d);
            add_edge(v, u, d);
        }
        dfs_subtree(1, 0);
        // debug();
        dfs_fa(1, 0);
        // cout << "\n\n";
        // debug();

        for (int i = 1; i <= n; i++) {
            printf("%d\n", maxdist[i]);
        }
    }
    return 0;
}
