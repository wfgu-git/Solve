#include <cstdio>

int main(int argc, char const *argv[])
{
	int n, m;
	while (~scanf("%d%d", &n, &m) && n && m)
	{
		if (n % 2 != 0 && m % 2 != 0)
			printf("What a pity!\n" );
		else
			printf("Wonderful!\n");
	}
	return 0;
}