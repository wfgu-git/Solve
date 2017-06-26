#include <bits/stdc++.h>
using namespace std;

stack < int > sta;
int main()
{
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        string op;
        int ans = 0;
        int cur = 1;
        for (int i = 1; i <= n * 2; i++) {
            cin >> op;
            if (op[0] == 'a') {
                int x;
                cin >> x;
                sta.push(x); 
            } else {
                if (!sta.empty()) {
                    if (sta.top() == cur) {
                        sta.pop();
                    } else {
                        ans++;
                        while (!sta.empty()) sta.pop();
                    }
                    cur++;
                } else {
                    cur++;
                }
            } 
        } 
        cout << ans << endl;
    }
    return 0; 
}