#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pat[600 + 2];
int dp[300 + 2];
int f[25 + 2];
int solve(const string &s, const string &t) {
    int s_len = (int)s.size();
    int t_len = (int)t.size();

    int i = s_len - 1, j = t_len - 1;
    while (i >= 0 && j >= 0) {
        if (s[i] == t[j]) {
            i--;
            j--;
        } else {
            i--;
        }
    }
    if (j == -1) {
        return i + 1;
    } else {
        return -1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    int q;
    int n;
    string str;
    while (cin >> q >> n) {
        cin >> str;
        for (int i = 0; i < q; i++) cin >> pat[i];

        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            string s = str.substr(0, i);
            for (int j = 0; j < q; j++) {
                string p = pat[j];
                if ((int)p.size() > i + 1) continue;
                else {
                    int pos = solve(s, p);
                    if (pos != -1) {
                        dp[i] = min(dp[i], dp[pos] + i - pos - (int)p.size());
                    }
                }
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}