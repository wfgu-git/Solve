#include <iostream>
#include <set>
using namespace std;

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		string str;
		in >> str;

    string s = "aeiou13579";
    set<char> Set = {s.begin(), s.end()};

    int ans = 0;
    for (char & ch : str) {
      if (Set.find(ch) != Set.end()) {
        ++ans;
      }
    }
    out << ans;
	}
};
