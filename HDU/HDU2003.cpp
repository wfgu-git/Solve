#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	double x;
	while(cin >> x)
		cout << fixed << setprecision(2) << fabs(x) << endl;
	return 0;
}
