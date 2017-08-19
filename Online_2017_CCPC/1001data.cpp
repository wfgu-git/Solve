#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define sf(a) scanf("%lf", &a)
#define sd1(a) scanf("%d", &a)
#define sd2(a, b) scanf("%d%d", &a, &b)
#define sd3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sf(a) scanf("%lf", &a)
#define sf2(a, b) scanf("%lf%lf", &a, &b)
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef long long ll;
int G[100][100];
int main() {
  freopen("/home/wfgu/solve/data.out", "w", stdout);
  srand(time(0));
  int T;
  T = 100;
  cout << T << endl;
  while (T--) {
    memset(G, 0, sizeof(G));
    int n;
    n = rand() % 12 + 1;
    int m;
    if (n != 1)
      m = rand() % (n * (n - 1) / 2);
    else
      m = 0;
    cout << n << " " << m << endl;
    for (int i = 0; i < m; i++) {
      int u, v;
      u = rand() % n + 1;
      v = rand() % n + 1;
      while (G[u][v] && u != v) {
        u = rand() % n + 1;
        v = rand() % n + 1;
      }
      cout << u << " " << v << endl;
    }
  }
  return 0;
}
