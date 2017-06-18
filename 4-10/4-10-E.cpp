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

map<char, int> f;
bool flag;
// prior
// 0	-1	1
// =	<	>
// op1 --> stack.top()_operator
// op2 --> cur_operator
int Operator_Priority(char op1, char op2)
{
	if(op1 == '(')
		return -1;
	if(op1 == '+' || op1 == '-') {
		if(op2 == '*' || op2 == '/')
			return -1;
		else
			return 0;
	}
	if(op1 == '*' || op1 == '/') {
		if(op2 == '+' || op2 == '-')
			return 1;
		else
			return 0;
	}
	return 0;
}

bool isOperator(char c)
{
	if(c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/')  return true;
	return false;
}

string To_Post(const string &str)
{
	stack<char>  optr;
	int n = (int)str.length();
	string res = "";

	for(int i = 0; i < n; i++) {
		char curChar = str[i];

		if(!isOperator(curChar)) {  // is A 2 3 ... J Q K
			res += curChar;
		} else { // is + - * / ( )
			if(curChar == '(') {
				optr.push(curChar);
			} else if(curChar == ')') {
				while(!optr.empty()) {
					char tempOp = optr.top(); optr.pop();
					if(tempOp == '(')
						break;
					else
						res += tempOp;
				}
			} else {
				while(!optr.empty() && Operator_Priority(optr.top(), curChar) >= 0) {
					res += optr.top();
					optr.pop();
				}
				optr.push(curChar);
			}
		}

	}
	while(!optr.empty()) {
		res += optr.top();
		optr.pop();
	}
	return res;
}
double NaiveCalc(char op, double x1, double x2)
{
	double res;
	switch(op) {
	case '+': res = x1 + x2; break;
	case '-': res = x1 - x2; break;
	case '*': res = x1 * x2; break;
	case '/':
		if(x2 == 0) { res = 999.99; flag = true;}
		else  res = x1 / x2;
		break;
	}
	return res;
}
stack<double> calc;
int main(int argc, char const *argv[])
{
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	for(int i = 2; i <= 9; i++) f[i + '0'] = i;
	f['A'] = 1, f['D'] = 10, f['J'] = 11, f['Q'] = 12, f['K'] = 13;

	string str;
	while(cin >> str) {
		while(!calc.empty())  calc.pop();
		flag = false;
		int strLen = (int)str.size();
		for(int i = 0; i < strLen; i++) {
			if(str[i] == '1' && str[i + 1] == '0') {
				str[i] = 'D';
				str.erase(i + 1, 1);
			}
		}

		string newStr = To_Post(str);
		// cout << newStr << endl;

		for(const char ch : newStr) {
			if(!isOperator(ch)) {
				calc.push((double)f[ch]);
			} else {
				char op = ch;
				double x1, x2;
				x2 = calc.top(); calc.pop();
				x1 = calc.top(); calc.pop();
				calc.push(NaiveCalc(op, x1, x2));
			}
		}
		if(flag)  cout << "No" << endl;
		else {
			double res = calc.top();
			// cout << res << endl;
			if(res > 0 && fabs(res - 24) < 0.001)  cout << "Yes" << endl;
			else  cout << "No" << endl;
		}
	}
	return 0;
}

