#include <bits/stdc++.h>
using namespace std;
struct INFO {
  string tid, name;
  int mark;
} ;
bool comp1(INFO a, INFO b) {
  return a.tid < b.tid;
}
bool comp2(INFO a, INFO b) {
  if (a.name == b.name) {
    return a.tid < b.tid;
  }
  return a.name < b.name;
}
bool comp3(INFO a, INFO b) {
  if (a.mark == b.mark) {
    return a.tid < b.tid;
  }
  return a.mark < b.mark;
}
int N, C;
void work(int kase) {
  vector<INFO> st;
  for (int i = 0; i < N; ++i) {
    string tid, name;
    int mark;
    cin >> tid >> name >> mark;
    st.push_back({tid, name, mark});
  }
  if (C == 1) sort(st.begin(), st.end(), comp1);
  else if (C == 2) sort(st.begin(), st.end(), comp2);
  else sort(st.begin(), st.end(), comp3);
  printf("Case %d:\n", kase);
  for (INFO& x : st) {
    cout << x.tid << " " << x.name << " " << x.mark << endl;
  }
}
int main() {
  int kase = 0;
  while (scanf("%d%d", &N, &C) != EOF && (N + C)) {
    work(++kase);
  }
  return 0;
}
