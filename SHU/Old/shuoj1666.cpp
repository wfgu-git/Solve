#include <bits/stdc++.h>
using namespace std;

int a[10010];
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for_each(a, a + n, [](int &x){cin >> x;});
        sort(a, a + n);
        int mid = a[n / 2];
        long long ret = 0;
        for_each(a, a + n, [&ret, mid](int x){ret += abs(x - mid);});
        cout << ret << endl;
    }
    return 0;
}
