#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
int tail = 100000 + 5;
const int moder = 1000000007;
using ll = long long;
ll mod_pow(int n) {
  ll base = 26, ans = 1;
  while (n) {
    if (n & 1)
      ans = ans * base % moder;
    base = base * base % moder;
    n >>= 1;
  }
  return ans;
}
int maxlen;
struct char_info {
  char c;
  int a[maxn];
} ch[26];
bool comp(char_info &a, char_info &b) {
  for (int i = tail - maxlen - 1; i <= tail; i++) {
    if (a.a[i] != b.a[i])
      return a.a[i] > b.a[i];
  }
  return 0;
}
int info[26];
set<char> not_first;
void init() {
  maxlen = 0;
  memset(info, 0, sizeof(info));
  for (char c = 'a'; c <= 'z'; ++c) {
    not_first.insert(c);
  }
  for (int i = 0; i < 26; i++) {
    ch[i].c = ('a' + i);
    memset(ch[i].a, 0, sizeof(ch[i].a));
  }
}
char s[maxn];
int main() {
  int n;
  int kase = 0;
  while (scanf("%d", &n) != EOF) {
    init();
    for (int k = 0; k < n; k++) {
      scanf("%s", s);
      int sz = strlen(s);
      maxlen = max(maxlen, sz);
      if (sz != 1) not_first.erase(s[0]);
      for (int i = sz - 1, bit = tail; i >= 0; i--, bit--) {
        ch[s[i] - 'a'].a[bit]++;
      }
    }
    for (int i = 0; i < 26; i++) {
      for (int j = tail; j > tail - maxlen; j--) {
        ch[i].a[j - 1] += ch[i].a[j] / 26;
        ch[i].a[j] %= 26;
      }
    }
    sort(ch, ch + 26, comp);
    char zero;
    for (int i = 25; i >= 0; i--) {
      if (not_first.find(ch[i].c) != not_first.end()) {
        zero = ch[i].c;
        info[ch[i].c - 'a'] = 0;
        break;
      }
    }
    for (int i = 0, fix = 25; fix > 0; i++, fix--) {
      if(ch[i].c == zero) {
        fix++;
        continue;
      }
      info[ch[i].c - 'a'] = fix;
    }
    ll ans = 0;
    for (int i = 0; i < 26; i++) {
      ll v = info[ch[i].c - 'a'] * 1LL;
      for (int j = tail, bit = 0; j >= tail - maxlen - 1; j--, bit++) {
        ll cnt = ch[i].a[j];
        ans = (ans + (v * cnt % moder) * mod_pow(bit) % moder) % moder;
      }
    }
    printf("Case #%d: %d\n", ++kase, ans);
  }
  return 0;
}
