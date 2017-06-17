#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn << 1], ans[maxn << 1];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for_each (a, a + n, [](int &x){cin >> x;});
    int l = 0, r = n - 1;
    while (a[l]) l++;
    while (a[r]) r--;
    int dis = 0;
    for (int i = l; i >= 0; i--) ans[i] = dis++;
    dis = 0;
    for (int i = r; i < n; i++) ans[i] = dis++;
    dis = 0;
    for (int i = l; i <= r; i++){
        if(a[i]) ans[i] = ++dis;
        else dis = 0, ans[i] = 0;
    }
    dis = 0;
    for (int i = r; i >= l; i--){
        if (a[i]) ans[i] = min(ans[i], ++dis);
        else dis = 0, ans[i] = 0;
    }
    for_each (ans, ans + n, [](int x){cout << x << " ";});
    return 0;
}

