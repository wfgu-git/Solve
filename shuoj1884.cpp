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
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mp(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 1e5;
int a[maxn];
int bit[maxn];
int N, m;
int lowbit(int x)
{
	return x & (-x);
}

void add(int idx, int v)
{
	while (idx <= N) {
		bit[idx] += v;
		idx += lowbit(idx);
	}
}

int GetSum(int idx)
{
	int res = 0;
	while (idx > 0) {
		res += bit[idx];
		idx -= lowbit(idx);
	}
	return res;
}

int GetValue(int idx) {
	return GetSum(idx) - GetSum(idx - 1);
}
int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	sc2(N, m);
	for (int i = 1; i <= N; i++)  sc(a[i]);
	//build
	for (int i = 1; i <= N; i++) {
		bit[i] = a[i];
		for (int j = i - 1; j > i - lowbit(i); j--) {
			bit[i] += a[j];
		}
	}

	for (int i = 0; i < m; i++) {
		int mark, a, b;
		sc3(mark, a, b);
		if (mark == 1) {
			add(a, b);
		} else if (mark == 2)
			printf("%d\n", GetSum(b) - GetSum(a - 1));
	}
	return 0;
}
