/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;

struct node {
  int state, pos;
} ;
struct path {
  int pre, dir;
} fa[maxn];
string dir_go = "udlr";
string dir_back = "durl";
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char buf[2];
char str[20];
int fact[10];
int mark[maxn];
int flag;
queue<node> go, back;
queue<int> Que;
stack<int> S;
int cantor() {
  int ret = 0;
  for (int i = 0; i < 9; ++i) {
    int cont = 0;
    for (int j = i + 1; j < 9; ++j) {
      if (str[j] < str[i]) {
        ++cont;
      }
    }
    ret += cont * fact[9 - i - 1];
  }
  return ret;
}
void decantor(int state) {
  if (state == 0) {
    for (int i = 0; i < 9; ++i) {
      str[i] = '1' + i;
    }
    str[8] = 'x';
    return;
  }
  vector<int> left;
  for (int i = 1; i <= 9; ++i) {
    left.push_back(i);
  }
  // --state;
  for (int i = 0; i < 9; ++i) {
    int r = state % fact[9 - i -  1];
    int t = state / fact[9 - i - 1];
    state = r;
    sort(left.begin(), left.end());
    str[i] = '0' + left[t];
    str[i] = (str[i] == '9' ? 'x' : str[i]);
    left.erase(left.begin() + t);
  }
}
bool check(int x, int y) {
  if (x < 0 || x > 2 || y < 0 || y > 2) return 0;
  return 1;
}
void read() {
  str[0] = buf[0];
  for (int i = 1; i < 9; ++i) {
    scanf("%s", buf);
    str[i] = buf[0];
  }
}
void BFS(queue<node>& Q, int k) {
  node now = Q.front(); Q.pop();
  int x, y, tx, ty, tp, ts;
  x = now.pos / 3;
  y = now.pos % 3;
  decantor(now.state);

  for (int i = 0; i < 4; ++i) {
    tx = x + dx[i];
    ty = y + dy[i];
    if (!check(tx, ty)) {
      continue;
    }
    tp = 3 * tx + ty;
    swap(str[tp], str[now.pos]);
    if (mark[cantor()] == k) {
      swap(str[tp], str[now.pos]);
      continue;
    } else if (mark[cantor()] != -1) {
      flag = 1;
      if (k == 0) {
        S.push(i);
        int cur = now.state;
        while (fa[cur].pre != -1) {
          S.push(fa[cur].dir);
          cur = fa[cur].pre;
        }
        cur = cantor();
        while (fa[cur].pre != -1) {
          Que.push(fa[cur].dir);
          cur = fa[cur].pre;
        }
      } else {
        Que.push(i);
        int cur = now.state;
        while (fa[cur].pre != -1) {
          Que.push(fa[cur].dir);
          cur = fa[cur].pre;
        }
        cur = cantor();
        while (fa[cur].pre != -1) {
          S.push(fa[cur].dir);
          cur = fa[cur].pre;
        }
      }
      return;
    } else {
      ts = cantor();
      mark[ts] = k;
      fa[ts] = {now.state, i};
      Q.push({ts, tp});
      swap(str[tp], str[now.pos]);
    }
  }
}
void solve(int state, int pos) {
  flag = 0;
  while (!go.empty()) go.pop();
  while (!back.empty()) back.pop();
  go.push({state, pos});
  back.push({0, 8});
  memset(mark, -1, sizeof(mark));
  mark[state] = 0;
  mark[0] = 1;
  fa[state] = {-1, -1};
  fa[0] = {-1, -1};
  while ((!go.empty()) && (!back.empty())) {
    if (flag) {
      break;
    }
    BFS(go, 0);
    if (flag) {
      break;
    }
    BFS(back, 1);
    if (flag) {
      break;
    }
  }
  while (!S.empty()) {
    putchar(dir_go[S.top()]);
    S.pop();
  }
  while (!Que.empty()) {
    putchar(dir_back[Que.front()]);
    Que.pop();
  }
  puts("");
}
void init() {
  fact[0] = 1;
  for (int i = 1; i < 9; ++i) {
    fact[i] = fact[i - 1] * i;
  }
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  init();
  while (~scanf("%s", buf)) {
    read();
    int sum = 0;
    for (int i = 0; i < 9; ++i) if (str[i] != 'x') {
      for (int j = 0; j < i; ++j) {
        if (str[j] != 'x' && str[i] < str[j]) {
          sum++;
        }
      }
    }
    if (sum & 1) {
      puts("unsolvable");
      continue;
    }

    int state = cantor(), pos;
    for (int i = 0; i < 9; ++i) {
      if (str[i] == 'x') {
        pos = i;
      }
    }
    solve(state, pos);
  }
}
