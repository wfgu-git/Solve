#include <complex>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<double> Complex;

const ld PI = acos(0.0) * 2.0;

void bit_reversal(vector<Complex>& a) {
  int n = a.size();
  int k;
  for (int i = 0, j = 0; i < n; ++i) {
    if (j > i) {
      swap(a[i], a[j]);
    }
    k = n;
    while (j & (k >>= 1)) {
      j &= ~k;
    }
    j |= k;
  }
}
