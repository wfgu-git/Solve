/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 5000000 + 20;
const int chsz = 26;

struct Tire {
  int tot;
  int root;
  int fail[maxn], next[maxn][chsz], end[maxn];
  int newnode() {
    for (int i = 0; i < chsz; ++i) {
      next[tot][i] = -1;
    }
    end[tot++] = 0;
    return tot - 1;
  }

  void init() {
    tot = 0;
    root = newnode();
  }

  void insert(const string& str) {
    int now = root;
    int n = str.size();
    for (int i = 0; i < n; ++i) {
      int tid = str[i] - 'a';
      if (next[now][tid] == -1) next[now][tid] = newnode();
      now = next[now][tid];
    }
    ++end[now];
  }

  void build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < chsz; ++i) {
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      }
    }

    while (!q.empty()) {
      int now = q.front(); q.pop();
      for (int i = 0; i < chsz; ++i) {
        if (next[now][i] == -1) {
          next[now][i] = next[fail[now]][i];
        } else {
          fail[next[now][i]] = next[fail[now]][i];
          q.push(next[now][i]);
        }
      }
    }
  }

  int solve(const string& str) {
    int ret = 0, k = 0;
    int n = str.size();
    for (int i = 0; i < n; ++i) {
      int tid = str[i] - 'a';
      k = next[k][tid];
      int j = k;
      while (j) {
        ret += end[j];
        end[j] = 0;
        j = fail[j];
      }
    }
    return ret;
  }

} ACm;
int N;
string buf;
string str[300000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cin >> N;
    ACm.init();
    int mxlen = -1, len;
    int mxid;
    for (int i = 0; i < N; ++i) {
      cin >> str[i];
      len = str[i].size();
      if (mxlen < len) {
        mxlen = len;
        mxid = i;
      }
    }
    bool flag = 1;
    int tot = 0;
    for (int i = 0; i < N; ++i) {
      if (i != mxid && str[i].size() == mxlen) {
        if (str[i] != str[mxid]) {
          cout << "No" << endl;
          flag = 0;
          break;
        } else {
          tot++;
        }
      } else {
        ACm.insert(str[i]);
      }
    }

    if (!flag) {
      continue;
    }

    ACm.build();
    int cont = ACm.solve(str[mxid]);
    if (cont + tot == N) {
      cout << str[mxid] << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
