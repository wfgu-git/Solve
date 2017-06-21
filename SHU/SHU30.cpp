#include <bits/stdc++.h>
using namespace std;

int ch[] = {'0', '1', '2'};
int main()
{
    int n;
    while (cin >> n) {
        string ans = "";
        while (n) {
            ans.push_back(ch[n % 3]);
            n /= 3;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}

