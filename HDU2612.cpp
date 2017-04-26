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

<<<<<<< HEAD
//gcd lcm
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int r, c;
const int maxn = 220;
char grid[maxn][maxn];
int main(int argc, char const *argv[]) {
// freopen("data.in","r",stdin);
// freopen("data.out","w",stdout);
    for(int i = 0; i < r; i++) {
        scanf("%s", grid + i);
    }
    return 0;
}


=======
const int maxn = 205;
int r, c;
int ret;
char grid[maxn][maxn];
int dist[maxn][maxn][2];
bool vis[maxn][maxn];
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
inline bool canMove(int x, int y) {
	if (x < 0 || x >= r || y < 0 || y >= c || vis[x][y] || grid[x][y] == '#')  return false;
	return true;
}

void bfs(PII start, int who) {
	clr(vis, 0);
	dist[start.first][start.second][who] = 0;
	vis[start.first][start.second] = true;
	queue<PII> q;
	q.push(start);

	while (!q.empty()) {
		PII cur = q.front(); q.pop();
		int x = cur.first;
		int y = cur.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (canMove(nx, ny)) {
				dist[nx][ny][who] = dist[x][y][who] + 1;
				q.push(make_pair(nx, ny));
				vis[nx][ny] = true;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	while (scanf("%d%d", &r, &c) == 2) {
		clr(grid, 0), clr(dist, -1);
		for (int i = 0; i < r; i++) {
			scanf("%s", grid + i);
		}

		PII Y, M;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == 'Y') {
					Y.first = i;
					Y.second = j;
					break;
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == 'M') {
					M.first = i;
					M.second = j;
					break;
				}
			}
		}
		ret = INF;
		bfs(Y, 0);
		bfs(M, 1);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == '@' && dist[i][j][0] != -1 && dist[i][j][1] != -1) {
					ret = Min(ret, dist[i][j][0] + dist[i][j][1]);
				}
			}
		}
		printf("%d\n", ret * 11);
	}
	return 0;
}
>>>>>>> abd3086bf95cf68f0075b38f149d9a54cc622353
