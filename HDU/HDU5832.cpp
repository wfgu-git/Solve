#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    string num;
    int kase = 0;
    int base = 73 * 137;
    while (getline(cin, num)) {
        int n = num.size();
        int v = 0;
        for (int i = 0; i < n; i++) {
            v = v * 10 + num[i] - '0';
            v %= base;
        }
        cout << "Case #" << ++kase << ": ";
        if (v == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
