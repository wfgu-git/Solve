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

const int maxn = 20;
int row, col;
int step;
int grid[maxn][maxn], ret[maxn][maxn], temp[maxn][maxn];
int dx[] = { -1, 1, 0, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

bool inside(int x, int y) {
	return !(x < 0 || x >= row || y < 0 || y >= col);
}

void filp(int x, int y) {
	for(int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(inside(nx, ny)) {
			grid[nx][ny] = !grid[nx][ny];
		}
	}
}

bool cmp() {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(temp[i][j] != ret[i][j]) {
				return ret[i][j] < temp[i][j];
			}
		}
	}
}

void dfs(int cur, int cnt) {
	// dfs at the last layer --> check the last layer
	if(cur == row) {
		// copy the data of this situation
		int cntCopy = cnt;
		int gridCopy[maxn][maxn];
		int retCopy[maxn][maxn];
		memcpy(gridCopy, grid, sizeof(gridCopy));
		memcpy(retCopy, ret, sizeof(retCopy));

		for(int i = 1; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(grid[i - 1][j] == 1) {
					filp(i, j);
					cnt++;
					ret[i][j]++;
				}
			}
		}

		// cnt > last situation
		if(cnt > step) {
			cnt = cntCopy;
			memcpy(grid, gridCopy, sizeof(grid));
			memcpy(ret, retCopy, sizeof(ret));
			return;
		}
		// check the last layer
		bool flag = true;
		for(int i = 0; i < col; i++) {
			if(grid[row - 1][i] == 1) {
				flag = false;
			}
		}
		// less step or dict sort
		if(flag && (cnt < step || cmp())) {
			step = cnt;
			memcpy(temp, ret, sizeof(temp));
		}
		// back
		cnt = cntCopy;
		memcpy(grid, gridCopy, sizeof(grid));
		memcpy(ret, retCopy, sizeof(ret));
		return;
	}
	// to try filp each piece of the first layer
	filp(0, cur);
	ret[0][cur]++;
	dfs(cur + 1, cnt + 1);
	ret[0][cur]--;
	filp(0, cur);  // filp twice  == init
	dfs(cur + 1, cnt);
}

int main(int argc, char const *argv[]) {
// freopen("data.in","r",stdin);
// freopen("data.out","w",stdout);
	while(scanf("%d%d", &row, &col) == 2) {
		// init and input
		clr(grid, 0), clr(ret, 0), clr(temp, 0);
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				scanf("%d", &grid[i][j]);
			}
		}

		// solve
		step = INF;
		dfs(0, 0);
		// print the ret
		if(step == INF) {
			printf("IMPOSSIBLE\n");
		} else {
			for(int i = 0; i < row; i++) {
				if(i)	printf("\n");
				for(int j = 0; j < col; j++) {
					if(j)  printf(" ");
					printf("%d", temp[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}


