#include <bits/stdc++.h>
using namespace std;
const int n = 16;
int upper_limit = (1 << n) - 1;
int res;

void dfs(int row, int ld, int rd)
{
	int pos, p;
	if (row != upper_limit)  {
		pos = upper_limit & ~(row | ld | rd);
		while (pos != 0) {
			p = pos & (-pos);  // the position p is used
			pos = pos ^ p;     // del potition p from pos
			dfs(row | p, (ld | p) << 1, (rd | p) >> 1);
		}
	} else {
		++res;
	}
}

int main(int argc, char const *argv[])
{
	dfs(0, 0, 0);
	return 0;
}
