/*
教练我要打ACM!
*/
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int grid[6][6];
map<int, int> ans;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
inline bool inside(int x, int y) {
  return (x >= 0 && x < 5 && y >= 0 && y < 5);
}
void DFS(int x, int y, int w, int dep) {
  if (dep == 5) {
    ans[w]++;
    return;
  }

  for (int i = 0; i < 4; ++i) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (inside(tx, ty)) {
      DFS(tx, ty, w * 10 + grid[tx][ty], dep + 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      DFS(i, j, grid[i][j], 0);
    }
  }
  cout << ans.size() << endl;
}
