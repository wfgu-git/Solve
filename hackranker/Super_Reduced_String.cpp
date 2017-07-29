#include <bits/stdc++.h>

using namespace std;

bool del(string &s) {
	int n = s.size();
	if (n == 1) return false;
	bool flag = false;
	for (int i = 1; i < n; i++) {
		if (s[i - 1] == s[i]) {
			flag = true;
			s.erase(i - 1, 2);
			i -= 1;
			n -= 2;
		}
	}
	return flag;
}
string super_reduced_string(string s){
    // Complete this function
	string ans = s;
	for (int i = 0; i < 50; i++) {
		if (!del(ans))
			break;
	}
	if (ans.size() == 0) ans = "Empty String";
	return ans;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}

