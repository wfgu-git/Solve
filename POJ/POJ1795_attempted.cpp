/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxl = 1000 + 20;

int fail[maxl];
void get_fail(const string& t) {
  fail[0] = -1;
  int n = t.size();
  int j = 0;
  int k = -1;
  while (j < n) {
    if (k == -1 || t[j] == t[k]) {
      fail[++j] = ++k;
    } else {
      k = fail[k];
    }
  }
}
int KMP(const string& s, const string& t) {
  get_fail(t);
  int sn = s.size();
  int tn = t.size();
  int i = 0;
  int j = 0;
  while (i < sn && j < tn) {
    if (j == -1 || s[i] == t[j]) {
      ++i; ++j;
    } else {
      j = fail[j];
    }
  }
  if (j == tn) return i - tn + 1;
  else return -1;
}
const int maxn = 20 + 20;
bool vis[maxn];
int g[maxn][maxn];
int dp[20][(1 << 16) + 5];
string DP[20][(1 << 16) + 5];
/*
dp(i, j) i 结尾
*/
int calc(const string& x, const string& y) {
  int xsz = x.size();
  int ysz = y.size();
  int len = min(xsz, ysz);
  string subx, suby;
  for (; len > 0; len--) {
    subx = x.substr(xsz - len);
    suby = y.substr(0, len);
    if (subx == suby) {
      return ysz - len;
    }
  }
  return ysz;
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    vector<string> str;
    int n;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      str.push_back(tmp);
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) if (i != j && !vis[i] && !vis[j]) {
        if (KMP(str[i], str[j]) != -1) {
          vis[j] = 1;
        }
      }
    }
    vector<string> st;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        st.push_back(str[i]);
      }
    }

    n = st.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) if (i != j) {
        g[i][j] = calc(st[i], st[j]);
        // printf("%s --> %s  cost = %d\n", st[i].c_str(), st[j].c_str(), g[i][j]);
      }
    }
    memset(dp, 0x3f, sizeof(dp));
    int remark = dp[0][0];
    for (int i = 0; i < n; ++i) {
      // dp[i][0] = 0;
      DP[i][0] = "";
      dp[i][1 << i] = st[i].size();
      DP[i][1 << i] = st[i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < (1 << n); ++j) if (j & (1 << i)) {
        for (int k = 0; k < n; ++k) if (!(j & (1 << k))) {
          // if (__builtin_popcount(j - (1 << i)) + 1 == __builtin_popcount(j))
          // dp[k][j + (1 << k)] = min(dp[k][j + (1 << k)], dp[i][j]) + g[i][k];
          if (dp[k][j + (1 << k)] > dp[i][j]) {
            DP[k][j + (1 << k)] = DP[i][j] + st[k].substr(g[i][k]);
            dp[k][j + (1 << k)] = dp[i][j] + g[i][k];
          }else if(dp[k][j + (1 << k)] == dp[i][j]){
            if(remark != dp[k][j + (1 << k)])DP[k][j + (1 << k)] = min(DP[k][j + (1 << k)], DP[i][j] + st[k].substr(g[i][k]));
          }
        }
      }
    }
    int Min = inf;
    string ans = "";
    for (int i = 0; i < n; ++i) {
      if(Min < dp[i][(1 << n) - 1]){
        Min = dp[i][(1 << n) - 1];
        if(ans!="")ans = min(ans,DP[i][(1 << n) -1]);
        else ans = DP[i][(1 << n) - 1];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
