/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
// typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a, b) scanf("%d%d", &a, &b)
#define iscanf3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define mo(a, b) (((a) % (b) + (b)) % (b))
#define all(x) (x).begin(), (x).end()
#define mp(a, b) make_pair(a, b)
#define clr(x, i) memset(x, i, sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l, m, rt << 1
#define rch m + 1, r, rt << 1 | 1
#define rep(i, x, n) for (int i = x; i < n; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int maxn = 105;
// start --> 1
// fill --> 100 / -100
// drop --> 5 / -5
// pour --> 1-->2 12
// pour --> 2-->1 21
int path[maxn][maxn];
int dist[maxn][maxn];
PII pre[maxn][maxn];
int a, b, c;
bool canVisited(int x, int y) {
    if(x < 0 || x > a || y < 0 || y > b || dist[x][y] != -1) return false;
    return true;
}
void pour(int &x, int &y, int v) {
    if(!x)  return;
    if(x + y <= v) {
        y += x;
        x = 0;
    } else {
        x = x - (v - y);
        y = v;
    }
}
void print_path(int x, int y) {
    if(x == 0 && y == 0) return;
    print_path(pre[x][y].first, pre[x][y].second);
    if(path[x][y] == 100)
        printf("FILL(1)\n");
    else if(path[x][y] == -100)
        printf("FILL(2)\n");
    else if(path[x][y] == 5)
        printf("DROP(1)\n");
    else if(path[x][y] == -5)
        printf("DROP(2)\n");
    else if(path[x][y] == 12)
        printf("POUR(1,2)\n");
    else if(path[x][y] == 21)
        printf("POUR(2,1)\n");
}
void bfs() {
    clr(path, 0), clr(pre, 0), clr(dist, -1);
    dist[0][0] = 0;
    path[0][0] = 1;
    queue<PII> q;
    q.push(make_pair(0, 0));

    while(!q.empty()) {
        PII cur = q.front();
        q.pop();
        int aa, bb;
        aa = cur.first;
        bb = cur.second;
        if(aa == c || bb == c) {
            printf("%d\n", dist[aa][bb]);
            print_path(aa, bb);
            return;
        }
        // fill a
        aa = a, bb = cur.second;
        if(canVisited(aa, bb)) {
            path[aa][bb] = 100;
            dist[aa][bb] = dist[cur.first][cur.second] + 1;
            pre[aa][bb] = make_pair(cur.first, cur.second);
            q.push(make_pair(aa, bb));
        }
        // fill b
        bb = b, aa = cur.first;
        if(canVisited(aa, bb)) {
            path[aa][bb] = -100;
            dist[aa][bb] = dist[cur.first][cur.second] + 1;
            pre[aa][bb] = make_pair(cur.first, cur.second);
            q.push(make_pair(aa, bb));
        }
        // drop a
        aa = 0, bb = cur.second;
        if(canVisited(aa, bb)) {
            path[aa][bb] = 5;
            dist[aa][bb] = dist[cur.first][cur.second] + 1;
            pre[aa][bb] = make_pair(cur.first, cur.second);
            q.push(make_pair(aa, bb));
        }
        // drop b
        bb = 0, aa = cur.first;
        if(canVisited(aa, bb)) {
            path[aa][bb] = -5;
            dist[aa][bb] = dist[cur.first][cur.second] + 1;
            pre[aa][bb] = make_pair(cur.first, cur.second);
            q.push(make_pair(aa, bb));
        }
        // pour a-->b
        aa = cur.first, bb = cur.second;
        pour(aa, bb, b);
        if(canVisited(aa, bb)) {
            path[aa][bb] = 12;
            dist[aa][bb] = dist[cur.first][cur.second] + 1;
            pre[aa][bb] = make_pair(cur.first, cur.second);
            q.push(make_pair(aa, bb));
        }
        // pour b-->a
        aa = cur.first, bb = cur.second;
        pour(bb, aa, a);
        if(canVisited(aa, bb)) {
            path[aa][bb] = 21;
            dist[aa][bb] = dist[cur.first][cur.second] + 1;
            pre[aa][bb] = make_pair(cur.first, cur.second);
            q.push(make_pair(aa, bb));
        }
        // all possible operator is above
    }  // end of while
    printf("impossible\n");
}

int main(int argc, char const *argv[]) {
    while(scanf("%d%d%d", &a, &b, &c) == 3) {
        bfs();
    }
    return 0;
}