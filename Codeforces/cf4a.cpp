/*************************************************************************
    > File Name: cf4a.cpp
    > Author:Prgu
    > Mail:peter.wfgu@gmail.com
    > Created Time: 2017年01月06日 星期五 22时23分35秒
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
int main(void)
{
    int n;
    cin >> n;
    if (n == 1 || n == 2 || n == 3) {
        cout << "NO" << endl;
        return 0;
    }
    if (n % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
