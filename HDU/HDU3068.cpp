#include <bits/stdc++.h>
using namespace std;
const int maxn = 110002;
char Ma[maxn << 1];
int Mp[maxn << 1];
void Manacher(const string &s)
{
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for (auto ch : s) {
        Ma[l++] = ch;
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for (int i = 0; i < l; i++) {
        if (mx > i) {
            Mp[i] = min(Mp[2 * id - i], mx - i);
        } else {
            Mp[i] = 1;
        }
        while (Ma[i + Mp[i]] == Ma[i - Mp[i]] ) ++Mp[i];
        if (i + Mp[i] > mx) {
            mx = i + Mp[i];
            id = i;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);

    string s;
    while (cin >> s) {
        Manacher(s);
        int ans = 0;
        for (int i = 0; i < 2 * s.size() + 2; i++) {
            ans = max(ans, Mp[i] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
