#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;
const int maxn = 1000 + 10;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int n, m, maxv;
char g[maxn][maxn];
int dis[maxn][maxn];
pii p[15];
inline bool inside(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (g[x][y] == 'X') return false;
    return true;
}
int bfs(pii s, pii t) {
    memset(dis, -1, sizeof(dis));
    queue < pii > q;
    dis[s.first][s.second] = 0;
    q.push(s);

    int ans = 0;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (inside(tx, ty) && dis[tx][ty] == -1) {
                dis[tx][ty] = dis[x][y] + 1;
                if (tx == t.first && ty == t.second) {
                    ans = dis[tx][ty];
                    break;
                }
                q.push({tx, ty});
            }
        }
    }
    return ans;
}
void get_info() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' || g[i][j] == 'X') continue;
            if (g[i][j] == 'S') {
                p[0] = {i, j};
            } else if (g[i][j] >= '1' && g[i][j] <= '9') {
                p[g[i][j] - '0'] = {i, j};
            }
        }
    }
}
int main() {
    while (scanf("%d%d%d", &n, &m, &maxv) == 3) {
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }

        get_info();
        int ans = 0;
        for (int i = 0; i < maxv; i++) {
            ans += bfs(p[i], p[i + 1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

