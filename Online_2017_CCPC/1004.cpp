#include <bits/stdc++.h>
using namespace std;
const int moder = 1000000007;
const int maxn = 2000000 + 20;
int fail[maxn];
string S, T;
int slen, tlen;
void getNext() {
  int j = 0;
  int k = -1;
  fail[0] = -1;
  while (j < tlen)
    if (k == -1 || T[j] == T[k])
      fail[++j] = ++k;
    else
      k = fail[k];
}
long long KMP_Count() {
  long long ans = 0;
  long long i, j = 0;

  if (slen == 1 && tlen == 1) {
    if (S[0] == T[0])
      return 1;
    else
      return 0;
  }
  getNext();
  for (i = 0; i < slen; i++) {
    while (j > 0 && S[i] != T[j]) {
      ans = (ans + ((1 + j) * j / 2LL) % moder) % moder;
      j = fail[j];
    }
    if (S[i] == T[j]) j++;
    if (j == tlen) {
      ans = (ans + ((1 + j) * j / 2LL) % moder) % moder;
      j = fail[j];
    }
  }
  return ans;
}
string tmp;
void work() {
  cin >> S >> T;
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());
  S += tmp;
  getNext();
  slen = (int)S.size();
  tlen = (int)T.size();
  // printf("%I64d\n", KMP_Count());
  cout << KMP_Count() << endl;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  tmp = "#";
  for (int i = 0; i < 1000000; ++i) tmp.push_back('$');
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
