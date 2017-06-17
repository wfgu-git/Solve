#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 22;
int row, col;
char g[maxn][maxn];
int sx, sy;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
bool vis[maxn][maxn];
int ans;
inline bool inside(int x, int y)
{
	if (x < 0 || x >= row || y < 0 || y >= col || g[x][y] != '.') return false;
	return true;
}
void dfs(int x, int y)
{
	++ans;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (!inside(tx, ty) || vis[tx][ty]) continue;
		dfs(tx, ty);	
	}
}
void fnd_start(int &x, int &y)
{
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (g[i][j] == '@') {
				x = i;
				y = j;
			}
		}
	}
}
int main()
{
	while (cin >> col >> row) {
		if (row == 0 && col == 0) break;
		for (int i = 0; i < row; i++) 
			for (int j = 0; j < col; j++) 
				cin >> g[i][j];	
		
		ans = 0;
		memset(vis, 0, sizeof(vis));
		fnd_start(sx, sy);
		dfs(sx, sy);
		cout << ans << endl;
	}
	return 0;
}
