#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
struct Node {
    int x, y;
    int step = -1;
    int used = 0;
};
Node start, target;
int n, m, k;
char pic[25][25];
bool vis[25][25][15];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void find_start()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pic[i][j] == 'S') {
                start.x = i, start.y = j;
                return ;
            }
        }
    }
}

void find_tar()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pic[i][j] == 'T') {
                target.x = i, target.y = j;
                return ;
            }
        }
    }
}

bool legal (Node u)
{
    if ( (u.x < 0 || u.x >= n || u.y < 0 || u.y >= m)
            || (vis[u.x][u.y][u.used] == true))  return false;
    return true;
}

void bfs()
{
    memset (vis, 0, sizeof (vis));
    find_start();
    find_tar();
    start.step = 0;
    start.used = 0;
    target.step = -1;
    queue<Node> q;
    q.push (start);
    vis[start.x][start.y][start.used] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        if (cur.x == target.x && cur.y == target.y && cur.used <= k)  {
            target.step = cur.step;
            return ;
        }
        for (int i = 0; i < 4; i++) {
            Node nxt;
            nxt.x = cur.x + dx[i], nxt.y = cur.y + dy[i], nxt.step = cur.step + 1, nxt.used = cur.used;
            if (legal (nxt)) {
                if (pic[nxt.x][nxt.y] == 'x') {
                    if (pic[cur.x][cur.y] == 'x')  continue;
                    else {
                        if (nxt.used < k)   ++nxt.used;
                        else continue;
                    }
                }
                vis[nxt.x][nxt.y][nxt.used] = true;
                q.push (nxt);
            }
        }
    }
}

int main (void)
{
    int t;
    cin >> t;
    while (t--) {
        memset (pic, 0, sizeof (pic));
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> pic[i][j];
            }
        }
        bfs();
        cout << target.step << endl;
    }
    return 0;
}
