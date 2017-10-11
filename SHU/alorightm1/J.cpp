/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 20;

int n, ret;
int a[maxn];
bool hit(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] == a[n] || abs(a[i] - a[n]) == abs(i - n))
			return true;
	}
	return false;
}
void dfs(int row, int n) {
	for (int col = 1; col <= n; col++) {
		a[row] = col;
		if (!hit(a, row)) {
			if (row < n)
				dfs(row + 1, n);
			else
				ret++;
		}
	}
}
// int main() {
// 	for (int i = 1; i <= 15; i++) {
// 		ret = 0;
// 		for (int i = 1; i <= n; i++)  a[i] = 0;
// 		dfs(1, i);
// 		ans[i] = ret;
// 	}
//   int kase = 0;
//   while (~scanf("%d", &n)) {
//     printf("Case %d: n=%d\n", ++kase, n);
//     printf("Total: %d\n\n", ans[n]);
//   }
// }
int ans[20] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184, 14772512};
int main() {
  int kase = 0;
  while (~scanf("%d", &n)) {
    printf("Case %d: n=%d\n", ++kase, n);
    printf("Total: %d\n\n", ans[n]);
  }
}
