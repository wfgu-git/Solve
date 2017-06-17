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

int s, m, n;
int cnt;
const int maxn = 105;
int dist[maxn][maxn][maxn];
struct cola {
    int v, curv;
    cola() {}
    cola(int _v, int _curv): v(_v), curv(_curv) {}
};
struct Node {
    cola v0, v1, v2;
    Node() {}
    Node(cola s, cola m, cola n): v0(s), v1(m), v2(n) {}
};

void pour(int &x, const int &v, int &cur) {
    if (!x)  return ;
    int left = v - cur;
    if (x >= left) {
        cur += left;
        x -= left;
    } else {
        cur += x;
        x = 0;
    }
}

int ret;
void bfs() {
    clr(dist, -1);
    //当前杯子中的水
    dist[s][0][0] = 0;
    queue<Node> q;
    q.push(Node(cola(s, s), cola(m, 0), cola(n, 0)));
    if (s & 1)  return;
    int target = s / 2;
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        //对于每一桶 都有两个选择  全部倒给另两个中的一个
        cola v[3];
        for (int i = 0; i < 3; i++) {
            v[0] = cur.v0, v[1] = cur.v1, v[2] = cur.v2;
            pour(v[i].curv, v[(i + 1) % 3].v, v[(i + 1) % 3].curv);
            if (dist[v[0].curv][v[1].curv][v[2].curv] == -1) {
                dist[v[0].curv][v[1].curv][v[2].curv] = dist[cur.v0.curv][cur.v1.curv][cur.v2.curv] + 1;

                if (v[0].curv == target)  {
                    ret = dist[v[0].curv][v[1].curv][v[2].curv];
                    return;
                }
                q.push(Node(cola(v[0].v, v[0].curv), cola(v[1].v, v[1].curv), cola(v[2].v, v[2].curv)));
            }
            //
            v[0] = cur.v0, v[1] = cur.v1, v[2] = cur.v2;
            pour(v[i].curv, v[(i + 2) % 3].v, v[(i + 2) % 3].curv);
            if (dist[v[0].curv][v[1].curv][v[2].curv] == -1) {
                dist[v[0].curv][v[1].curv][v[2].curv] = dist[cur.v0.curv][cur.v1.curv][cur.v2.curv] + 1;

                if (v[0].curv == target)  {
                    ret = dist[v[0].curv][v[1].curv][v[2].curv];
                    return;
                }

                q.push(Node(cola(v[0].v, v[0].curv), cola(v[1].v, v[1].curv), cola(v[2].v, v[2].curv)));
            }
        }
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(int argc, char const *argv[]) {
    while (~iscanf3(s, m, n) && (s + m + n)) {
        ret = INF;
        bfs();
        if (ret == INF)  printf("NO\n");
        else printf("%d\n", ret);
        // pour(s, m, n);
        // printf("%d %d %d\n", s, m, n);
    }
    return 0;
}
