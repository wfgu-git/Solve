#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <iomanip>
#include <cctype>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1010;
const int INF = INT_MAX;
vector<pair<int, int> > G[maxn];
bool vis[maxn];
int distgo[maxn], distback[maxn];
int dis[maxn];
int n, m, x;

void add_edge(int u, int v, int d) {
    G[u].push_back(make_pair(v, d));
}

void spfa(int start, int n, int dist[]) {
    for(int i = 0; i < n; i++) {vis[i] = false;}

    for(int i = 0; i < n; i++) {dist[i] = (i == start ? 0 : INF);}

    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        vis[cur] = false;
        for(int i = 0; i < (int)G[cur].size(); i++) {
            int v = G[cur][i].first;
            int d = G[cur][i].second;
            if(dist[cur] + d < dist[v]) {
                dist[v] = dist[cur] + d;
                if(!vis[v])
                    q.push(v);
                vis[v] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    while(cin >> n >> m >> x) {
        for(int i = 0; i < n; i++) G[i].clear();
        memset(dis, 0, sizeof(dis));
        for(int i = 1; i <= m; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            add_edge(u - 1, v - 1, d);
        }
        //back
        spfa(x - 1, n, distback);
        for(int i = 0; i < n; i++) dis[i] = distback[i];
        for(int i = 0; i < n; i++) {
            spfa(i, n, distgo);
            dis[i] += distgo[x - 1];
        }
        int ans = -INF;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dis[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
