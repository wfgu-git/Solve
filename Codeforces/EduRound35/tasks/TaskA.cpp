/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

struct TaskA {
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;

		map<int, vector<int>> mep;
		for (int i = 0; i < n; ++i) {
			int x;
			in >> x;

			mep[x].push_back(i);
		}

		vector<int> & v = mep.begin()->second;
		int ans = 0x3f3f3f3f;
		for (int i = 1; i < v.size(); ++i) {
			ans = min(ans, v[i] - v[i - 1]);
		}
		out << ans << endl;
	}
};
