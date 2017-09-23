/*
教练我要打ACM!
*/
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;

struct node {
  int state, pos, f, g, h;
  bool operator < (const node& rhs) const {
    return f > rhs.f;
  }
} ;
struct path {
  int pre, dir;
} fa[maxn];
char str[20], buf[2], buffer[20];
int fact[10];
int g[maxn];
int mark[maxn];
priority_queue<node> Q;
stack<int> S;
string dir = "udlr";
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int cantor() {
  int ret = 0;
  for (int i = 0; i < 9; ++i) {
    int cont = 0;
    for (int j = i + 1; j < 9; ++j) {
      if (str[i] > str[j]) {
        ++cont;
      }
    }
    ret += cont * fact[9 - i - 1];
  }
  return ret;
}
void decantor(int state) {
  vector<int> left;
  for (int i = 1; i <= 9; ++i) {
    left.push_back(i);
  }
  for (int i = 0; i < 9; ++i) {
    int r = state % fact[9 - i - 1];
    int t = state / fact[9 - i - 1];
    state = r;
    sort(left.begin(), left.end());
    str[i] = '0' + left[t];
    str[i] = (str[i] == '9' ? 'x' : str[i]);
    left.erase(left.begin() + t);
  }
}
int h(int state) {
  memcpy(buffer, str, sizeof(buffer));
  decantor(state);
  int ret = 0;
  int num, x1, y1, x2, y2;
  for (int i = 0; i < 9; ++i) {
    if (str[i] == 'x') {
      continue;
    }
    num = str[i] - '0' - 1;
    x1 = i / 3;
    y1 = i % 3;
    x2 = num / 3;
    y2 = num % 3;
    ret += abs(x1 - x2) + abs(y1 - y2);
  }
  memcpy(str, buffer, sizeof(buffer));
  return ret;
}
bool check(int x, int y) {
  if (x < 0 || x > 2 || y < 0 || y > 2) return 0;
  return 1;
}
void Astar(int state, int pos) {
  memset(g, -1, sizeof(g));
  memset(mark, 0, sizeof(mark));
  while (!Q.empty()) Q.pop();
  while (!S.empty()) S.pop();

  mark[state] = 2;
  g[state] = 0;
  fa[state] = {-1, -1};
  Q.push({state, pos, 0 + h(state), 0, h(state)});
  while (!Q.empty()) {
    node now = Q.top(); Q.pop();
    decantor(now.state);

    if (now.state == 0) {
      int cur = now.state;
      while (true) {
        if (fa[cur].pre == -1) break;
        S.push(fa[cur].dir);
        cur = fa[cur].pre;
      }
      break;
    }

    int tx, ty, ts, tp;
    int x = now.pos / 3;
    int y = now.pos % 3;
    for (int i = 0; i < 4; ++i) {
      tx = x + dx[i];
      ty = y + dy[i];
      if (!check(tx, ty)) {
        continue;
      }
      tp = 3 * tx + ty;
      swap(str[tp], str[now.pos]);
      ts = cantor();
      swap(str[tp], str[now.pos]);
      if (!mark[ts] || (mark[ts] == 1 && g[ts] > now.g + 1)) {
        mark[ts] = 1;
        g[ts] = now.g + 1;
        fa[ts] = {now.state, i};
        int th = h(ts);
        Q.push({ts, tp, g[ts] + th, g[ts], th});
      }
    }
  }
  while (!S.empty()) {
    putchar(dir[S.top()]);
    S.pop();
  }
  printf("\n");
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);

  fact[0] = 1;
  for (int i = 1; i < 9; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  while (~scanf("%s", buf)) {
    str[0] = buf[0];
    for (int i = 1; i < 9; ++i) {
      scanf("%s", buf);
      str[i] = buf[0];
    }

    int sum = 0;
    for (int i = 0; str[i]; i++) {
      if (str[i] == 'x') continue;
      for (int j = 0; j < i; j++) {
        if (str[j] == 'x') continue;
        if (str[i] < str[j]) sum++;
      }
    }
    if (sum & 1) {
      puts("unsolvable");
      continue;
    }

    int state = cantor();
    int pos;
    for (int i = 0; i < 9; ++i) {
      if (str[i] == 'x') {
        pos = i;
      }
    }
    Astar(state, pos);
  }
}
