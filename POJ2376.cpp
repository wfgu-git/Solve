#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct interval {
    int l, r;

    bool operator < (const interval &rhs) const {
        if (l == rhs.l) return r > rhs.r;
        return l < rhs.l;
    }

    interval() {}
    interval(int _l, int _r) : l(_l), r(_r) {}
}a[25002];

int main()
{
    int n, L;
    while (scanf("%d%d", &n, &L) != EOF) {
        for (int i = 0; i < n; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            a[i] = interval(l, r);
        }
        sort(a, a + n);

        if (a[0].l != 1) {
            printf("-1\n");
            continue;
        }
        int cover = a[0].r;
        int cnt = 1;
        int i = 1;

        while (i < n) {
            if (cover == L) break;
            int max_r = -1;
            bool flag = false;
            while (a[i].l <= cover + 1) {
                flag = true;
                max_r = max(max_r, a[i].r);
                i++;
            }
            if(!flag) break;
            cover = max_r;
            cnt++;
        }
        if (cover != L) printf("-1\n");
        else printf("%d\n", cnt);
    }
    return 0;
}

