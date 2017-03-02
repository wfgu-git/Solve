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
#define sc3(a,c,b) scanf("%d%d%d",&a,&b,&c)
#define pt(a) printf("%d\n",a)
#define ptlld(a) printf("%lld\n",a)
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

const int maxn = 500050;
int a[maxn];
ll ans;
void merge_array(int a[], int left, int mid, int right, int temp[])
{
	int i = left, j = mid + 1, k = 0;
	int m = mid, n = right;

	while(i <= m && j <= n) {
		if(a[i] > a[j]) {
			temp[k++] = a[j++];
			ans += mid - i + 1;
		} else {
			temp[k++] = a[i++];
		}
	}

	while(i <= m)  temp[k++] = a[i++];
	while(j <= n)  temp[k++] = a[j++];

	for(int i = 0; i < k; i++) {
		a[i + left] = temp[i];
	}
}

void merge_sort(int a[], int left, int right, int temp[])
{
	if(left >= right) {
		return ;
	}
	int mid = left + (right - left) / 2;
	merge_sort(a, left, mid, temp);
	merge_sort(a, mid + 1, right, temp);
	merge_array(a, left, mid, right, temp);
}

void MergeSort(int a[], int n)
{
	int *p = new int[n];
	if(p == NULL)  return;
	merge_sort(a, 0, n - 1, p);
	delete []p;
	return ;
}
//#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int n;
	while(sc(n) && n) {
		ans = 0;
		for(int i = 0; i < n; i++) {
			sc(a[i]);
		}
		MergeSort(a, n);
		printf("%lld\n", ans);
	}
	return 0;
}
