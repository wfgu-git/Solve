#include <bits/stdc++.h>
using namespace std;

int a[100005];
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int money;
        cin >> money;
        //binary search
        int l = 0, r = n;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(a[mid] <= money)
                l = mid + 1;
            else
                r = mid;
        }
        cout << l << endl;
    }
    return 0;
}