#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = INT_MAX;
const int maxn = 1e5 + 10;
int n, k;
int a[maxn];
int check(int v) {
    int cnt = 1;
    int temp = 0, num = 0;
    int k = 0;
    for(int i = n - 1; i >= k; i++) {
        temp += a[i];
        if(temp + a[k] <= v) {
            temp += a[k];
            k++;
        }
        ++cnt;
    }
}

int l, mid;
ll r;
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    l = r = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        r += a[i];
    }

    while(r - l > 1) {
        mid = l + (r - l) / 2;
        if(check(mid) <= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}
