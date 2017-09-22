#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

char input[1000], t[1000], op[5];
int c[10];
struct Node {
  int s, p;
  Node() {}
  Node(int S, int P) { s = S, p = P; }
};
struct Path {
  int from, dir;
} path[400000];
int f[400000];

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string d[3] = {"", "udlr", "durl"};

queue<Node> q[3];
int ans;

stack<int> S;
queue<int> Q;

int getnum() {
  int res = 0;
  for (int i = 0; t[i]; i++)
    for (int j = i + 1; t[j]; j++)
      if (t[j] < t[i]) res = res + c[8 - i];
  return res;
}

void getstr(int val) {
  int tmp[10], flag[10];
  memset(flag, 0, sizeof flag);
  for (int i = 0; i < 9; i++) tmp[i] = val / c[8 - i], val = val % c[8 - i];
  for (int i = 0; i < 9; i++) {
    int num = 0;
    for (int j = 0; j < 9; j++) {
      if (flag[j] == 0) num++;
      if (num == tmp[i] + 1) {
        t[i] = j + '0' + 1;
        if (t[i] == '9') t[i] = 'x';
        flag[j] = 1;
        break;
      }
    }
  }
}

bool g(int a, int b) {
  if (a >= 0 && a <= 2 && b >= 0 && b <= 2) return 1;
  return 0;
}

void bfs(int now) {
  Node h = q[now].front();
  q[now].pop();
  int a = h.p / 3, b = h.p % 3;
  getstr(h.s);

  for (int i = 0; i < 4; i++) {
    int x = a + dir[i][0], y = b + dir[i][1];
    if (!g(x, y)) continue;
    int pos = 3 * x + y;

    swap(t[h.p], t[pos]);

    if (f[getnum()] == now) {
      swap(t[h.p], t[pos]);
      continue;
    } else if (f[getnum()] != 0) {
      ans = 1;
      if (now == 1) {
        S.push(i);
        int u = h.s;
        while (path[u].from != -1) {
          S.push(path[u].dir);
          u = path[u].from;
        }
        u = getnum();
        while (path[u].from != -1) {
          Q.push(path[u].dir);
          u = path[u].from;
        }
      } else {
        printf("%d   %d\n", h.s, getnum());
        Q.push(i);
        int u = h.s;
        while (path[u].from != -1) {
          Q.push(path[u].dir);
          u = path[u].from;
        }
        u = getnum();
        while (path[u].from != -1) {
          S.push(path[u].dir);
          u = path[u].from;
        }
      }
      break;
    } else {
      f[getnum()] = now;
      path[getnum()].from = h.s;
      path[getnum()].dir = i;
      q[now].push(Node(getnum(), pos));
      swap(t[h.p], t[pos]);
    }
  }
}

void read() {
  t[0] = op[0];
  for (int i = 1; i <= 8; i++) {
    scanf("%s", op);
    t[i] = op[0];
  }
  for (int i = 0; i <= 9; i++) input[i] = t[i];
}

void init() {
  memset(f, ans = 0, sizeof f);
  while (!q[1].empty()) q[1].pop();
  while (!q[2].empty()) q[2].pop();
}

void work(int s, int pos) {
  q[1].push(Node(s, pos));
  q[2].push(Node(0, 8));
  f[s] = 1;
  path[s].from = path[s].dir = -1;
  f[0] = 2;
  path[0].from = path[0].dir = -1;
  while ((!q[1].empty()) && (!q[2].empty())) {
    if (ans == 1) break;
    bfs(1);
    if (ans == 1) break;
    bfs(2);
    if (ans == 1) break;
  }
}

int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  c[0] = 1;
  for (int i = 1; i <= 8; i++) c[i] = c[i - 1] * i;
  while (~scanf("%s", op)) {
    read();

    int sum = 0;
    for (int i = 0; t[i]; i++) {
      if (t[i] == 'x') continue;
      for (int j = 0; j < i; j++) {
        if (t[j] == 'x') continue;
        if (t[i] < t[j]) sum++;
      }
    }

    if (sum % 2 == 1) {
      printf("unsolvable\n");
      continue;
    }
    init();
    for (int i = 0; i < 9; i++)
      if (input[i] == 'x') {
        work(getnum(), i);
        break;
      }
    if (ans == 1) {
      while (!S.empty()) {
        printf("%c", d[1][S.top()]);
        S.pop();
      }
      while (!Q.empty()) {
        printf("%c", d[2][Q.front()]);
        Q.pop();
      }
    } else
      printf("unsolvable");
    printf("\n");
  }
  return 0;
}
