/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 20;

int n, m;
int bucket[maxn * 3];
struct node {
  node* son[2];
  void init() {
    for (int i = 0; i < 2; ++i) {
      son[i] = nullptr;
    }
  }
} ;
void insert(node* o, int x) {
  node* p = o;
  for (int i = 31; i >= 0; --i) {
    int t = (x >> i) & 1;
    if (p->son[t] == nullptr) {
      p->son[t] = new node;
      p->son[t]->init();
    }
    p = p->son[t];
  }
}
void clear(node* o) {
  for (int i = 0; i < 2; ++i) {
    if (o->son[i] != nullptr) clear(o->son[i]);
  }
  delete o;
}
void work() {
  node* root = new node;
  root->init();
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    bucket[tmp]++;
  }
  for (int i = 0; i <= 620000; ++i) {
    if (!bucket[i]) {
      insert(root, i);
    }
  }
  int now = 0;
  while (m--) {
    int x;
    cin >> x;
    now ^= x;
    x = now;
    int ans = 0;
    node* o = root;
    for (int i = 31; i >= 0; --i) {
      int k = (x >> i) & 1;
      if (o->son[k] != nullptr) {
        o = o->son[k];
      } else {
        ans |= (1 << i);
        o = o->son[k ^ 1];
      }
      if (o == nullptr) break;
    }
    cout << ans << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
