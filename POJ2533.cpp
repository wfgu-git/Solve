#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int inf = 0x3f3f3f3f;
int a[1002];
int dp[1002];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		fill(dp, dp + n, inf);
		for (int i = 0; i < n; i++){
			*lower_bound(dp, dp + n, a[i]) = a[i];
		}		
		cout << lower_bound(dp, dp + n, inf) - dp << endl;
	}
	return 0;
}
