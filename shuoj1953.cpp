#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 50;
int blk[maxn], blk_sz;
struct interval {
	int l, r;
	int id;

	bool operator < (const interval &rhs) const {
		if (blk[l] == blk[rhs.l])
			return r < rhs.r;
		return blk[l] < blk[rhs.l];
	}

	interval() {}
	interval(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
} qry[maxn];
int a[maxn], ans[maxn], cnt[maxn];
int cnt_odd;
void add(int x)
{
	cnt[x]++;
	if (cnt[x] & 1) cnt_odd++;
	else cnt_odd--;
}
void del(int x)
{
	cnt[x]--;
	if (cnt[x] & 1) cnt_odd++;
	else cnt_odd--;
}
int main()
{
//	ios::sync_with_stdio(false);

	int kase;
	scanf("%d", &kase);
	for (int t = 1; t <= kase; t++) {
		int n, m;
		scanf("%d%d", &n, &m);
		blk_sz = ceil(sqrt(1.0 * n));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			blk[i] = (i - 1) / blk_sz;	
		}	
		for (int i = 0; i < m; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			qry[i] = interval(l, r, i);	
		}
		sort(qry, qry + m);
		
		int l = 1;
		int r = 0;
		cnt_odd = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < m; i++) {
			const int cur = qry[i].id;
			const int ql = qry[i].l;
			const int qr = qry[i].r;
			
			while (r < qr) add(a[++r]);
			while (r > qr) del(a[r--]);
			while (l < ql) del(a[l++]);
			while (l > ql) add(a[--l]);
				
			ans[cur] = cnt_odd < 2;
		}	
		printf("Case %d:\n", t);
		for (int i = 0; i < m; i++) {
			if (ans[i]) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
