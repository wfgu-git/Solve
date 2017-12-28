/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

int mep[maxn][maxn];
pii dist[maxn];
int inq[maxn];
vector<int> path[maxn];
void work() {
  int n;
  int kase = 0;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> mep[i][j];
      }
    }
    int s, t;
    cin >> s >> t;
    --s; --t;

    memset(inq, 0, sizeof(inq));
    for (int i = 0; i < n; ++i) {
      dist[i].first = inf;
    }
    inq[s] = 1;
    dist[s] = {0, 0};
    path[s] = {s};
    priority_queue<int, vector<int>, greater<int> > Q;
    Q.push(s);
    while (!Q.empty()) {
      int x = Q.top(); Q.pop();
      inq[x] = 0;
      for (int v = 0; v < n; ++v) {
        if (mep[x][v] != -1) {
          if (dist[v].first > dist[x].first + mep[x][v]) {
            dist[v].first = dist[x].first + mep[x][v];
            dist[v].second = dist[x].second + 1;
            path[v] = path[x];
            path[v].push_back(v);
            if (!inq[v]) {
              Q.push(v);
              inq[v] = 1;
            }
          } else if (dist[v].first == dist[x].first + mep[x][v] && dist[v].second > dist[x].second + 1) {
            dist[v].second = dist[x].second + 1;
            path[v] = path[x];
            path[v].push_back(v);
            if (!inq[v]) {
              Q.push(v);
              inq[v] = 1;
            }
          }
        }
      }
    }
    cout << "Case " << ++kase << '\n';
    cout << "The least distance from" << s + 1 << "->" << t + 1 << " is " << dist[t].first << '\n';
    cout << "the path is ";
    int fi = 1;
    for (int x : path[t]) {
      if (fi) {
        fi = 0;
        cout << x + 1;
        continue;
      }
      cout << "->" << x + 1;
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  work();
}
