/*
教练我想打ACM！
*/
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 20;

int a[maxn];
struct Deque {
  int val, idx;
  Deque(int v = 0, int x = 0) : val(v), idx(x) {}
} Q[maxn];
int head, tail;
vector<int> Max, Min;
int n, k;
void solve_min() {
  Min.clear();
  head = 1;
  tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && Q[tail].val >= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && Q[tail].val >= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
    while (head <= tail && Q[head].idx < i - k + 1) {
      ++head;
    }
    Min.push_back(Q[head].val);
  }
}
void solve_max() {
  Max.clear();
  head = 1;
  tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && Q[tail].val <= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && Q[tail].val <= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
    while (head <= tail && Q[head].idx < i - k + 1) {
      ++head;
    }
    Max.push_back(Q[head].val);
  }
}
