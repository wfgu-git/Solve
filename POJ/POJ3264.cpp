#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50000;
const int logmaxn = 20;
int Max[maxn + 1][logmaxn];
int Min[maxn + 1][logmaxn];
void RMQ(const int &n)
{
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
            Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
        }
    }
}
inline int get_ans(int l, int r)
{
    int k = 0;
    while (1 << (k + 1) < r - l + 1) k++;
    int _max = max(Max[l][k], Max[r - (1 << k)][k]);
    int _min = min(Min[l][k], Min[r - (1 << k)][k]);
    return _max - _min;
}
int main()
{
    int n, q;
    while (scanf("%d%d", &n, &q) == 2) {
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            Max[i][0] = x;
            Min[i][0] = x;
        }
        RMQ(n);
        for (int i = 0; i < q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            printf("%d\n", get_ans(l, r + 1));
        }
    }
}