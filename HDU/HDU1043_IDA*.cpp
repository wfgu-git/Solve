/*
教练我要打ACM!
*/
// #include <bits/stdc++.H>
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



char str[10], buf[5], buffer[10], input[10];
int fact[10];
int length, flag, limit;
int path[1000];
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
vector<int> left;
void decantor(int state) {
  left.clear();
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
int H(int state) {
  // memcpy(buffer, str, sizeof(buffer));
  for (int i = 0; i <= 9; ++i) buffer[i] = str[i];
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
  // memcpy(str, buffer, sizeof(buffer));
  for (int i = 0; i <= 9; ++i) str[i] = buffer[i];
  return ret;
}
bool check(int x, int y) {
  if (x < 0 || x > 2 || y < 0 || y > 2) return 0;
  return 1;
}
void dfs(int pos, int state, int depth, int pre_dir) {
  if (state == 0) {
    length = depth;
    flag = 1;
    return;
  }
  if (depth + H(state) > limit) {
    return;
  }

  decantor(state);
  // memcpy(buffer, str, sizeof(str));
  for (int i = 0; i <= 9; ++i) buffer[i] = str[i];
  int x = pos / 3;
  int y = pos % 3;
  int tx, ty, ts, tp;
  for (int i = 0; i < 4; ++i) {
    if ((pre_dir ^ 1) == i) continue;
    tx = x + dx[i];
    ty = y + dy[i];
    if (!check(tx, ty)) {
      continue;
    }
    tp = 3 * tx + ty;
    swap(buffer[tp], buffer[pos]);
    // memcpy(str, buffer, sizeof(buffer));
    for (int i = 0; i <= 9; i++) str[i] = buffer[i];
    ts = cantor();
    path[depth] = i;
    dfs(tp, ts, depth + 1, i);
    if (flag) {
      return;
    }
    swap(buffer[tp], buffer[pos]);
  }
}
void read() {
  str[0] = buf[0];
  for (int i = 1; i < 9; ++i) {
    scanf("%s", buf);
    str[i] = buf[0];
  }
  for (int i = 0; i <= 9; ++i) {
    input[i] = str[i];
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);

  fact[0] = 1;
  for (int i = 1; i < 9; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  while (~scanf("%s", buf)) {
    read();
    int sum = 0;
    for (int i = 0; i < 9; i++) {
      if (str[i] == 'x') continue;
      for (int j = 0; j < i; j++) {
        if (str[j] == 'x') continue;
        if (str[i] < str[j]) sum++;
      }
    }
    if (sum %2 ==  1) {
      printf("unsolvable\n" );
      continue;
    }

    int sp;
    for (int i = 0; i < 9; ++i) {
      if (input[i] == 'x') {
        sp = i;
      }
    }
    limit = H(cantor());
    flag = 0;
    while (!flag) {
      // memcpy(str, input, sizeof(input));
      for (int i = 0; i <= 9; ++i) str[i] = input[i];
      int ss = cantor();
      dfs(sp, ss, 0, -1);
      if (flag) {
        break;
      }
      limit++;
    }
    for (int i = 0; i < length; ++i) {
      putchar(dir[path[i]]);
    }
    puts("");
  }
}
