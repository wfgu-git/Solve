#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

ll lcm(ll x, ll y) {
    return   y / gcd(x, y) * x ;
}
int main(int argc, char const *argv[]) {
    int x, n;
    cin >> x >> n;
    for(int i = 2; i <= n; i++) {
        cout << lcm(i, x) / x << endl;
    }
    return 0;
}