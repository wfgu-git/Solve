#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 2;
int a[maxn];
int l[maxn], r[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for_each(a, a + n, [](int &x) { cin >> x; });

    for (int i = 0; i < n; i++) r[i]  = l[i] = i;
    for (int i = 1; i < n; i++) { 
        int now = i;
        while (now >= 1 && a[i] > a[now - 1]) { now = l[now - 1]; }
        l[i] = now;
    }
    for (int i = n - 2; i >= 0; i--) {
        int now = i;
        while (now < n - 1 && a[i] >= a[now + 1]) { now = r[now + 1]; }
        r[i] = now;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << "  -- > (" << l[i] << ", " << r[i] << ")\n";
    // }
    ll sigma_max = 0;
    for (int i = 0; i < n; i++) {
        sigma_max += (ll)(i - l[i] + 1) * (ll)(r[i] - i + 1) * (ll)a[i];
    }

    for (int i = 0; i < n; i++) r[i]  = l[i] = i;
    for (int i = 1; i < n; i++) {
        int now = i;
        while (now >= 1 && a[i] < a[now - 1]) { now = l[now - 1]; }
        l[i] = now;
    }
    for (int i = n - 2; i >= 0; i--) {
        int now = i;
        while (now < n - 1 && a[i] <= a[now + 1]) { now = r[now + 1]; }
        r[i] = now;
    }
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << "  -- > (" << l[i] << ", " << r[i] << ")\n";
    // }
    for (int i = 0; i < n; i++) {
        sigma_max -= (ll)(i - l[i] + 1) * (ll)(r[i] - i + 1) * (ll)a[i];
    }
    cout << sigma_max << endl;
    return 0;
}