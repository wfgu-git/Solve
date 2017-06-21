#include <bits/stdc++.h>
using namespace std;

int a[5005];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int mid = a[n / 2];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(a[i] - mid);
        }
        cout << ans << endl;
    }
    return 0;
}

