#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
const int maxn = 100;
int n, T;
int prefer[maxn][maxn];   // 编号为i的汉子第j喜欢的妹子
int order[maxn][maxn];    // 编号为i的妹子心中j汉子的排名
int nxt[maxn];            // 汉子i下一个收卡对象 初始化为1
int future_husband[maxn];
int future_wife[maxn];
queue<int> q; //单身狗队列 初始化都push入队
void engage(int man, int woman) {
  int m = future_husband[woman];
  if (m) {  // 女士有现任未婚夫m
    future_wife[m] = 0; // 抛弃m
    q.push(m);    // m加入单身狗队列
  }
  future_wife[man] = woman;
  future_husband[woman] = man;
}
void you_are_good_man() {
  memset(future_husband, 0, sizeof(future_husband));
  memset(future_wife, 0, sizeof(future_wife));
  while (!q.empty()) {
    int man = q.front(); q.pop();
    int woman = prefer[man][nxt[man]++];
    if (!future_husband[woman]) { // 没有汉子，直接上
      engage(man, woman);
    } else if (order[woman][man] < order[woman][future_husband[woman]]) {  // 现在的更好
      engage(man, woman);
    } else { // GG
      q.push(man);
    }
  }
  while (!q.empty()) q.pop();
}
map<char, int> hs;
map<int, char> arc;
int main() {
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    hs.clear();
    // while (!q.empty()) q.pop();
    scanf("%d", &n);
    int tot = 0;
    for (int i = 0; i < n * 2; ++i) {
      static char player[2];
      scanf("%s", player);
      hs[player[0]] = ++tot;
      arc[tot] = player[0];
    }
    char name[50];
    for (int i = 0; i < n; ++i) {
      scanf("%s", name);
      int t = hs[name[0]];
      for (int j = 0; j < n; ++j) {
        prefer[t][j + 1] = hs[name[j + 2]];
      }
      nxt[t] = 1;
      q.push(t);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%s", name);
      int t = hs[name[0]];
      for (int j = 0; j < n; ++j) {
        order[t][hs[name[j + 2]]] = j + 1;
      }
    }
    you_are_good_man();
    for (map<char, int>::iterator it = hs.begin(); it != hs.end(); ++it) {
      if (it->first >= 'A' && it->first <= 'Z') continue;
      printf("%c %c\n", it->first, arc[future_wife[it->second]]);
    }
    if (cas < T) printf("\n");
  }
  return 0;
}
