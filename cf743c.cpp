/*************************************************************************
	> File Name: cf743c.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月04日 星期三 16时15分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<iomanip>
#include<functional>
#include<cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(int argc, char const *argv[])
{
        int n;
        ios::sync_with_stdio(false);
        while (cin >> n)
    {
                if (n == 1)ifprintf("-1\n");
                else
                    cout << n << " " << (n + 1) << " " << n*(n + 1) << endl;
            
    }
        return 0;

}
