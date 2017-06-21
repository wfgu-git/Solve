#include <bits/stdc++.h>
using namespace std;

inline bool is_p(const string &p, int n, int l, int r)
{
    if (n == 0 || n == 1)
        return 1;
    if (p[l] != p[r])
        return 0;
    return is_p(p, n - 2, l + 1, r - 1);
}
bool check(const string &p)
{
    int n = p.size();
    return is_p(p, n, 0, n - 1);
}
int main()
{
    int cas;
    cin >>cas;
    for (int i = 0; i < cas; i++) {
        string s;
        cin >> s;
        if (check(s)) {
            cout << "YES\n";
            continue;
        }
        int n = (int)s.size();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            string temp = s.substr(0, i) + s.substr(i + 1);
            if (check(temp)) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
