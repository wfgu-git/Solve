#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d\n", &n) == 1) {
        int cnt = 0, ret, x;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
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
        printf("%d\n", ret);
    }
    return 0;
}
