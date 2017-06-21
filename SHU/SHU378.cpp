#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 0, ret;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (cnt == 0) {
            ret = x;
            cnt++;
        } else {
            if (ret == x) {
                cnt++;
            } else {
                cnt--;
            }
        }
    }
    cout << ret << endl;
    return 0;
}