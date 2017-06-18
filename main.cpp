#include <bits/stdc++.h>
using namespace std;

map < int, int > cnt;
int main()
{
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int ans, Max = -1;
        for (auto kv : cnt) {
                if (kv.second > Max) {
                    Max = kv.second;
                    ans = kv.first;
                }
        }
        cout << ans << endl;
    }
    return 0;
}
