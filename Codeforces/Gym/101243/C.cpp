#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  if (h < 2 || w < 2) {
    cout << 0;
    return 0;
  }
  int ans = (h * w - 4) / 2 + 1;
  cout << ans << endl;
  if (w % 2 == 0) {
    for (int i = h - 1; i >= 2; --i) {
      for (int j = 1; j <= w; j += 2) {
        cout << i << " " << j << endl;
      }
    }
    for (int i = 1; i < w; ++i) {
      cout << 1 << " " << i << endl;
    }
  } else if (h % 2 == 0) {
    for (int j = w - 1; j >= 2; --j) {
      for (int i = 1; i <= h; i += 2) {
        cout << i << " " << j << endl;
      }
    }
    for (int i = 1; i < h; ++i) {
      cout << i << " " << 1 << endl;
    }
  } else {
    for (int i = 3; i < h; i += 2) {
      cout << i << " " << w - 1 << endl;
    }
    for (int i = h - 1; i >= 2; --i) {
      for (int j = 1; j < w; j += 2) {
        cout << i << " " << j << endl;
      }
    }
    for (int i = 1; i < w; ++i) {
      cout << 1 << " " << i << endl;
    }
  }
}
