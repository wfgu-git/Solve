#include <bits/stdc++.h>
using namespace std;
int a[3][4] = {0, 1, 2, 3, 1, 2, 3, 4, 2, 3, 4, 5};
int main() {
  for (auto row : a) {
    cout << endl;
    for (auto col : row) {
      cout << col << " ";
    }
  }
  return 0;
}
