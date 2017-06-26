#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll solve(ll x, ll y)
{
    ll ret = 0;
    ret = x * (x + 1) * (y + 1) / 2 + y * (y + 1) * (x + 1) / 2;
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    int m, b;
    while (cin >> m >> b) {
        ll ans = -1;
        int x, y;

        for (y = 0; y <= b; y++) {
            x = (b - y) * m;
            ans = max(ans, solve(x, y));
        }
        cout << ans << endl;
    }
    return 0;
}