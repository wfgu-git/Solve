#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
char g[2][maxn][maxn];
struct Node{
    int x, y, layer, step;
    Node(){}
    Node(int _x, int _y, int _layer, int _step = -1)
        : x(_x), y(_y), layer(_layer), step(_step){}
    bool operator > (const Node &rhs) const {
        return step > rhs.step;
    }
};
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
bool vis[2][maxn][maxn];
int n, m;
bool can_move(int x, int y, int l)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    if(vis[l][x][y] == true || g[l][x][y] == '*') return false;
    return true;
}
bool bfs(const int &t)
{
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    q.push(Node(0, 0, 0, 0));
    vis[0][0][0] = true;

    //cout << "start " << start.x << " " << start.y << " " << start.layer << endl;
    while(!q.empty()){
        Node cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int tx = cur.x + dx[i];
            int ty = cur.y + dy[i];
            int tstep = cur.step + 1;
            int tlayer = cur.layer;
            if(tstep > t) break;
            if( !can_move(tx, ty, tlayer) ) continue;
            if(g[tlayer][tx][ty] == '#'){
                if(g[tlayer ^ 1][tx][ty] == 'P' || g[tlayer ^ 1][tx][ty] == '.')
                    tlayer ^= 1;
                else
                    continue;
            }
            if(g[tlayer][tx][ty] == 'P'){
                //cout << "Need " << tstep << endl;
                return tstep <= t;
            }
            Node tnode(tx, ty, tlayer, tstep);
            vis[tlayer][tx][ty] = true;
            //cout << "next  the " << tlayer << " layer " << tx << ", " << ty << " " << tstep << endl;
            q.push(tnode);
        }
    }
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(g, 0, sizeof(g));
        int tt;
        scanf("%d%d%d", &n, &m, &tt);
        for(int lyr = 0; lyr < 2; lyr++){
            for(int i = 0; i < n; i++){
                scanf("%s", g[lyr][i]);
            }
        }

        if(bfs(tt)) puts("YES");
        else puts("NO");
    }
    return 0;
}
