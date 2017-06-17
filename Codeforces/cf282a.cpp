/*************************************************************************
    > File Name: cf282a.cpp
    > Author:Prgu
    > Mail:peter.wfgu@gmail.com
    > Created Time: 2017年01月07日 星期六 17时49分32秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
char str[3];

int main(void)
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (strstr(str, "++"))    ans++;
        if (strstr(str, "--"))    ans--;
    }
    cout << ans << endl;
    return 0;
}
