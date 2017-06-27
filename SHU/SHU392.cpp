#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, t, k, d;
    while (cin >> n >> t >> k >> d) {
        if (ceil(1.0 * n / k) * t > t + d) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}