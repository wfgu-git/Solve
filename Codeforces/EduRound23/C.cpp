#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, s;
bool really_big(ll x, ll k = s) {
    ll xx = x;
    int sumd = 0;
    while (x) {
        sumd += x % 10;
        x /= 10;
    }
    ll sub_ret = xx - sumd;
    bool flag = sub_ret >= k;
    return flag;
}
int main()
{
    ios::sync_with_stdio(false);

    while (cin >> n >> s) {
        ll l = 0, r = n + 5;
        while (l < r) {
            ll mid = l + (r - l) / 2; 
            if (really_big(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ll ans = n - l + 1;
        ans = ans > 0 ? ans : 0;
        cout << ans << endl;
    }
    return 0;
}