/*
Life has never been fucking so easy.
Coding...
...WeiFeng
*/
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
#define pq priority_queue
#define iscanf(a) scanf("%d", &a)
#define iscanf2(a,b) scanf("%d%d",&a, &b)
#define iscanf3(a,b,c) scanf("%d%d%d",&a, &b, &c)
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) sort(all(x)); v.erase(unique(all(v)), end())
#define mp(a,b) make_pair(a,b)
#define clr(x,i) memset(x,i,sizeof(x))
#define pb(a) push_back(a)
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
#define rep(i,x,n) for(int i=x;i<n;i++)
#define Max(a,b)  ((a)>(b)?(a):(b))
#define Min(a,b)  ((a)<(b)?(a):(b))
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-8;

//gcd lcm
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int t;
bool used[105];
int New_id() {
	int idx = 0;
	for(int i = 1; i < 105; i++) {
		if(!used[i]) {
			idx = i;
			break;
		}
	}
	return idx;
}

int main(int argc, char const *argv[]) {
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	while(~iscanf(t)) {
		char op[10];
		clr(used, 0);
		for(int i = 0; i < t; i++) {
			scanf("%s", op);
			if(op[0] == 'N') {
				int id = New_id();
				used[id] = true;
				printf("%d\n", id);
			} else if(op[0] == 'D') {
				int del_id;
				iscanf(del_id);
				if(used[del_id] == true) {
					used[del_id] = false;
					printf("Successful\n");
				} else {
					printf("Failed\n");
				}
			}
		}
	}
	return 0;
}


// #include<iostream>
// #include<algorithm>
// #include<stack>
// #include<queue>
// #include<cstdio>
// #include<cctype>
// #include<sstream>
// #include<string>
// #include<functional>
// #include<cstring>
// #include<deque>
// #include<map>
// #include<set>
// #include<vector>
// #include<list>
// #include<cmath>
// #include<ctime>
// #include<cstdlib>
// #define sd1(a) scanf("%d",&a)
// #define sd2(a,b) scanf("%d%d",&a,&b)
// #define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
// #define sf(a) scanf("%lf",&a)
// using namespace std;
// priority_queue<int, vector<int>, greater<int> >que;
// int n;
// string a;
// bool has[1000];
// int main() {
// 	ios::sync_with_stdio(0);
// 	while(cin >> n) {
// 		memset(has, 0, sizeof(has));
// 		int cur = 0;
// 		while(!que.empty())que.pop();
// 		for(int i = 0; i < n; i++) {
// 			int x;
// 			cin >> a;
// 			if(a[0] == 'D') {
// 				cin >> x;
// 				if(has[x]) {
// 					puts("Successful");
// 					has[x] = 0;
// 					que.push(x);
// 				} else puts("Failed");
// 			} else {
// 				if(que.empty()) {
// 					cur++;
// 					cout << cur << endl;
// 					has[cur] = 1;
// 				} else {
// 					int ans = que.top();
// 					que.pop();
// 					cout << ans << endl;
// 					has[ans] = 1;
// 				}
// 			}
// 		}
// //        cout << endl;
// 	}
// 	return 0;
// }
