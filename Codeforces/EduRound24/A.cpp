#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    ll n, k;
    while (cin >> n >> k) {
        ll a, b;
        a = n / 2 / (k + 1);
        b = k * a;
        cout << a << " " << b << " " << n - (a + b) << endl;
    }
}