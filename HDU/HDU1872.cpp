#include <bits/stdc++.h>
using namespace std;
struct INFO {
  string name;
  int mark, clok;
  bool operator < (const INFO& rhs) const {
    if (mark == rhs.mark) {
      return clok < rhs.clok;
    }
    return mark > rhs.mark;
  }
  bool operator == (const INFO& rhs) const {
    return name == rhs.name && mark == rhs.mark;
  }
} ;
int n;
void work() {
  string name;
  int mark;
  vector<INFO> st, ret;
  for (int i = 0; i < n; ++i) {
    cin >> name >> mark;
    st.push_back({name, mark, i});
  }
  sort(st.begin(), st.end());
  int pre = 0x3f3f3f3f;
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    cin >> name >> mark;
    ret.push_back({name, mark, i});
    if (mark <= pre) {
      pre = mark;
    } else {
      flag = false;
    }
  }

  if (flag) {
    bool check = true;
    for (int i = 0; i < n; ++i) {
      if (st[i] == ret[i]) continue;
      else check = false;
    }
    if (check) {
      cout << "Right" << endl;
    } else {
      cout << "Not Stable" << endl;
      for (INFO& x : st) {
        cout << x.name << " " << x.mark << endl;
      }
    }
  } else {
    cout << "Error" << endl;
    for (INFO& x : st) {
      cout << x.name << " " << x.mark << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n) {
    work();
  }
  return 0;
}
