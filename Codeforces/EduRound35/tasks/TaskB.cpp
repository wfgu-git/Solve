/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

struct TaskB {
	void solve(std::istream& in, std::ostream& out) {
		int n, a, b;
		in >> n >> a >> b;

		int ans = -1;
		for (int i = 1; i < n; ++i) {
			ans = max(ans, min(a / i, b / (n - i)));
		}
		out << ans;
	}
};
