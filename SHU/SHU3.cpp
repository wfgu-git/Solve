#include <bits/stdc++.h>
using namespace std;

int f[2017];
int solve(int n) {
    if (f[n] != -1) return f[n];
    if (n == 1) return 0;
    else if (n % 2 == 0) return f[n] = solve(n / 2) + solve(n / 2) + (n / 2) * (n / 2);
    else
        return f[n] = solve(n - 1) + solve(1) + 1 * (n - 1);
}
int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    memset(f, -1, sizeof(f));
    for (int i = 0; i < t; i++) {
        int ans = 0;
        int n;
        cin >> n;
        ans = solve(n);
        if (ans) {
            if (ans == 1) cout << "Needs at least 1 ATP!" << endl;
            else cout << "Needs at least " << ans << " ATPs!" << endl;
        } else {
            cout << "Mission Complete!" << endl;
        }
    }
    return 0;
}