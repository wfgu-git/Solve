/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
int read() {
  int x = 0, c = getchar(), f = 1;
  for (; c < 48 || c > 57; c = getchar())
    if (!(c ^ 45)) f = -1;
  for (; c > 47 && c < 58; c = getchar()) x = (x << 1) + (x << 3) + c - 48;
  return x * f;
}
rope<char> a, b, tmp;
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  char opt[20];
  static char ch[1 << 22];
  static char rch[1 << 22];
  int n, x, pos = 0;
  int length;
  n = read();
  for (int q = 0; q < n; ++q) {
    scanf("%s", opt);
    switch (opt[0]) {
      case 'M':
        pos= read();
        break;
      case 'P':
        pos--;
        break;
      case 'N':
        ++pos;
        break;
      case 'G':
        putchar(a[pos]);
        putchar('\n');
        break;
      case 'I':
        x = read();
        length = a.size();
        for (int i = 0; i < x; ++i) {
          do {
            ch[i] = getchar();
          } while (ch[i] == '\n');
          rch[x - i - 1] = ch[i];
        }
        ch[x] = rch[x] = '\0';
        a.insert(pos, ch);
        b.insert(length - pos, rch);
        break;
      case 'D':
        x = read();
        length = a.size();
        a.erase(pos, x);
        b.erase(length - pos - x, x);
        break;
      case 'R':
        x = read();
        length = a.size();
        tmp = a.substr(pos, x);
        a = a.substr(0, pos) + b.substr(length - pos - x, x) +
            a.substr(pos + x, length - pos - x);
        b = b.substr(0, length - pos - x) + tmp + b.substr(length - pos, pos);
        break;
    }
  }
  return 0;
}
