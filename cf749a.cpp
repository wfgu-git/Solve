/*************************************************************************
    > File Name: cf749a.cpp
    > Author:Pr
    > Mail:peter.wfgu@gmail.com
    > Created Time: 2017年01月02日 星期一 14时40分58秒
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

int main(void)
{
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << endl;
        int t = n / 2;
        for (int i = 0; i < t; i++) {
            if (i)    cout << " ";
            cout << 2;
        }
        cout << endl;
    }
    else {
        int t = (n - 3) / 2;
        cout << t + 1 << endl;
        for (int i = 0; i < t; i++) {
            if (i)    cout << " ";
            cout << 2;
        }
        cout << " " << 3 << endl;
    }
    return 0;
}
