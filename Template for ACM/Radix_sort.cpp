#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 20;
int tmp[maxn];

void radix_sort(int a[], int n) {
  int p = 10;
  int d = 1;
  int Max = *max_element(a, a + n);
  while (Max >= p) {
    Max /= 10;
    ++d;
  }

  int radix = 1;
  for (int i = 1; i <= d; ++i) {
    int bucket[10] = {0};

    for (int j = 0; j < n; ++j) {
      bucket[(a[j] / radix) % 10]++;
    }
    for (int j = 1; j < 10; ++j) {
      bucket[j] += bucket[j - 1];
    }
    for (int j = n - 1; j >= 0; --j) {
      tmp[--bucket[(a[j] / radix) % 10]] = a[j];
    }
    for (int j = 0; j < n; ++j) {
      a[j] = tmp[j];
    }
    radix = radix * 10;
  }
}
