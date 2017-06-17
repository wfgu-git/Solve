#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;
	while (~scanf("%d%d", &a, &b))
	{
		int aa = min(a, b);
		int bb = max(a, b);
		int k = bb - aa;
		int ans = k * (1 + sqrt(5)) / 2;
		if (aa == ans)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}