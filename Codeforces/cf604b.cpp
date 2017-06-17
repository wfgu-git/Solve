#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int n, k;
int a[maxn];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int maxv = -inf;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxv = max(maxv, a[i]);
    }
    if (k >= n) {
        cout << maxv << endl;
    } else {
        int single = 2 * k - n;
        int left = n - single;
        for (int i = n - 1; i >= n - single + 1; i--) {
            maxv = max(maxv, a[i]);
        }
        for (int i = 0; i < left / 2; i++) {
            maxv = max(maxv, a[i] + a[left - i - 1]);
        }
        cout << maxv << endl;
    }
    return 0;
}
