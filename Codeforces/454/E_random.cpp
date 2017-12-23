/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;

void work() {
  vector<unordered_set<int> > init;
  int n, m;
  cin >> n >> m;
  init.resize(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    init[x].insert(y);
    init[y].insert(x);
  }

  vector<int> perm;
  for (int i = 0; i < n; ++i) {
    perm.push_back(i);
  }

  vector<int> ans;
  int best = inf;
  srand(clock() + time(nullptr));
  while (clock() < 0.95 * CLOCKS_PER_SEC) {
    random_shuffle(perm.begin(), perm.end());

    vector<int> temp;
    vector<unordered_set<int> > now = init;
    int left = n * (n - 1) / 2 - m;

    for (int i = 0; i < n; ++i) {
      if (left == 0) {
        break;
      }

      int prev = left;
      for (int j : now[perm[i]]) {
        for (int k : now[perm[i]]) {
          if (j == k || now[j].count(k)) {
            continue;
          }
          now[j].insert(k);
          now[k].insert(j);
          --left;
        }
      }
      if (prev > left) {
        temp.push_back(perm[i]);
      }
    }

    if (temp.size() < best) {
      best = temp.size();
      ans = temp;
    }
  }

  cout << best << "\n";
  for (int & x : ans) {
    cout << x + 1<< " ";
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
