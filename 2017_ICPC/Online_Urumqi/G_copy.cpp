#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100001];
char t[11];
char op[2];
char c[2];
int co[100001];
int f[400000];
void build(int x, int l, int r) {
  int xx = x << 1;
  int mid = (l + r) >> 1;
  if (l == r) {
    f[x] = co[l];
    return;
  }
  build(xx, l, mid);
  build(xx + 1, mid + 1, r);
  f[x] = f[xx] + f[xx + 1];
}
void add(int x, int l, int r, int pos, int num) {
  int xx = x << 1;
  int mid = (l + r) >> 1;
  f[x] += num;
  if (l == r && r == pos) {
    return;
  }
  if (pos <= mid) {
    add(xx, l, mid, pos, num);
  } else {
    add(xx + 1, mid + 1, r, pos, num);
  }
}
int find(int x, int l, int r, int left, int right) {
  int xx = x << 1;
  int mid = (l + r) >> 1;
  if (left == l && right == r) {
    return f[x];
  }
  if (right <= mid) {
    return find(xx, l, mid, left, right);
  } else if (mid < left) {
    return find(xx + 1, mid + 1, r, left, right);
  } else {
    int a = find(xx, l, mid, left, mid);
    int b = find(xx + 1, mid + 1, r, mid + 1, right);
    return a + b;
  }
}
int main(void) {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  int i, j, k;
  int n;
  int l, r;
  int pos;
  int len_s, len_t;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    len_s = strlen(s);
    len_t = strlen(t);
    memset(co, 0, sizeof(co));
    for (i = len_t; i <= len_s; i++) {
      for (j = i - len_t, k = 0; j < i; j++, k++) {
        if (s[j] != t[k]) {
          break;
        }
      }
      if (j == i) {
        co[i] = 1;
      }
    }
    build(1, 1, len_s);
    while (n--) {
      scanf("%s", op);
      if (op[0] == 'Q') {
        scanf("%d%d", &l, &r);
        if (l + len_t - 1 > r) {
          printf("0\n");
        } else {
          printf("%d\n", find(1, 1, len_s, l + len_t - 1, r));
        }
      } else {
        scanf("%d%s", &pos, c);
        s[pos - 1] = c[0];
        // printf("%s\n", s);
        for (i = max(pos - len_t, 0); i < min(len_s - len_t + 1, pos); i++) {
          for (j = i, k = 0; j < i + len_t; j++, k++) {
            if (s[j] != t[k]) {
              break;
            }
          }
          if (j < i + len_t) {
            if (co[i + len_t] == 1) {
              co[i + len_t] = 0;
              add(1, 1, len_s, i + len_t, -1);
            }
          } else {
            if (co[i + len_t] == 0) {
              co[i + len_t] = 1;
              add(1, 1, len_s, i + len_t, 1);
            }
          }
          /*for (j = 1; j <= len_s; j++)
          {
          printf("%d", co[j]);
          }
          printf("\n");*/
        }
      }
    }
    if (T) {
      printf("\n");
    }
  }
  return 0;
}
