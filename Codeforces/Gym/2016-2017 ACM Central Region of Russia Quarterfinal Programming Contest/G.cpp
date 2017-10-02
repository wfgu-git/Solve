/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

const int inf = 0x3f3f3f3f;

int main() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);

  int x;
  while (scanf("%d", &x) != EOF) {
    set<int> ret;
    for (int i = 2; x != 1; ++i) {
      if (x % i == 0) {
        ret.insert(i);
        do {
          x /= i;
        } while (x % i == 0);
      }
    }
    printf("%s\n", ret.size() == 3 ? "YES" : "NO");
  }
}
