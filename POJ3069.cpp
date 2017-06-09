#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[1002];
int main()
{
	ios::sync_with_stdio(false);

	int R, n;
	while (cin >> R >> n){
		if (R == -1 && n == -1) break;
		for (int i = 0; i < n; i++) { cin >> a[i]; }
		sort(a, a + n);
		
		int i = 0, ans = 0;
		while (i < n){
			int uncover = a[i++];
			while (i < n && a[i] <= uncover + R) i++;
			int mark = a[i - 1];
			while (i < n && a[i] <= mark + R) i++;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
