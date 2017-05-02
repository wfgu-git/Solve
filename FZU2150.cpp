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
// #define UNIQUE(v) \
//   sort(all(x));   \
//   v.erase(unique(all(v)), end())
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

// gcd lcm
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

const int maxn = 11;
int t, r, c, ret;
char grid[maxn][maxn];
char temp[maxn][maxn];
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int step[maxn][maxn];
int fired[maxn][maxn][maxn];  // (i, j, t)
PII start[500];
// map<pair<PII, PII>, bool> s;
bool firedAll() {
  int flag = true;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(temp[i][j] == '#') {
        flag = false;
        break;
      }
    }
    if(!flag) break;
  }
  return flag ? true : false;
}
int cntTime() {
  int cnt = -INF;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(temp[i][j] == '@') cnt = Max(cnt, step[i][j]);
    }
  }
  return cnt;
}
bool canFire(int x, int y) {
  if(x < 0 || x >= r || y < 0 || y >= c || step[x][y] != -1 ||
      temp[x][y] == '.')
    return false;
  return true;
}
int bfs(int x1, int y1, int x2, int y2) {
  clr(step, -1);
  memcpy(temp, grid, sizeof(temp));
  temp[x1][y1] = temp[x2][y2] = '@';
  step[x1][y1] = step[x2][y2] = 0;
  queue<PII> q;
  q.push(make_pair(x1, y1));
  q.push(make_pair(x2, y2));
  int cnt = 0;
  // if (firedAll()) return cntTime();
  while(!q.empty()) {
    PII cur = q.front();
    q.pop();
    int x = cur.first;
    int y = cur.second;
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(!canFire(nx, ny)) continue;
      // printf("at this step!!!\n");
      temp[nx][ny] = '@';
      step[nx][ny] = step[x][y] + 1;
      cnt = Max(cnt, step[nx][ny]);
      q.push(make_pair(nx, ny));
    }
  }
  if(firedAll() == true)
    return cnt;
  else
    return INF;
}
int main(int argc, char const *argv[]) {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  int kase = 0;
  scanf("%d", &t);
  while(t--) {
    // s.clear();
    clr(start, -1);
    scanf("%d%d", &r, &c);
    for(int i = 0; i < r; i++) {
      scanf("%s", grid + i);
    }
    // find all '#'
    int tot = 0;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(grid[i][j] == '#') {
          start[tot++] = make_pair(i, j);
        }
      }
    }
    // solve by bfs
    ret = INF;
    for(int i = 0; i < tot; i++) {
      for(int j = i; j < tot; j++) {
        // if (s.count(make_pair(start[i], start[j]))) continue;
        // s[make_pair(start[i], start[j])] = 1;
        // s[make_pair(start[j], start[i])] = 1;
        ret = Min(ret, bfs(start[i].first, start[i].second, start[j].first,
                           start[j].second));
      }
    }
    // print the ret
    if(ret == INF) {
      printf("Case %d: %d\n", ++kase, -1);
    } else {
      printf("Case %d: %d\n", ++kase, ret);
    }
  }
  return 0;
}