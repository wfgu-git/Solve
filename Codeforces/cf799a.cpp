#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int need = n / k * t;
    if (n % k != 0) need += t;

    if (need <= d + t) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}