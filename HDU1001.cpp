#include <iostream>
#include <cstdio>
using namespace std;

// signed int Sum(int n)
// {
// 	return (1 + n) * n / 2;
// }

int main(int argc, char const *argv[])
{
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n, sum;
	while (cin >> n)
	{
		sum = 0;
		for (int i = 1; i <= n; i++)
			sum += i;
		cout << sum << endl << endl;
	}
	return 0;
}