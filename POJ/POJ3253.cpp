#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n){
		priority_queue< ll, vector<ll>, greater<ll> > q;
		for (int i = 0; i < n; i++) {  
			int x;
			cin >> x;
			q.push(x);
		}
		ll ans = 0;
		while (q.size() > 1){
			ll x1 = q.top();
			q.pop();
			ll x2 = q.top();
			q.pop();
			ans += (x1 + x2);
			q.push(x1 + x2);
		}	
		cout << ans << endl;
	}
	return 0;
}
