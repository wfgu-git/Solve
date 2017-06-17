/*************************************************************************
    > File Name: cf752b.cpp
    > Author:Pr
    > Mail:peter.wfgu@gmail.com
    > Created Time: 2017年01月04日 星期三 16时11分48秒
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

map<char, char> mix;
set<pair<char, char>> s;
int main(void)
{
    ios::sync_with_stdio(false);
    string fav, cmp;
    while (cin >> fav)
    {
        int cnt = 0;
        bool flag = 1;
        cin >> cmp;
        mix.clear();
        for (int i = 0; i < (int)fav.size(); i++)
        {
            if ((mix[fav[i]] != 0 || mix[cmp[i]] != 0) && (mix[fav[i]] != cmp[i] || mix[cmp[i]] != fav[i])) {
                flag = false;
                break;

            }
            if (mix[fav[i]] == 0)
            {
                if (fav[i] != cmp[i]) cnt++;
                mix[fav[i]] = cmp[i];
                mix[cmp[i]] = fav[i];

            }

        }

        if (!flag)   cout << -1 << endl;
        else
        {
            cout << cnt << '\n';
            for (char t = 'a'; t <= 'z'; t++)
            {
                if (mix[t] != 0 && mix[t] != t)
                {
                    cout << t << " " << mix[t] << endl;
                    mix[mix[t]] = 0;

                }

            }

        }

    }
    return 0;

}
