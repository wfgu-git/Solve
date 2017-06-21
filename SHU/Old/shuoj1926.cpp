#include <bits/stdc++.h>
using namespace std;

bool check(const string &s)
{
    int n = s.size();
    bool flag = true;
    for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
        if (s[i] != s[j]) {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    int cas;
    cin >> cas;
    for (int i = 0; i < cas; i++) {
        string s;
        cin >> s;
        if (check(s)) {
            cout << "YES\n";
            continue;
        }
        int n = (int)s.size();
        int l = 0;
        int r = n - 1;
        int idx_l, idx_r;
        while (l < n / 2 && r >= n / 2) {
            if (s[l] == s[r]) l++, r--;
            else {
                idx_l = l;
                idx_r = r;
                break;
            }
        }

        bool flag = false;
        string temp1 = s;
        string temp2 = s;
        temp1.erase(idx_l, 1);
        temp2.erase(idx_r, 1);
        //cout << temp1 << endl << temp2 << endl;
        flag = check(temp1) | check(temp2);
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

