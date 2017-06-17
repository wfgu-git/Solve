// /*************************************************************************
//     > File Name: POJ2387.cpp
//     > Author:Prgu
//     > Mail:peter.wfgu@gmail.com
//     > Created Time: 2017年01月08日 星期日 16时52分08秒
//  ************************************************************************/

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// #include<queue>
// #include<map>
// #include<set>
// #include<cstring>
// #include<cstdio>
// #include<cmath>
// #include<cstdlib>
// #include<stack>
// #include<iomanip>
// #include<cctype>
// #include<climits>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;

// const int maxn = 2020;
// const int INF = 0x3f3f3f3f;
// typedef pair<int, int> PII;
// #define MP(a,b) make_pair(a,b)
// bool vis[maxn];
// int dist[maxn];
// vector<PII> G[maxn];

// void add_edge(int u, int v, int d)
// {
//     G[u].push_back(MP(v, d));
// }

// void spfa(int start, int n)
// {
//     for(int i = 0; i <= n; i++) {vis[i] = false;}

//     for(int i = 0; i < n; i++) {dist[i] = INF;}
//     dist[start] = 0;

//     queue<int> q;
//     q.push(start);

//     while(!q.empty()) {
//         int cur = q.front(); q.pop();
//         vis[cur] = false;
//         for(int i = 0; i < (int)G[cur].size(); i++) {
//             int v = G[cur][i].first;
//             int d = G[cur][i].second;
//             if(dist[cur] + d < dist[v]) {
//                 dist[v] = dist[cur] + d;
//                 if(!vis[v]) {
//                     q.push(v);
//                     vis[v] = true;
//                 }
//             }
//         }
//     }
// }


// int main(void)
// {
//     ios::sync_with_stdio(false);
//     int n, m;
//     while(cin >> m >> n) {
//         for(int i = 0; i < n; i++) G[i].clear();

//         for(int i = 0; i < m; i++) {
//             int from, to, value;
//             cin >> from >> to >> value;
//             add_edge(from - 1, to - 1, value);
//             add_edge(to - 1, from - 1, value);
//         }
//         spfa(0, n);
//         cout << dist[n - 1] << endl;
//     }
//     return 0;
// }

/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <iomanip>
#include <cctype>
#include <climits>
#include <utility>
#include <memory>
#include <functional>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
//typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a,b) scanf("%d%d",&a, &b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a, &b, &c)
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) sort(all(x)); v.erase(unique(all(v)), end())
#define mp(a,b) make_pair(a,b)
#define clr(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
#define Max(a,b)  ((a)>(b)?(a):(b))
#define Min(a,b)  ((a)<(b)?(a):(b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

//gcd lcm
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

const int maxn = 2020;
vector<PII> G[maxn];
int n, m;
int dist[maxn];
bool vis[maxn];
void add_edge(int u, int v, int d) {
    G[u].push_back(make_pair(v, d));
}

void spfa(int start, int n) {
    // clr(vis, 0), clr(dist, 0x3f);
    // for(int i = 0; i < n; i++)  printf("%d\n", dist[i]);
    for(int i = 0; i <= n; i++) {vis[i] = false;}
    for(int i = 0; i <= n; i++) {dist[i] = INF;}

    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        vis[cur] = false;
        for(int i = 0; i < (int)G[cur].size(); i++) {
            int v = G[cur][i].first;
            int d = G[cur][i].second;
            if(dist[v] > dist[cur] + d) {
                dist[v] = dist[cur] + d;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

    }
}

int main(int argc, char const *argv[]) {
// freopen("data.in","r",stdin);
// freopen("data.out","w",stdout);
    while(cin >> m >> n) {
        for(int i = 0; i <= n; i++)  G[i].clear();
        int u, v, d;
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> d;
            add_edge(u, v, d);
            add_edge(v, u, d);
        }

        spfa(1, n);
        cout << dist[n] << endl;
    }
    return 0;
}



