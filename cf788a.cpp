#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for_each(a + 1, a + 1 + n, [](int &x){cin >> x;});

    return 0;
}
