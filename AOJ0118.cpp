#include <bits/stdc++.h>
using namespace std;

const int maxn = 102;
int row, col;
char g[maxn][maxn];
inline bool inside(int x, int y)
{
	if (x < 0 || x >= row || y < 0 || y >= col || g[x][y] == 'o') 
		return false;

	return true;
}
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
void dfs(const int &x, const int &y, char t)
{
	g[x][y] = 'o';
	for (int i = 0; i < 4; i++){
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (!inside(tx, ty)) continue;
		if (g[tx][ty] == t)
			dfs(tx, ty, t);
	}	
}
int main()
{
	ios::sync_with_stdio(false);

	while (cin >> row >> col) {
		if (row == 0 && col == 0) break;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				cin >> g[i][j];

		int ans = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (g[i][j] != 'o') {
					ans++;
					dfs(i, j, g[i][j]);
				}
			}
		}
		cout << ans << endl;
	}	
	return 0;
}
