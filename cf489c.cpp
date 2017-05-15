#include <bits/stdc++.h>
using namespace std;

bool check(int m, int s) {
    if (s < 0 || m * 9 < s) return false;
    return true;
}
int m, sum;
int main(void) {
    ios::sync_with_stdio(false);
    cin >> m >> sum;

    string mini, maxi;
    mini = maxi = "";
    int val = sum;
    char base = '0';
    // find min
    for (int i = 0; i < m; i++) {
        for (int d = 0; d <= 9; d++) {
            if (i == 0 && d == 0) continue;
            if (check(m - i - 1, val - d)) {
                mini += base + d;
                val -= d;
                break;
            }
        }
    }
    val = sum;
    // find max
    for (int i = 0; i < m; i++) {
        for (int d = 9; d >= 0; d--) {
            if (i == 0 && d == 0) continue;
            if (check(m - i - 1, val - d)) {
                maxi += base + d;
                val -= d;
                break;
            }
        }
    }
    if (m == 1 && sum == 0)
        cout << "0 0" << endl;
    else if (mini.size() != m)
        cout << "-1 -1" << endl;
    else
        cout << mini << " " << maxi << endl;
    return 0;
}
