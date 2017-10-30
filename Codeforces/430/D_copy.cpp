/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5;

int a[3 * maxn];
struct node {
  int size;
  int times;
  node *son[2];
  void init() {
    for (int i = 0; i < 2; ++i) {
      son[i] = nullptr;
    }
    size = 0;
    times = 0;
  }
} ;
void push_down(node* o, int d) {
  for (int i = 0; i < 2; ++i) {
    if (o->son[i]) {
      o->son[i]->times ^= o->times;
    }
  }
  if ((o->times >> d) & 1) {
    swap(o->son[0], o->son[1]);
  }
  o->times = 0;
}
void insert(node* o, int x) {
  node* p = o;
  p->size++;
  for (int i = 31; i >= 0; --i) {
    int t = (x >> i) & 1;
    if (p->son[t] == nullptr) {
      p->son[t] = new node;
      p->son[t]->init();
    }
    p = p->son[t];
    p->size++;
  }
  p->times = 0;
}
void clear(node* o) {
  for (int i = 0; i < 2; ++i) {
    if (o->son[i]) clear(o->son[i]);
  }
  delete o;
}
void work() {
  node* root = new node;
  root->init();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  n = unique(a, a + n) - a;
  for (int i = 0; i < n; ++i) {
    insert(root, a[i]);
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    root->times ^= x;
    node* o = root;
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
      push_down(o, i);
      if (o->son[0] == nullptr
        || (o->son[0] != nullptr && o->son[0]->size != (1 << i))) {
          o = o->son[0];
        } else {
          o = o->son[1];
          ans |= (1 << i);
        }
        if (o == nullptr) {
          cout << ans << '\n';
          break;
        }
    }
  }
  clear(root);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
