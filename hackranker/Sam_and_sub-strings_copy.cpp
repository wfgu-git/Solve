#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long LL;

#define MOD7 1000000007


string str;

int main()
{

    cin>>str;
    int l = str.length();
    LL outp = str[0] - '0'; // output stored in it.
    LL temp = str[0] - '0'; // sum of all strings ending at index i is stored in this string
    for(int i=1 ; i< l ; i++)
    {
        temp = temp*10 + (i+1)*(str[i] - '0');
        temp = temp%MOD7;
        outp = (outp +temp)%MOD7;
    }
        cout<<outp<<endl;
    return 0;
}
