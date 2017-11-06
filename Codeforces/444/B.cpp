/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int n;
set<int> S[3], temp[3];
void work() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      int x;
      cin >> x;
      S[i].insert(x);
    }
  }

  int num[3];
  vector<int> Q{0, 1, 2};
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 0; j < 3; ++j) num[j] = -1;
    int x = i, tot = 0;
    while (x > 0) {
      num[tot++] = x % 10;
      x /= 10;
    }
    int cont = 0;
    do {
      int temp = 0;
      for (int j = 0; j < 3; ++j) {
        int t = Q[j];
        if (S[t].find(num[j]) != S[t].end()) {
          temp++;
        } else {
          break;
        }
      }
      cont = max(cont, temp);
    } while (next_permutation(Q.begin(), Q.end()));

    if (cont != tot) {
      cout << i - 1;
      return ;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
