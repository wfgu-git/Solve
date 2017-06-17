#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <iomanip>
#include <cctype>
#include <climits>
#include <utility>
#include <memory>
#include <functional>
using namespace std;
typedef long long ll;
// typedef __int64 ll;
typedef pair<int, int> PII;
#define iscanf(a) scanf("%d",&a)
#define iscanf2(a,b) scanf("%d%d",&a,&b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mp(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 20;
int n;
int a[maxn];
int res;
int ans[maxn];
bool is_hit(int a[], int n)
{
	for (int i = 1; i < n; i++) {
		if (a[i] == a[n] || abs(a[i] - a[n]) == abs(i - n))
			return true;
	}
	return false;
}

void dfs(int row, int n)
{
	for (int col = 1; col <= n; col++) {
		a[row] = col;
		if (!is_hit(a, row)) {
			if (row < n)
				dfs(row + 1, n);
			else
				res++;
		}
	}
}

int main(int argc, char const *argv[])
{
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	for (int i = 1; i <= 10; i++) {
		res = 0;
		for (int i = 1; i <= n; i++)  a[i] = 0;
		dfs(1, i);
		ans[i] = res;
	}
	while (iscanf(n) != EOF && n) {
		printf("%d\n", ans[n]);
	}
	return 0;
}
