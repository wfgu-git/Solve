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

const int maxn = 1010;
int res[maxn];
stack<int> s;
//#define LOCAL_TEST
int main(void)
{
#ifdef LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int N;
	int kase = 0;
	while (cin >> N && N) {
		if (kase++)  printf("\n");
		//init
		mset(res, 0);

		//input
		while (sc(res[1]) && res[1]) {
			while (!s.empty())  s.pop();
			for (int i = 2; i <= N; i++)  sc(res[i]);

			//simulation
			int p = 1;
			for (int i = 1; i <= N; i++) {
				if (res[i] == p)
					p++;
				else if (!s.empty() && res[i] == s.top()) {
					s.pop();
				}
				else {
					if (p > N) break;
					s.push(p++);
					i--;
				}
			}

			bool flag = true;
			if (!s.empty()) {
				int start = N - (int)s.size() + 1;
				for (int i = start; i <= N; i++) {
					if (res[i] != s.top()) {
						//cout<<res[i]<<" "<<s.top()<<endl;
						flag = false;
						break;
					} else {
						//cout<<res[i]<<" "<<s.top()<<endl;
						s.pop();
					}
				}
			}
			if (flag)  printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
