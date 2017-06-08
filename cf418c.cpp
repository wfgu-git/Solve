#include <bits/stdc++.h>
using namespace std;

vector< pair< int, char > > v;
const int maxn = 1505;
const int alph_sz = 26;
int ans[alph_sz][maxn];
void solve(const string &s)
{
	memset(ans, 0, sizeof(ans));
	int n = (int)s.size();
	for(int k = 0; k < 26; k++){
		char c = 'a' + k;
		for(int l = 0; l < n; l++){
			int replace_cnt = 0;
			for(int r = l; r < n; r++){
				if(s[r] != c) ++replace_cnt;
				ans[k][replace_cnt] = max(ans[k][replace_cnt], r - l + 1);
			}
		}
		for(int i = 1; i < maxn; i++) 
			ans[k][i] = max( ans[k][i - 1], ans[k][i] );
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	string s;
	cin >> n >> s >> q;
	for(int i = 0; i < q; i++){
		int m;
		char ch;
		cin >> m >> ch;
		v.push_back({m, ch});
	}
	solve(s);
	
	for(auto _pir : v){
		int m = _pir.first;
		int c = _pir.second - 'a';
		cout << ans[c][m] << endl;
	}
	return 0;
}
