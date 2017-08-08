#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int mp[maxn][maxn];
int ls[maxn * maxn][maxn];
//int up[maxn * maxn][maxn], dn[maxn * maxn][maxn];
int pref[maxn], suff[maxn], upper[maxn], lower[maxn];
long long ans = 0;
int n, m;
double sol()
{
    ans = 0;
    memset(ls, 0, sizeof ls);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &mp[i][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int co = mp[i][j];

            memset(upper, 0, sizeof upper);
            memset(lower, 0x3f, sizeof lower);
            memset(pref, 0, sizeof pref);
            memset(suff, 0, sizeof suff);
            pref[j] = ls[co][j];
            for (int k = j - 1; k >= 1; k--)
                pref[k] = max(pref[k + 1], ls[co][k]);
            for (int k = 0; k <= j; k++)
                upper[pref[k]] = k + 1;
            upper[i] = max(upper[i], 1);
            for (int k = i - 1; k >= 1; k--)
                upper[k] = max(upper[k], upper[k + 1]);
            //
            suff[j] = ls[co][j];
            for (int k = j + 1; k <= m; k++)
                suff[k] = max(suff[k - 1], ls[co][k]);
            for (int k = m; k >= j; k--)
                lower[suff[k]] = k - 1;
            lower[i] = min(lower[i], m);
            for (int k = i - 1; k >= 1; k--)
                lower[k] = min(lower[k], lower[k + 1]);
            for (int k = 1; k <= i; k++)
            {
                if (upper[k] > j || lower[k] < j) continue;
                int up = j - upper[k] + 1;
                int dn = lower[k] - j + 1;
                ans += up * dn * (n - i + 1);
            }
            ls[co][j] = i;

        }
    }
    long long tot = (n + 1ll) * (m + 1ll) * n * m;
    return 4. * ans / (tot);
}


int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        printf("%.9f\n", sol());
    return 0;
}
