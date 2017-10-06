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
const int maxn = 2000 + 20;

int x[maxn], y[maxn];
set<int> st;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    st.insert(x[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> y[i];
    st.insert(y[i]);
  }
  int cont =  0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (st.find(x[i] ^ y[j]) != st.end()) {
        cont++;
      }
    }
  }
  if (cont & 1) {
    cout << "Koyomi";
  } else {
    cout << "Karen";
  }
}
