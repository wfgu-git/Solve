#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	int n, m;
	cin >> T;
	cin.get();
	while (T--)
	{
		cin >> n >> m;
		if (n % (m + 1))	cout << "first" << endl;
		else
			cout << "second" << endl;
	}
	return 0;
}