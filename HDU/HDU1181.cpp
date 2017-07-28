#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 20;
vector<int> g[maxn];
static char st = 'b';
static char tar = 'm';
inline int getid(char c) {return c - 'a';}
bool flag;
bool vis[maxn];
void dfs(char st) {
  vis[getid(st)] = true;
  for (int x : g[getid(st)]) {
    if (x  == getid(tar)) {
      flag = true;
      return;
    }
    if (!vis[x]) {
      dfs(x + 'a');
    }
  }
}
int main() {
  string s;
  while (cin >> s) {
    if (s[0] == '0') {
      flag = false;
      dfs(st);
      if (flag) cout << "Yes." << endl;
      else cout << "No." << endl;
      for (int i = 0; i < maxn; i++) g[i].clear();
      memset(vis, 0, sizeof(vis));
    }
    g[getid(s.front())].push_back(getid(s.back()));
  }
  return 0;
}
