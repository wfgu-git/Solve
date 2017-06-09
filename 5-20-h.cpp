#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
vector< vector<int> > g;
map<pair<int, int>, bool> check;
bool vis[maxn];
bool bfs(const int &n)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(1);
    vis[1] = true;
    int cnt = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto v : g[cur]){
            if(!vis[v]){
                q.push(v);
                vis[v] = true;
                cnt++;
            }
        }
    }
    return cnt == n? true : false;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    bool flag = true;
    if(n != m) flag = false;
    g.resize(n + 2);
    g.clear();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(u == v) flag = false;
        if(check[{u, v}] == true) flag = false;
        else {
            g[u].push_back(v);
            g[v].push_back(u);
            check[{u, v}] = true;
            check[{v, u}] = true;
        }
    }
    if(flag && bfs(n)) cout << "Bingo" << endl;
    else cout << "Break up" << endl;

    return 0;
}

