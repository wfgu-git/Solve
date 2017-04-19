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

const int maxn = 5;
bool vis[maxn];
ll dist[maxn];
ll grid[maxn][maxn];
// grid[i][j]
// the money need  from j to i  (%4)
void Spfa(int start) {
    clr(vis, 0);
    for (int i = 0; i < maxn; i++) {
        dist[i] = (i == start ? 0 : INF);
    }

    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vis[cur] = false;
        for (int i = 0; i < 4; i++) {
            if (grid[cur][i] && grid[cur][i] + dist[cur] < dist[i]) {
                dist[i] = grid[cur][i] + dist[cur];
                if (!vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
    }
}
int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    int t;
    iscanf(t);
    while (t--) {
        clr(grid, 0);
        int n, a, b, c;
        scanf("%d%d%d%d", &n, &a, &b, &c);
        if (n % 4 == 0) {
            printf("0\n");
            continue;
        }
        grid[0][1] = c, grid[1][2] = c, grid[2][3] = c;
        grid[0][2] = b, grid[1][3] = b, grid[3][1] = b;
        grid[0][3] = a, grid[3][2] = a, grid[2][1] = a;
        Spfa(0);
        printf("%lld\n", dist[n % 4]);
    }
    return 0;
}