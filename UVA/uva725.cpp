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

bool Check(int a, int b) {
	bool num[10] = {false};
	if(b < 10000)  num[0] = true;
	while(a) {
		if(num[a % 10])  return false;
		num[a % 10] = true;
		a /= 10;
	}
	while(b) {
		if(num[b % 10])  return false;
		num[b % 10] = true;
		b /= 10;
	}
	return true;
}

int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	int n, kase = 0;
	while(iscanf(n) && n) {
		if(kase++)  printf("\n");
		bool flag = false;
		for(int i = 1234; i <= 98765 / 2; i++) {
			int d = i * n;
			if(d < 12345)  continue;
			if(d > 98765)  break;
			if(Check(d, i)) {
				flag = true;
				printf("%d / %05d = %d\n", d, i, n);
			}
		}
		if(!flag)  printf("There are no solutions for %d.\n", n);
	}
	return 0;
}

