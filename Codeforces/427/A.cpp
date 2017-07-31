#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
  int a = v1 * s + 2 * t1;
  int b = v2 * s + 2 * t2;
  if (a == b) printf("Friendship\n");
  else if (a < b) printf("First\n");
  else printf("Second\n");
  return 0;
}
