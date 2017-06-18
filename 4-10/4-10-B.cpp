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
#define rep(i,x,n) for(int i=x;i<n;i++)
#define Min(a,b) ((a)<(b)?(a):(b))
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

// struct Seat {
// 	int index, dist;
// 	Seat(int _idx, int _dis): index(_idx), dist(_dis) {}
// };
// bool cmp(Seat a, Seat b) {
// 	if (a.dist == b.dist)  return a.index < b.index;
// 	return  a.dist < b.dist;
// }
vector<int> idx;
//vector<Seat> s;

int solve(int x, int n) {
	return Min(x - 1, n - x);
}

int main(int argc, char const *argv[]) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		idx.clear();
		// s.clear();
		int n;
		string str = "";
		cin >> n >> str;
		str = 'P' + str;
		n++;
		for(int i = 0; i < n; i++) {
			if(str[i] == 'E' && i + 1 < n && str[i + 1] == 'E' || str[i] == 'E' && i - 1 >= 0 && str[i - 1] == 'E') {
				idx.push_back(i);
			}
		}
		if(idx.size() == 0) {
			cout << -1 << endl;
		} else {
			int res = solve(idx[0], n - 1);
			for(int i = 0; i < (int)idx.size(); i++) {
				if(solve(res, n - 1) < solve(idx[i], n - 1))
					res = idx[i];
			}

			cout << res - 1 << endl;
		}
	}
	return 0;
}
