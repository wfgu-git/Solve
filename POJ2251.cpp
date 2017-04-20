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
typedef priority_queue<int, vector<int>, greater<int>> pq_int;
typedef priority_queue<PII, vector<PII>, greater<PII>> pq_PII;
#define iscanf(a) scanf("%d",&a)
#define iscanf2(a,b) scanf("%d%d",&a,&b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
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
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int maxn = 35;
struct Node {
    int r, c, layer;
    Node() {}
    Node(int _l, int _r, int _c): r(_r), c(_c), layer(_l) {}
};
bool flag;
int ret;
int L, R, C;
char grid[maxn][maxn][maxn];
int dist[maxn][maxn][maxn];
//[level][row][column]
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int dl[] = {-1, 1};
// dl = -1  up
// dl =  1  down
bool canMove(int l, int r, int c) {
    if (l < 0 || l >= L || r < 0 || r >= R || c < 0 || c >= C)  return false;
    if (grid[l][r][c] == '#')  return false;
    return true;
}

Node findStart() {
    Node s;
    for (int l = 0; l < L; l++) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[l][r][c] == 'S') {
                    s.r = r, s.c = c, s.layer = l;
                    return s;
                }
            }
        }
    }
}

void Bfs() {
    clr(dist, -1);
    Node start = findStart();
    dist[start.layer][start.r][start.c] = 0;
    queue<Node> q;
    q.push(start);

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        int r = cur.r;
        int c = cur.c;
        int l = cur.layer;

        // up or down
        for (int i = 0; i < 2; i++) {
            int nl = l + dl[i];
            int nr = r;
            int nc = c;

            if (canMove(nl, nr, nc) == true && dist[nl][nr][nc] == -1) {
                dist[nl][nr][nc] = dist[l][r][c] + 1;
                if (grid[nl][nr][nc] == 'E') {
                    flag = true;
                    ret = dist[nl][nr][nc];
                    return ;
                }
                q.push(Node(nl, nr, nc));
            }
        }
        // the same layer
        for (int i = 0; i < 4; i++) {
            int nl = l;
            int nr = r + dr[i];
            int nc = c + dc[i];
            // printf("r = %d  c = %d  l = %d\n", nr, nc, nl);
            if (canMove(nl, nr, nc) == true && dist[nl][nr][nc] == -1) {
                dist[nl][nr][nc] = dist[l][r][c] + 1;
                // printf("row = %d  col = %d layer = %d  step = %d\n", nl, nr, nc, dist[nl][nr][nc]);
                if (grid[nl][nr][nc] == 'E') {
                    // printf("%d %d %d\n", nl, nr, nc);
                    flag = true;
                    ret = dist[nl][nr][nc];
                    return;
                }
                q.push(Node(nl, nr, nc));
            }
        }
    }// for

}// while


int main(int argc, char const *argv[]) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    while (iscanf3(L, R, C) == 3 && (L + R + C)) {
        clr(grid, -1);
        for (int l = 0; l < L; l++) {
            for (int r = 0; r < R; r++) {
                scanf("%s", grid[l][r]);
            }
        }

        flag = false;
        Bfs();
        if (!flag)  printf("Trapped!\n");
        else  printf("Escaped in %d minute(s).\n", ret);
    }
    return 0;
}

