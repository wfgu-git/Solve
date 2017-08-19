#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_V = 205;

vector<int> G[MAX_V]; // 图
int V;                  // 顶点数
int color[MAX_V];       // 顶点i的颜色 1 或 -1

// 把顶点染成1或-1
bool dfs(int v, int c)
{
    color[v] = c; // 把顶点v染成颜色c
    for (int i = 0; i < G[v].size(); ++i) {
        if (color[G[v][i]] == c) return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    return true;
}

void solve()
{
    for (int i = 0; i < V; ++i) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                puts("No");
                return ;
            }
        }
    }
    puts("Yes");
}

int main()
{
    int E;
    while (scanf("%d%d", &V, &E) == 2) {
        int a, b;
        for (int i = 0; i < V; ++i) G[i].clear();
        memset(color, 0, sizeof color);
        for (int i = 0; i < E; ++i) {
            scanf("%d%d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        solve();
    }
    return 0;
}
