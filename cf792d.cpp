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
#define pt(a) printf("%d\n",a)
#define ptlld(a) printf("%lld\n",a)
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

ll lowbit(ll x)
{
	return x & (-x);
}

int main(void)
{
	ll n, q;
	cin >> n >> q;
	string op;
	while(q--) {
		ll start_num;
		cin >> start_num >> op;
		ll root_num = (n + 1) / 2, op_num = op.length();
		ll num = start_num;
		for(int i = 0; i < op_num; i++) {
			if(op[i] == 'U') {
				if(num == root_num)  continue;
				ll sec_lbs = lowbit(num) * 2;
				num -= lowbit(num);
				if(lowbit(num) == sec_lbs)  continue;
				num += sec_lbs;
			} else if(op[i] == 'L') {
				if(lowbit(num) == 1)  {
					//cout << num;
					continue;
				}
				num = num - lowbit(num) + lowbit(num) / 2;
				//cout << num;
			} else if(op[i] == 'R') {
				num = num + lowbit(num) / 2;
				//cout << num;
			}
		}
		cout << num << endl;
	}
	return 0;
}


/*
3 1
1
ULRUULURLULLLLLLRLL
*/
