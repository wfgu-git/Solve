#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n){
		string s = "";
		for (int i = 0; i < n; i++){
			char ch;
			cin >> ch;
			s.push_back(ch);	
		}
		string ans = "";
		string revs(s.rbegin(), s.rend());
		int p = 0, q = 0;
		while (p + q < n){
			bool left;
			for (int i = 0; i + max(p, q) < n; i++){
				if (s[p + i] < revs[q + i]) {
					left = true;
					break;
				}
				else if (s[p + i] > revs[q + i]) {
					left = false;
					break;
				}
			}	

			if (left) ans.push_back(s[p++]);
			else ans.push_back(revs[q++]);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++){
			cout << ans[i];
			cnt++;
			if (cnt % 80 == 0) cout << endl;
		}
	}
	return 0;
}
