/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

struct Point {
  double x, y;
  int id;
} point[maxn];
int cmp(Point &a, Point &b) {
  if (a.y == b.y) return (a.x < b.x);
  return (a.y < b.y);
}
void QSort(Point p[], int l, int r) {
  int i = l, j = r;
  Point mid = p[(l + r) / 2], swap;
  while (i <= j) {
    while (cmp(p[i], mid)) i++;
    while (cmp(mid, p[j])) j--;
    if (i <= j) {
      swap = p[i];
      p[i] = p[j];
      p[j] = swap;
      i++;
      j--;
    }
  }
  if (i < r) QSort(p, i, r);
  if (l < j) QSort(p, l, j);
}
int mul(Point a, Point b, Point c) {
  int x1 = b.x - a.x;
  int y1 = b.y - a.y;
  int x2 = c.x - b.x;
  int y2 = c.y - b.y;
  return x1 * y2 - y1 * x2;
}
int sta[maxn], top;
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      point[i] = {1.0 * x, 1.0 * y, i};
    }
    if (n <= 2) {
      cout << "NO" << endl;
      continue;
    } else if (n == 3) {
      int x1, y1, x2, y2, x3, y3;
      x1 = point[0].x; y1 = point[0].y;
      x2 = point[1].x; y2 = point[1].y;
      x3 = point[2].x; y3 = point[2].y;
      if ((x1 == x2 && x2 == x3) || (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) {
        cout << "YES" << endl;
        QSort(point, 0, n - 1);
        string ret = "AAA";
        ret[point[1].id] = 'B';
        ret[point[0].id] = 'A';
        ret[point[2].id] = 'A';
        cout << ret << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "YES" << endl;
      QSort(point, 0, n - 1);
      int top = 1;
      for (int i = 0; i < 3; ++i) sta[i] = i;
      for (int i = 2; i < n; ++i) {
        while (top && mul(point[i], point[sta[top]], point[sta[top - 1]]) >= 0) top--;
        sta[++top] = i;
      }
      int len = top;
      sta[++top] = n - 2;
      for (int i = n - 3; i >= 0; --i) {
        while (top != len && mul(point[i], point[sta[top]], point[sta[top - 1]]) >= 0) top--;
        sta[++top] = i;
      }
      cout << top << endl;
      string ret;
      for (int i = 0; i < n; ++i) {
        ret.push_back('A');
      }
      if (top == 3) {
        while (top >= 0) {
          ret[point[sta[top--]].id] = 'B';
        }
      } else {
        int k = 0;
        while (top) {
          ret[point[sta[top--]].id] = 'A' + k;
          k ^= 1;
        }
      }
      cout << ret << endl;
    }
  }
}
