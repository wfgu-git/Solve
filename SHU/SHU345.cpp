#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        for (ll i = 2; i <= n; i *= 2) {
            ans += n / i;
        }
        cout << ans << endl;
    }
    return 0;
}