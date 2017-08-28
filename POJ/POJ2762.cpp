/*
   教练我要打ACM!
   Life has never been fucking so easy...
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;
const int maxm = 6000 + 20;

const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext() {
  if (++ps == pe)
    pe = (ps = buf) +
         fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T &ans) {
  ans = 0;
  T f = 1;
  if (ps == pe) return false;  // EOF
  do {
    rnext();
    if ('-' == *ps) f = -1;
  } while (!isdigit(*ps) && ps != pe);
  if (ps == pe) return false;  // EOF
  do {
    ans = (ans << 1) + (ans << 3) + *ps - 48;
    rnext();
  } while (isdigit(*ps) && ps != pe);
  ans *= f;
  return true;
}

const int MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write() {
  fwrite(bufout, sizeof(char), pout - bufout, stdout);
  pout = bufout;
}
inline void out_char(char c) {
  *(pout++) = c;
  if (pout == pend) write();
}
inline void out_str(const char *s) {
  while (*s) {
    *(pout++) = *(s++);
    if (pout == pend) write();
  }
}
template <class T>
inline void out_int(T x) {
  if (!x) {
    out_char('0');
    return;
  }
  if (x < 0) x = -x, out_char('-');
  int len = 0;
  while (x) {
    outtmp[len++] = x % 10 + 48;
    x /= 10;
  }
  outtmp[len] = 0;
  for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
  out_str(outtmp);
}

int T;
int N, M;
vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> vs;
pair<int, int> edges[maxm];
bool used[maxn];
int sccno[maxn];
vector<int> nG[maxn];
void add_edge(int u, int v) {
  G[u].push_back(v);
  rG[v].push_back(u);
}
void dfs(int u) {
  used[u] = true;
  for (int i = 0; i < (int)G[u].size(); ++i) {
    if (!used[G[u][i]]) dfs(G[u][i]);
  }
  vs.push_back(u);
}
void rdfs(int u, int k) {
  used[u] = true;
  sccno[u] = k;
  for (int i = 0; i < (int)rG[u].size(); ++i) {
    if (!used[rG[u][i]]) rdfs(rG[u][i], k);
  }
}
int scc() {
  memset(used, 0, sizeof(used));
  vs.clear();
  for (int v = 0; v < N; ++ v) {
    if (!used[v]) dfs(v);
  }
  memset(used, 0, sizeof(used));
  int k = 0;
  for (vector<int>::reverse_iterator it = vs.rbegin(); it != vs.rend(); ++it) {
    int x = *it;
    if (!used[x]) rdfs(x, k++);
  }
  return k;
}
void work() {
  in(N); in(M);
  //cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    G[i].clear();
    rG[i].clear();
    nG[i].clear();
  }

  for (int i = 0; i < M; ++i) {
    int u, v;
    in(u); in(v);
    //cin >> u >> v;
    --u; --v;
    add_edge(u, v);
    edges[i] = {u, v};
  }

  int scc_tot = scc();
  map<pair<int, int>, bool> S;
  vector<int> deg(scc_tot);
  for (int i = 0; i < M; ++i) {
    int from = edges[i].first;
    int to = edges[i].second;
    if (sccno[from] != sccno[to]) {
      if (S.count(make_pair(from, to))) continue;
      S[make_pair(from, to)] = 1;
      nG[sccno[from]].push_back(sccno[to]);
      ++deg[sccno[to]];
    }
  }

  queue<int> Q;
  for (int i = 0; i < scc_tot; ++i) {
    if (!deg[i]) {
      Q.push(i);
    }
  }
  if(Q.size() > 1) {
    out_str("No"); out_str("\n");
    //cout << "No" << endl;
    return;
  }
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    int cont = 0;
    for (int i = 0; i < (int)nG[u].size(); ++i) {
      int v = nG[u][i];
      if (!--deg[v]) {
        ++cont;
        Q.push(v);
      }
    }
    if (cont > 1) {
      out_str("No"); out_str("\n");
      //cout << "No" << endl;
      return;
    }
  }
  out_str("Yes"); out_str("\n");
  //cout << "Yes" << endl;
}
int main() {
  //cin >> T;
  in(T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  write();
  return 0;
}
