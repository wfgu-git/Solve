#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 500005;
int sz[maxn], dep[maxn], skip[maxn];
char ch[maxn];
int ret[maxn], str[maxn];
vector<vector<int> > g;
vector<pair<int, int> > qry[maxn];
void getinfo(int u, int p)
{
    sz[u] = 1;
    dep[u] = dep[p] + 1;
    for(auto v : g[u]) {
        if(v != p) {
            getinfo(v, u);
            sz[u] += sz[v];
        }
    }
}
void add(int u, int p)
{
    str[dep[u]] = str[dep[u]] ^ (1 << (ch[u] - 'a'));
    for(auto v : g[u]) {
        if(v == p || skip[v]) continue;
        add(v, u);
    }
}
void dfs(int u, int p, bool keep)
{
    int Max = -1, bigChild = -1;
    for(auto v : g[u]) {
        if(v == p) continue;
        if(sz[v] > Max) {
            Max = sz[v];
            bigChild = v;
        }
    }
    for(auto v : g[u]) {
        if(v != p && v != bigChild)
            dfs(v, u, 0);
    }
    if(bigChild != -1) dfs(bigChild, u, 1), skip[bigChild] = 1;
    add(u, p);
    for(auto q : qry[u]) {
        ret[q.second] = str[q.first];
    }
    if(bigChild != -1) skip[bigChild] = 0;
    if(keep == false) add(u, p);
}
int main()
{
    scanf("%d%d", &n, &m);
    g.resize(n + 2);
    g.clear();
    for(int u = 2, fa; u <= n; u++) {
        scanf("%d", &fa);
        g[fa].push_back(u);
        g[u].push_back(fa);
    }
    scanf("%s", ch + 1);
    for(int i = 1, v, h; i <= m; i++) {
        scanf("%d%d", &v, &h);
        qry[v].push_back({h, i});
    }
    getinfo(1, 0);
    dfs(1, 0, 0);
    for(int i = 1; i <= m; i++) {
        int num1 = __builtin_popcount(ret[i]);
        if(num1 <= 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
