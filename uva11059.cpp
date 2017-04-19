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
typedef long long ll;
//typedef __int64 i64;
typedef unsigned long long ull;
typedef priority_queue<int, vector<int>, greater<int> > pq_int;
typedef priority_queue<PII, vector<PII>, greater<PII> > pq_PII;
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
#define Max(a,b)  ((a)>(b)?(a):(b))
#define Min(a,b)  ((a)<(b)?(a):(b))
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;


int a[20];
vector<ll> product;
int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	int n, kase = 0;
	while(iscanf(n) != EOF) {
		product.clear();
		for(int i = 0; i < n; i++) {
			iscanf(a[i]);
		}
		for(int be = 0; be < n; be++) {
			for(int ed = be; ed < n; ed++) {
				ll res = 1;
				for(int i = be; i <= ed; i++) {
					res *= a[i];
				}
				product.push_back(res);
			}
		}
		vector<ll>::iterator Max_product = max_element(product.begin(), product.end());
		ll ans = *Max_product;
		if(ans < 0)  ans = 0;
		printf("Case #%d: The maximum product is %lld.\n", ++kase, ans);
		printf("\n");
	}
	return 0;
}

