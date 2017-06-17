#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 22;
const int inf = 0x3f3f3f3f;
int r, c;
int g[maxn][maxn];
int sx, sy, ex, ey;
int tot, ans;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int x, int y)
{
    if (tot >= 10) return;

	for (int i = 0; i < 4; i++) {
		int tx = x;
		int ty = y;
		const int dx = dir[i][0];
		const int dy = dir[i][1];

		while (true) {
			tx += dx;
			ty += dy;
			if (tx < 0 || tx >= r || ty < 0 || ty >= c) break;
			if (tx == ex && ty == ey) {
				tot++;
				ans = min(ans, tot);
				tot--;
				return;
			} else if (g[tx][ty] == 1) {
				if (tx == x + dx && ty == y + dy) break;
				g[tx][ty] = 0;
				tot++;
				dfs(tx - dx, ty - dy);
				tot--;
				g[tx][ty] = 1;
				break;
			}
		}
	}
}
inline void init(int &sx, int &sy, int &ex, int &ey)
{
    tot = 0;
    ans = inf;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j] == 2) {
                sx = i;
                sy = j;
            }
            if (g[i][j] == 3) {
                ex = i;
                ey = j;
            }
        }
    }
}
int main()
{
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);

    while (scanf("%d%d", &c, &r) == 2) {
        if (r == 0 && c == 0) break;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                scanf("%d", &g[i][j]);

        init(sx, sy, ex, ey);
        dfs(sx, sy);
		if (ans == inf) puts("-1");
		else printf("%d\n", ans);
    }
    return 0;
}


