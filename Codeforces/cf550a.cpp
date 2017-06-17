#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> ab;
    vector<int> ba;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B') ab.push_back(i);
        if (s[i] == 'B' && s[i + 1] == 'A') ba.push_back(i);
    }
    bool flag = false;
    for (int i = 0; i < ab.size(); i++) {
        for (int j = 0; j < ba.size(); j++) {
            if (abs(ab[i] - ba[j]) >= 2) {
                flag = true;
                break;
            }
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
