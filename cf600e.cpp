#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int col[maxn], cnt[maxn], sz[maxn];
bool big[maxn];
vector<vector<int> > g;
void getsz(int u, int p)
{
    sz[u] = 1;
    for(auto v : g[u]){
        if(v != p){
            getsz(v, u);
            sz[u] += sz[v];
        }
    }
}

void dfs(int u, int p, bool keep){
    int Max = 0, bigChild = -1;
    for(auto v : g[u]){
        if(v != p && sz[v] > Max){
            Max = sz[v];
            bigChild = v;
        }
    }
    for(auto v : g[u]){
        if(v != p && v != bigChild){
            dfs(v, u, 0);
        }
    }

}
int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <n; i++) {scanf("%d", &col[i]);}
    for(int i = 0; i < n - 1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    getsz(1, 0);


    return 0;
}
