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
#define Max(a,b) ((a)>(b)?(a):(b))
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn = 1010;
int cnt[maxn][maxn];
// cnt[row][col]  is the sum of the row from 0-col
int main(int argc, char const *argv[]) {
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	int l, w, r, c;
	iscanf2(l, w);
	mset(cnt, 0);
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			int x;
			iscanf(x);
			cnt[i][j] = x;
			cnt[i][j] += cnt[i][j - 1];
		}
	}
	iscanf2(r, c);
	int ret = -INF, temp;
	for (int i = 1; i <= l - r + 1; i++) {
		for (int j = 1; j <= w - c + 1; j++) {
			temp = 0;
			for (int k = i; k <= i + r - 1; k++) {
				temp = temp + cnt[k][j + c - 1] - cnt[k][j - 1];
			}
			ret = Max(ret, temp);
		}
	}

	// r ^= c;
	// c ^= r;
	// r ^= c;
	// for (int i = 1; i <= l - r + 1; i++) {
	// 	for (int j = 1; j <= w - c + 1; j++) {
	// 		temp = 0;
	// 		for (int k = i; k <= r; k++) {
	// 			temp = temp + cnt[k][j + c - 1] - cnt[k][j - 1];
	// 		}
	// 		ret = Max(ret, temp);
	// 	}
	// }

	printf("%d\n", ret);
	return 0;
}
