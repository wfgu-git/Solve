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

const int maxn = 100010;
int T;
int a[maxn];
int target, n;
//#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	sc(T);
	while(T--) {
		int ans = INF;
		sc2(n, target);
		for(int i = 0; i < n; i++) {
			sc(a[i]);
		}

		int l = 0, r = 1;
		int sum = a[l];
		while(true) {
			printf("[%d, %d) ---> %d\n", l, r, sum);
			while(sum < target && r < n) {
				sum += a[r++];
				printf("[%d, %d) ---> %d\n", l, r, sum);
			}
			if(sum < target)  break;
			ans = min(ans, (r - l));
			//if(l < r)
			sum -= a[l++];
		}
		if(ans == INF)
			printf("0\n");
		else
			pt(ans);
	}
	return 0;
}
