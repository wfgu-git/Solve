/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;

int T, n;
int a[maxn];
ll ans0[35], ans1[35];
struct Node {
  Node* ch[2];
  int cntl, cntr;
} ;
Node* root;
Node* null = new Node;
Node* newnode() {
  Node* tmp = new Node;
  tmp->ch[0] = null;
  tmp->ch[1] = null;
  tmp->cntl = tmp->cntr = 0;
  return tmp;
}
void insert(const int& x, Node* o = root) {
  Node* now = o;
  int t;
  for (int i = 31; i >= 0; --i) {
    t = ((x >> i) & 1);
    if (now->ch[t] == null) {
      now->ch[t] = newnode();
    }
    now = now->ch[t];
    now->cntr++;
  }
}
ll query(const int& x, Node* o = root) {
  Node* now = o;
  ll ret = 0;
  int t;
  for (int i = 31; i >= 0; --i) {
    t = ((x >> i) & 1);
    now->ch[t]->cntr--;
    if (t) {
      ret += ans1[i];
      ans1[i] += now->ch[0]->cntr;
      ans0[i] -= now->ch[0]->cntl;
    } else {
      ret += ans0[i];
      ans0[i] += now->ch[1]->cntr;
      ans1[i] -= now->ch[1]->cntl;
    }
    now->ch[t]->cntl++;
    now = now->ch[t];
  }
  return ret;
}
void clear(Node* o) {
  if (o == null) return;
  clear(o->ch[0]);
  clear(o->ch[1]);
  delete o;
}

int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d", &n);
    root = newnode();
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      insert(a[i]);
    }
    memset(ans0, 0, sizeof(ans0));
    memset(ans1, 0, sizeof(ans1));
    ll ans= 0;
    for (int i = 0; i < n; ++i) {
      ans += query(a[i]);
    }
    printf("%I64d\n", ans);
    clear(root->ch[0]);
    clear(root->ch[1]);
  }
}
