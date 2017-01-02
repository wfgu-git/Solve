#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int Solver(int a, int b, int n)
{
	// if (F[n] != -1)	return F[n];
	if (n == 1 || n == 2)	return 1;
	if (n >= 3)
		return /*F[n] = */ (a * Solver(a, b, n - 1) + b * Solver(a, b, n - 2)) % 7;
}

int main(int argc, char const *argv[])
{
	int a, b, n;
	while (~scanf("%d%d%d", &a, &b, &n) && (a + b + n))
	{
		// memset(F, -1, sizeof(F));
		cout << Solver(a, b, n % 49) << endl;
	}
	return 0;
}

