#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 2;
int a[maxn], dp[maxn], l[maxn], r[maxn];
int w[maxn][maxn];
bool vis[maxn];
int get_sum(int l, int r)
{
	int ret = 0;
	map < int, bool > used;
	for (int i = l; i <= r; i++) {
		if (used[a[i]]) continue;
		ret ^= a[i];
		used[a[i]] = true;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	memset(l, -1, sizeof(l));
	set < int > num;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		num.insert(x);
		a[i] = x;
		if (l[x] == -1) 
			l[x] = i, r[x] = i;
		else 
			r[x] = i;
	}

	memset(vis, 0, sizeof(vis));
	memset(w, -1, sizeof(w));
	for (int i = 1; i <= n; i++) {
		const int x = a[i];
		if (vis[x]) continue; 
		vis[x] = true;
		int L = l[x];
		int R = r[x];
		for (int j = L; j <= R; j++) {
			L = min(L, l[a[j]]);
			R = max(R, r[a[j]]);	
		}
		l[x] = L;
		r[x] = R;
		w[L][R] = get_sum(L, R);
	}	
		
	memset(dp, 0, sizeof(dp));
	int ret = -1;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i]);
		for (int j = 0; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + w[j + 1][i]);
		}
		ret = max(ret, dp[i]);
	}
	cout << ret << endl;
	return 0;
}
