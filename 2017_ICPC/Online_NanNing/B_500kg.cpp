#include<bits/stdc++.h>
using namespace std;
struct node
{
	int pos, num, add;
}t[3000];
int cmp(node a, node b)
{
	if (a.pos == b.pos)
		return a.add < b.add;
	return a.pos < b.pos;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)break;
		int cnt = 0;
		int x, y, a;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &x, &y, &a);
			t[cnt].add = 1;
			t[cnt].pos = x;
			t[cnt++].num = a;
			t[cnt].add = -1;
			t[cnt].pos = y;
			t[cnt++].num = a;
		}
		sort(t, t + cnt, cmp);
		int cur = 0, ans = 0;
		for (int i = 0; i < cnt; i++)
		{
			if (t[i].add == 1)
			{
				cur += t[i].num;
				ans = max(ans, cur);
			}
			else
			{
				cur -= t[i].num;
			}
		}
		cout << ans << endl;
	}
	puts("*");
}
