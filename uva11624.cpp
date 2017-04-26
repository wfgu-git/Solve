/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
// typedef __int64 i64;
typedef unsigned long long ull;
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a, b) scanf("%d%d", &a, &b)
#define iscanf3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define mo(a, b) (((a) % (b) + (b)) % (b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) \
    sort(all(x)); \
    v.erase(unique(all(v)), end())
#define mp(a, b) make_pair(a, b)
#define clr(x, i) memset(x, i, sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l, m, rt << 1
#define rch m + 1, r, rt << 1 | 1
#define rep(i, x, n) for (int i = x; i < n; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int maxn = 1010;
int r, c;
char grid[maxn][maxn];
int stepF[maxn][maxn];
int stepJ[maxn][maxn];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<PII> q;
inline bool inside(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == '#') return false;
    return true;
}
void bfsf() {
    clr(stepF, -1);
    while (!q.empty()) q.pop();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'F') {
                q.push(make_pair(i, j));
                stepF[i][j] = 0;
            }
        }
    }
    // bfs
    while (!q.empty()) {
        PII cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!inside(nx, ny)) continue;
            if (stepF[nx][ny] != -1) continue;
            stepF[nx][ny] = stepF[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}
int bfsJ() {
    clr(stepJ, -1);
    while (!q.empty()) q.pop();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'J') {
                q.push(make_pair(i, j));
                stepJ[i][j] = 0;
            }
        }
    }
    // solve
    while (!q.empty()) {
        PII cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        if (x == 0 || x == r - 1 || y == 0 || y == c - 1)
            return stepJ[x][y] + 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!inside(nx, ny)) continue;
            if (stepJ[nx][ny] != -1) continue;
            if (stepF[nx][ny] != -1 && stepJ[x][y] + 1 >= stepF[nx][ny])
                continue;
            stepJ[nx][ny] = stepJ[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    return -1;
}
int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; i++) {
            scanf("%s", &grid[i]);
        }
        bfsf();
        int ret = bfsJ();
        if (ret == -1) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", ret);
        }
    }
    return 0;
}
