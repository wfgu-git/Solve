// learn dsu on tree
//...
// navie O(n^2)
int cnt[maxn];
void add(int u, int p, int x) {
    cnt[color[u]] += x;
    for (auto v : G[v]) {
        if (v != p) {
            add(v, u, x);
        }
    }
}

void dfs(int v, int p) {
    add(v, p, 1);
    add(v, p, -1);
    for (auto u : G[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
}


map<int, int> *cnt[maxn];
void dfs(int v, int p) {
    int mx = -1, bigch = -1;
    for (auto u : G[v]) {
        if (u != p) {
            dfs(u, v);
            if (sz[v] > mx) {
                mx = sz[u];
                bigch = u;
            }
        }
    }
    if (bigch != -1) cnt[v] = cnt[bigch];
    else cnt[v] = new map<int, int> ();
    (*cnt[v])[color[v]]++;
    for (auto u : G[v]) {
        if (u != p && u != bigch) {
            for (auto x : *cnt[u]) {
                (*cnt[v])[x.first] += x.second;
            }
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int>g[maxn];
int cnt[maxn];
int main(void) {

    return 0;
}