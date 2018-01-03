/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

struct TaskC {
	void solve(std::istream& in, std::ostream& out) {
		int k[2000] = {0};
		for (int i = 0; i < 3; ++i) {
			int ki;
			in >> ki;
			k[ki]++;
		}

		if (k[1] || k[2] >= 2 || k[3] == 3 || (k[2] == 1 && k[4] == 2)) {
			out << "YES";
		} else {
			out << "NO";
		}
	}
};
