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
#include<climits>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int coef[9];
string x[] = {"x^8", "x^7", "x^6", "x^5", "x^4", "x^3", "x^2", "x"};
string add = " + ";
string sub = " - ";
int main()
{
    ios::sync_with_stdio(false);
    while(cin >> coef[0] >> coef[1] >> coef[2] >> coef[3]
          >> coef[4] >> coef[5] >> coef[6] >> coef[7] >> coef[8]) {
        int first = 0;
        while(!coef[first] && first < 9) first++;
        if(first == 8) {cout << coef[8] << endl; continue;}
        if(first == 9) {cout << 0 << endl; continue;}

        if(coef[first] == 1)    cout << x[first];
        else if(coef[first] == -1)    cout << '-' << x[first];
        else    cout << coef[first] << x[first];
        ++first;

        for(int i = first; i < 8; i++) {
            if(coef[i]) {
                if(coef[i] == 1)    {cout << add << x[i];}
                else if(coef[i] == -1) {cout << sub << x[i];}
                else {
                    if(coef[i] > 1) {cout << add << coef[i] << x[i];}
                    else {cout << sub << abs(coef[i]) << x[i];}
                }
            }
        }

        if(coef[8] > 0) {
            cout << add << coef[8];
        }
        if(coef[8] < 0) {
            cout << sub << abs(coef[8]);
        }
        cout << endl;

    }
    return 0;
}
