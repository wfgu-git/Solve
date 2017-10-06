#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  // freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  queue<int> Q;
  int tot = 0;
  int nn = n;
  for (int i = 2; i <= nn; ++i) {
    if (n % i == 0) {
      do {
        n /= i;
        Q.push(i);
      } while(n % i == 0);
    }
  }
  if ((int)Q.size() < k) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < k - 1; ++i) {
    cout << Q.front() << " ";
    Q.pop();
  }
  int last = 1;
  while (!Q.empty()) {
    last *= Q.front();
    Q.pop();
  }
  cout << last;
}
