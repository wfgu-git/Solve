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

//
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int grid[5][5];
int dist[5][5];
PII pre[5][5];

bool inside(int x, int y) {
    return !(x < 0 || x >= 5 || y < 0 || y >= 5);
}

void Bfs() {
    clr(dist, -1);
    queue<PII> q;
    dist[0][0] = 0;
    q.push(mp(0, 0));
    while(!q.empty()) {
        PII cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(inside(nx, ny) && dist[nx][ny] == -1 && grid[nx][ny] == 0) {
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                pre[nx][ny] = cur;
                if(nx == 4 && ny == 4) return;
                q.push(mp(nx, ny));
            }
        }
    }
}

void Print_path(int x, int y) {
    if(x == 0 && y == 0) {
        printf("(%d, %d)\n", x, y);
        return;
    }
    Print_path(pre[x][y].first, pre[x][y].second);
    printf("(%d, %d)\n", x, y);
}

int main() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            iscanf(grid[i][j]);
        }
    }
    Bfs();
    Print_path(4, 4);
    //system("pause");
    return 0;
}