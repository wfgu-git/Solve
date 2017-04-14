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
#define cntOne(x) __builtin_popcount(x)
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


int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	double pi = 3.14159265359;
	int T;
	iscanf(T);
	while (T--) {
		// int A;
		// iscanf(A);
		// printf("%.2f\n", cos(A) );
		double A, b, c, res;
		scanf("%lf%lf%lf", &b, &c, &A);
		res = sqrt(b * b + c * c - 2.0 * b * c * cos(A / 180.0 * pi));
		printf("%.2f\n", res);
	}
	return 0;
}
