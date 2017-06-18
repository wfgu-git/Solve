#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
int cnt[maxn];
int main()
{
	int n, k, q;
	while (scanf("%d%d%d", &n, &k, &q) == 3) {
		memset(pre, 0, sizeof(pre));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			pre[l]++,pre[r + 1]--;
		}
		for (int i = 1; i <= maxn; i++) {
			cnt[i] = cnt[i - 1] + pre[i];
		}
		for (int i = 0; i <= maxn; i++) cnt[i] = cnt[i] >= k;
		for (int i = 1; i <= maxn; i++) cnt[i] += cnt[i - 1];
		for (int i = 0; i < q; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", cnt[r] - cnt[l - 1]);
		}
	}
	return 0;
}
