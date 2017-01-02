#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int n;
	while (~scanf("%d", &n) && n)
	{
		string color[1005];
		int sum[1005];
		for (int i = 1; i <= n; i++)	sum[i] = 1;
		int  max = 1;
		for (int i = 1; i <= n; i++)	cin >> color[i];
		for (int i = 2; i <= n; i++)
		{
			if (color[i] == color[i - 1])
			{
				sum[i] += sum[i - 1];
				if (sum[i] > sum[max])	max = i;
			}
		}
		cout << color[max] << endl;
	}
	return 0;
}