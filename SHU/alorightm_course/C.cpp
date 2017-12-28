/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    printf("%d\nTimes:%d\n", n, (int)ceil(log(n) / log(3)));
  }
}
