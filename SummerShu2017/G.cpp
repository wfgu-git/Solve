#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;
vector < pii > enemy, us;
vector < int > v;
int n;
bool flag;
bool vis[10 + 1];
inline int touch(double hp, double atk) {
  return ceil(hp / atk);
}
bool fight(const vector < int > &v) {
  int l, r, lhp, rhp;
  l = r = 0;
  lhp = us[v[l]].first;
  rhp = enemy[r].first;
  while (l < n && r < n) {
    int now = v[l];
    int t1 = (rhp + us[now].second - 1) / us[now].second;
    int t2 = (lhp + enemy[r].second - 1) / enemy[r].second;

    rhp -= min(t1, t2) * us[now].second;
    lhp -= min(t1, t2) * enemy[r].second;

    if (lhp <= 0) {
      if (++l < n) lhp = us[v[l]].first;
    }
    if (rhp <= 0) {
      if (++r < n) rhp = enemy[r].first;
    }
  }

  if (l < n) return true;
  return false;
}
void dfs(int dep) {
  if (flag) return;

  if (dep == n) {
    flag = fight(v);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (flag) return;
    if (vis[i]) continue;
    vis[i] = true;
    v.push_back(i);
    dfs(dep + 1);
    v.pop_back();
    vis[i] = false;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
    scanf("%d", &n);
    int hp, atk;
    enemy.resize(n + 2);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &hp, &atk);
      enemy[i] = {hp, atk};
    }
    us.resize(n + 2);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &hp, &atk);
      us[i] = {hp, atk};
    }

    v.clear();
    memset(vis, 0, sizeof(vis));
    flag = false;
    dfs(0);

    if (flag) puts("YES");
    else puts("NO");
  }
  return 0;
}
