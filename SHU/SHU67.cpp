#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        int cur;
        cin >> n >> cur;

        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            cur = lcm(cur, x);
        }
        cout << cur << endl;
    }
    return 0;
}