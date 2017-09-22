/*
教练我要打ACM!
*/
// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;

// tree<pii, null_type, greater<pii>, rb_tree_tag, tree_order_statistics_node_update> trees[maxn];
// tree<pii, null_type, greater<pii>, splay_tree_tag, tree_order_statistics_node_update> trees[maxn];
// tree<pii, null_type, greater<pii>, ov_tree_tag, tree_order_statistics_node_update> trees[maxn];

char raw[2];
char str[20];
int fact[10];
bool vis[maxn];
string dir = "udlr";
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct node {
  int state, pos;
  node(int _s, int _p) : state(_s), pos(_p) {}
} ;

struct path {
  int pre, next;
} fa[maxn];

int cantor() {
  int ret = 0;
  for (int i = 0; i < 9; ++i) {
    int cont = 0;
    for (int j = i + 1; j < 9; ++j) {
      if (str[j] < str[i]) {
        cont++;
      }
    }
    ret += cont * fact[9 - i - 1];
  }
  return ret;
}

void decantor(int state) {
  vector<int> left;
  vector<int> ret;
  for (int i = 1; i <= 9; ++i) {
    left.push_back(i);
  }
  --state;
  for (int i = 9; i >= 1; --i) {
    int r = state % fact[i - 1];
    int t = state / fact[i - 1];
    state = r;
    sort(left.begin(), left.end());
    ret.push_back(left[t]);
    left.erase(left.begin() + t);
  }
  for (int i = 0; i < ret.size(); ++i) {
    str[i] = '0' + ret[i];
    str[i] = (str[i] == '9' ? 'x' : str[i]);
  }
  puts(str);
}
bool check(int x, int y) {
  if (x < 0 || x >  2 || y < 0 || y > 2) return 0;
  return 1;
}
void BFS(int state, int pos) {
  vector<int> ret;
  memset(vis, 0, sizeof(vis));
  queue<node> Q;
  Q.push({state, pos});
  vis[state] = 1;
  fa[state] = {-1, -1};

  while (!Q.empty()) {
    node now = Q.front(); Q.pop();

    if (now.state == 0) {
      int cur = now.state;
      for ( ; ; ) {
        if (fa[cur].pre == -1) {
          break;
        }
        ret.push_back(fa[cur].next);
        cur = fa[cur].pre;
      }
      break;
    }

    decantor(now.state);
    int x, y, tx, ty;
    x = now.pos / 3;
    y = now.pos % 3;
    for (int i = 0; i < 4; ++i) {
      tx = x + dx[i];
      ty = y + dy[i];
      if (!check(tx, ty)) continue;
      int tp = 3 * tx + ty;
      swap(str[tp], str[now.pos]);
      int ts = cantor();
      if (vis[ts]) {
        swap(str[tp], str[now.pos]);
        continue;
      }
      fa[ts] = {now.state, i};
      vis[ts] = 1;
      Q.push({ts, tp});
      swap(str[tp], str[now.pos]);
    }
  }

  for (vector<int>::reverse_iterator it = ret.rbegin(); it != ret.rend(); ++it) {
    putchar(dir[*it]);
  }
}
void read() {
  str[0] = raw[0];
  for (int i = 1; i < 9; ++i) {
    scanf("%s", raw);
    str[i] = raw[0];
  }
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < 9; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  while (~scanf("%s", raw)) {
    read();
    int state = cantor();
    int pos;
    for (int i = 0; i < 9; ++i) {
      if (str[i] == 'x') {
        pos = i;
        break;
      }
    }
    // int pos = raw.find('x');

    // special judge
    int sum = 0;
    for (int i = 0; str[i]; ++i) {
      if (str[i] == 'x') {
        continue;
      }
      for (int j = 0; j < i; ++j) {
        if (str[j] == 'x') {
          continue;
        }
        if (str[i] < str[j]) {
          ++sum;
        }
      }
    }

    if (sum % 2 == 1) {
      printf("%s\n", "unsolvable");
      continue;
    }

    BFS(state, pos);
  }
  return 0;
}
