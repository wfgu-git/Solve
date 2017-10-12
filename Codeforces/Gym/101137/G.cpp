/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;


int n;
void print(int a, int b, int c) {
  printf("%d %d %d\n", a, b, c);
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  while (scanf("%d", &n) != EOF) {
    print(1, 1, 0);
    for (int i = 1; i + 1 <= n; ++i) {
      for (int j = i + 2; j <= n; ++j) {
        print(j, j, i);
        print(i, i, j);
      }
      if (i + 1 <= n) print(i + 1, i + 1, i);
    }
    for (int i = n - 1; i >= 2; --i) {
      print(i, i, i + 1);
    }
    print(0, 1, 2);
    printf("\n\n\n");
  }
}
