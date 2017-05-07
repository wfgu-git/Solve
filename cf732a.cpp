/*************************************************************************
    > File Name: cf732a.cpp
    > Author:Pr
    > Mail:peter.wfgu@gmail.com
    > Created Time: 2017年01月03日 星期二 13时47分38秒
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
int main(void) {
    ios::sync_with_stdio(false);
    int k, r;
    int cnt = 1;
    cin >> k >> r;
    int kk = k;
    while(k % 10 != 0 && (k - r) % 10 != 0) {
        k = kk * (++cnt);
    }
    cout << cnt << endl;
    return 0;
}
