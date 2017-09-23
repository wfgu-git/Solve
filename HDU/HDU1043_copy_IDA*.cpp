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

char input[10], str[10], buf[2];
char buffer[10];
int fact[10];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
string dir = "udlr";
int flag, limit, length;
int path[1000];
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

bool check(int a, int b) {
  if (a >= 0 && a <= 2 && b >= 0 && b <= 2) return 1;
  return 0;
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

void dfs(int pos, int s, int deep, int pre_dir) {
  if (s == 0) {
    length = deep;
    flag = 1;
    return;
  }
  if (deep + H(s) > limit) return;

  decantor(s);
  for (int i = 0; i <= 9; i++) buffer[i] = str[i];

  int x = pos / 3, y = pos % 3;
  for (int i = 0; i < 4; i++) {
    if ((pre_dir ^ 1) == i) continue;
    // if (pre_dir == 0 && i == 1) continue;
    // if (pre_dir == 1 && i == 0) continue;
    // if (pre_dir == 2 && i == 3) continue;
    // if (pre_dir == 3 && i == 2) continue;

    int tx = x + dx[i];
    int ty = y + dy[i];
    if (!check(tx, ty)) continue;

    int tp = 3 * tx + ty;

    swap(buffer[pos], buffer[tp]);
    for (int i = 0; i <= 9; i++) str[i] = buffer[i];
    int ts = cantor();
    path[deep] = i;
    dfs(tp, ts, deep + 1, i);
    if (flag) return;
    swap(buffer[pos], buffer[tp]);
  }
}
void read() {
  str[0] = buf[0];
  for (int i = 1; i < 9; i++) {
    scanf("%s", buf);
    str[i] = buf[0];
  }
  for (int i = 0; i <= 9; i++) input[i] = str[i];
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  fact[0] = 1;
  for (int i = 1; i < 9; i++) {
    fact[i] = fact[i - 1] * i;
  }
  while (~scanf("%s", buf)) {
    read();
    int sum = 0;
    for (int i = 0; str[i]; i++) {
      if (str[i] == 'x') continue;
      for (int j = 0; j < i; j++) {
        if (str[j] == 'x') continue;
        if (str[i] < str[j]) sum++;
      }
    }

    if (sum % 2 == 1) {
      printf("unsolvable\n");
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
    for (int i = 0; i < limit; ++i) {
      putchar(dir[path[i]]);
    }
    puts("");
  }
}
