#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(void) {
    ios::sync_with_stdio(false);
    vector<ll> vi;
    ll n, k;
    cin >> n >> k;
    if (k >  1000000) {cout << -1 << endl; return 0;}
    for (int i = 1; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            vi.push_back(i);
            vi.push_back(n / i);

            // cout << i << "  " << n / i << endl;
        }
    }
    sort(vi.begin(), vi.end());
    vi.erase(unique(vi.begin(), vi.end()), vi.end());
    reverse(vi.begin(), vi.end());
    // for (auto x : vi) cout << x << endl;

    bool flag = false;
    for (auto x : vi) {
        ll sum = n / x;
        if (sum * 2 < k * (k + 1)) continue;
        flag = true;
        for (ll i = 1; i <= k - 1; i++) {
            cout << i * x << " ";
            n -= i * x;
        }
        cout << n << endl;
        break;
    }
    if (!flag) cout << -1 << endl;
    return 0;
}

// 3000000021 50000
