/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 20;

int a[maxn];
struct node {
  int size;
  node *son[maxn];
  void init() {
    for (int i = 0; i < 2; ++i) {
      son[i] = nullptr;
    }
    size = 0;
  }
} ;
void insert(node* root, int *x) {
  node* p = root;

}
void work() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  n = unique(a, a + n) - a;
  int info[31] = {0};
  for (int i = 0; i < n; ++i) {
    memset(info, 0, sizeof(info));
    int x;
    cin >> x;
    for (int i = 0; i < 31 && x; ++i) {
      info[i] = x & 1;
      x >>= 1;
    }
  }
  int m;
  cin >> m;
  int last = 0;
  while (m--) {
    int x;
    cin >> x;
    x ^= last;
    memset(info, 0, sizeof(info));
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
  #endif

  work();
}
