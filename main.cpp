#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int a[maxn + 5];
int n, m;
int binarysearch1(int v, int l = 1, int r = n)
{
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < v)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}
int binarysearch2(int v, int l = 1, int r = n)
{
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= v)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}
int binarysearch3(int v, int l = 1, int r = n)
{
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= v)
            l = mid + 1;
        else
            ans = mid, r = mid - 1;
    }
    return ans;
}
int binarysearch4(int v, int l = 1, int r = n)
{
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < v)
            l = mid + 1;
        else
            ans = mid, r = mid - 1;
    }
    return ans;
}
int main()
{
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cout << binarysearch1(x) << " " << binarysearch2(x) << " "
                 << binarysearch3(x) << " " << binarysearch4(x) << endl;
        }
    }
    return 0;
}
