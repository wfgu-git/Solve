#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5;
int a[N + 5], l[N + 5], r[N + 5];
ll ans;
void solve(const int &n) {
    for (int i = 0; i < n; i++) l[i] = r[i] = i;

    for (int i = 1; i < n; i++) {
        int now = i;
        while (now >= 1 && a[i] <= a[now - 1]) now = l[now - 1];
        l[i] = now;
    }
    for (int i = n - 2; i >= 0; i--) {
        int now = i;
        while (now < n - 1 && a[i] <= a[now + 1]) now = r[now + 1];
        r[i] = now;
    }
}
int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(n);
        ans = -1;
        for (int i = 0; i < n; i++) {
            // cout << a[i] << " --> (" << l[i] << ", " << r[i] << ")" << endl;
            ans = max(ans, (ll)a[i] * ((ll)r[i] - (ll)l[i] + (ll)1));
        }
        cout << ans << endl;
    }
    return 0;
}