/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

char s[64];
char* p;
int x, y;
void g(int y) {
  if (y) {
    g((y - 1) / 26);
    putchar(65 + (y - 1) % 26);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", s);
    if (sscanf(s, "%*c%d%*c%d", &x, &y) == 2) {
      g(y);
      printf("%d\n", x);
    } else {
      p  = s;
      for (x = 0; *p > 64; ++p) {
        x = x * 26 + *p - 64;
      }
      printf("R%sC%d\n", p, x);
    }
  }
}
