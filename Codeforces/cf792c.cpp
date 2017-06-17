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

void del_pre_zero(string &s)
{
	if(s == "")  return;

	while(s[0] == '0') {
		s = s.substr(1, s.length() - 1);
	}
	if(s == "")  s += '0';
}
int a[10];
int main(void)
{
	ios::sync_with_stdio(false);
	string num, tmp1, tmp2;
	bool flag1, flag2;
	flag1 = flag2 = false;
	int sum, len;
	cin >> num;
	tmp1 = tmp2 = num;
	len = num.size(), sum = 0;
	for(const char &c : num) {
		sum += (c - '0');
		a[(c - '0')]++;
	}
	int remainder = sum % 3;
	if(remainder == 0) {
		del_pre_zero(num);
		cout << num << endl;
		return 0;
	} else if(remainder == 1) {
		if(a[1] + a[4] + a[7] < 1 && a[2] + a[5] + a[8] < 2) {
			cout << -1 << endl;
			return 0;
		} else {
			if(a[1] || a[4] || a[7]) {
				flag1 = true;
				for(int i = len - 1; i >= 0; i--) {
					if(tmp1[i] == '1' || tmp1[i] == '4' || tmp1[i] == '7') {
						tmp1[i] = '.';
						break;
					}
				}
			}
			if(a[2] + a[5] + a[8] >= 2) {
				flag2 = true;
				int cnt = 0;
				for(int i = len - 1; i >= 0; i--) {
					if(cnt == 2) break;
					if(tmp2[i] == '2' || tmp2[i] == '5' || tmp2[i] == '8') {
						tmp2[i] = '.';
						cnt++;
					}
				}
			}
		}
	} else if(remainder == 2) {
		if(a[2] + a[5] + a[8] < 1 && a[1] + a[4] + a[7] < 2) {
			cout << -1 << endl;
			return 0;
		} else {
			if(a[2] || a[5] || a[8]) {
				flag1 = true;
				for(int i = len - 1; i >= 0; i--) {
					if(tmp1[i] == '2' || tmp1[i] == '5' || tmp1[i] == '8') {
						tmp1[i] = '.';
						break;
					}
				}
			}
			if(a[1] + a[4] + a[7] >= 2) {
				flag2 = true;
				int cnt = 0;
				for(int i = len - 1; i >= 0; i--) {
					if(cnt == 2) break;
					if(tmp2[i] == '1' || tmp2[i] == '4' || tmp2[i] == '7') {
						tmp2[i] = '.';
						cnt++;
					}
				}
			}
		}
	}
	//cout<< num <<endl;
	string res1, res2, res;
	res1 = res2 = "";
	for(int i = 0; i < len; i++) {
		if(tmp1[i] == '.')  continue;
		res1 += tmp1[i];
	}
	for(int i = 0; i < len; i++) {
		if(tmp2[i] == '.')  continue;
		res2 += tmp2[i];
	}
	del_pre_zero(res1), del_pre_zero(res2);
	if(flag1 && !flag2)  res = res1;
	else if(!flag1 && flag2)  res = res2;
	else res = res1.size() > res2.size() ? res1 : res2;
	if(res == "")  cout << -1 << endl;
	else  cout << res << endl;
	return 0;
}
