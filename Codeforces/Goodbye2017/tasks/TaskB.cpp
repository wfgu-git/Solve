/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

struct TaskB {
  int n, m;
  char grid[52][52];

  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
      return  0;
    }
    if (grid[x][y] == '#') {
      return 0;
    }
    return 1;
  }
	void solve(std::istream& in, std::ostream& out) {
    in >> n >> m;

    int sx, sy, ex, ey;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        in >> grid[i][j];
        if (grid[i][j] == 'S') {
          sx = i; sy = j;
        } else if (grid[i][j] == 'E') {
          ex = i; ey = j;
        }
      }
    }

    string str;
    in >> str;

    vector<int> perm = {0, 1, 2, 3};
    int tot = 0;
    do {
      int nowx = sx, nowy = sy;
      int flag = 1;
      for (char & ch : str) {
        int d = ch - '0';
        nowx += dx[perm[d]];
        nowy += dy[perm[d]];

        if (!check(nowx, nowy)) {
          flag = 0;
          break;
        }
        if (nowx == ex && nowy == ey) {
          flag = 0;
          ++tot;
          break;
        }
      }
      if (flag && nowx == ex && nowy == ey) {
        ++tot;
      }
    } while (next_permutation(perm.begin(), perm.end()));
    out << tot;
	}
};
