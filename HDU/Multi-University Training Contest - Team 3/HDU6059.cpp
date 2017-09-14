/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;

int a[maxn];
int ch[maxn * 64][2];
int cntr[maxn * 64];
int cntl[maxn * 64];
ll ans0[35];
ll ans1[35];
int root, tot;
int newnode() {
  ch[tot][0] = ch[tot][1] = -1;
  cntr[tot] = cntl[tot] = 0;
  return tot++;
}
void init() {
  tot = 0;
  root = newnode();
  ch[0][0] = ch[0][1]= -1;
  cntr[0] = cntl[0] = 0;
}
void insert(int x) {
  int now = root;
  int t;
  for (int i = 31; i >= 0; --i) {
    t = ((x >> i) & 1);
    if (ch[now][t] == -1) {
      ch[now][t] = newnode();
    }
    now = ch[now][t];
    cntr[now]++;
  }
}
ll query(int x) {
  int now = root;
  ll ret = 0;
  int t;
  for (int i = 31; i >= 0; --i) {
    t = ((x >> i) & 1);
    cntr[ch[now][t]]--;
    if (t) {
      ret += ans1[i];
      ans1[i] += cntr[ch[now][0]];
      ans0[i] -= cntl[ch[now][0]];
    } else {
      ret += ans0[i];
      ans0[i] += cntr[ch[now][1]];
      ans1[i] -= cntl[ch[now][1]];
    }
    cntl[ch[now][t]]++;
    now = ch[now][t];
  }
  return ret;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      insert(a[i]);
    }
    ll ans = 0;
    for (int i = 0 ; i < n; ++i) {
      ans += query(a[i]);
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
