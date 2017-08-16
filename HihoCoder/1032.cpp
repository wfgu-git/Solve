#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 20;
//字符串长度<maxn
char Ma[maxn * 2];
int Mp[maxn * 2];
int Manacher(char s[]) {
  int l = 0, len = strlen(s);
  Ma[l++] = '$';
  Ma[l++] = '#';
  for (int i = 0; i < len; i++) {
    Ma[l++] = s[i];
    Ma[l++] = '#';
  }
  Ma[l] = 0;
  int mx = 0, id = 0;
  for (int i = 0; i < l; i++) {
    Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
    while (Ma[i + Mp[i]] == Ma[i - Mp[i]]) Mp[i]++;
    if (i + Mp[i] > mx) {
      mx = i + Mp[i];
      id = i;
    }
  }
  int ans = 0;
  for (int i = 0; i < 2 * len + 2; i++) ans = max(ans, Mp[i] - 1);
  return ans;
}
char s[maxn];
void work() {
  scanf("%s", s);
  printf("%d\n", Manacher(s));
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
