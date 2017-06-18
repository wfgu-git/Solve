#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int ori[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for_each(ori, ori + n, [](int &x){cin >> x;});
    for(int i = 0; i < m; i++){
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--, x--;
        int cnt = 0;
        for(int i = l; i <= r; i++){
            if(ori[i] < ori[x])
                cnt++;
        }
 //       cout << cnt << " " << x - l << " " << endl;
        if(cnt == x - l) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
