#include <bits/stdc++.h>
using namespace std;
map < int, set < int > > problem;
map < int, set < int > > contest;
int tot_contest;
int tot;
map < string, int > id;
int get_id(const string &s) {
  if (id.count(s)) return id[s];
  return id[s] = ++tot;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  tot = tot_contest = 0;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    problem[get_id(s)] = set < int >();
  }
  for (int i = 0; i < q; i++) {
    int op;
    string s;
    int id;
    cin >> op;
    if (op == 1) {
      cin >> s;
      id = get_id(s);
      if (!problem.count(id) || !problem[id].size()) {
      } else {
        bool first = true;
        for (auto x : problem[id]) {
          if (first) { cout << x; first = false; }
          else cout << " " << x;
        }
        cout << endl;
      }
    } else if (op == 2) {
      cin >> s;
      id = get_id(s);
      if (!problem.count(id) || problem[id].size()) {
        cout << "DoNotExist" << endl;
      } else {
        cout << "Response" << endl;
      }
    } else if (op == 3) {
      contest[++tot] = set < int >();
    } else if (op == 4) {
      cin >> id;
      if (contest.count(id)) {
        for (auto x : contest[id]) {
          if (problem.count(x)) problem[x].erase(id);
          else problem[x] = set < int >();
        }
        contest.erase(id);
      } else {
        cout << "Invalid" << endl;
      }
    } else {
      int k;
      cin >> s >> k;
      id = get_id(s);
      if (!contest.count(k)) cout << "Invalid" << endl;
      else {
        contest[k].insert(id);
        if (problem.count(id)) problem[id].insert(k);
        else problem[id] = set < int >();
      }
    }
  }
  return 0;
}
