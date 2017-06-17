#include <bits/stdc++.h>
using namespace std;
const int maxn = 5050;
int n, ans, res;
int bit[maxn];
int a[maxn << 1];

int lowbit(int x) {
	return x & (-x);
}

void update(int idx, int k) {
	while(idx <= n) {
		bit[idx] += k;
		idx += lowbit(idx);
	}

}

int sum(int x) {
	int res = 0;
	while(x > 0) {
		res += bit[x];
		x -= lowbit(x);
	}
	return res;
}

//#define LOCAL_TEST
int main(void) {
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	while(~sc(n)) {
		mset(a, 0), mset(bit, 0);
		ans = 0;
		res = 0;
		for(int i = 1; i <= n; i++) {
			int temp;
			sc(temp);
			a[n + i] = a[i] = temp + 1;
		}
		for(int i = n; i >= 1; i--) {
			res += sum(a[i] - 1);
			update(a[i], 1);
		}

		ans = res;
		int times = n, p = 1;
		while(--times) {
			res -= sum(a[p] - 1);
			update(a[p], -1);
			update(a[p + n], 1);
			res += n - sum(a[p + n]);
			p++;
			//printf("%d\n", res);
			ans = min(ans, res);
		}
		printf("%d\n", ans);
	}
	return 0;
}
