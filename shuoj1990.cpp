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

char f(char c)
{
    if(!(c>='a'&&c<='z')) return c;
    char res;
    if(c>='a'&&c<='c') res='2';
    else if(c<='f') res='3';
    else if(c<='i') res='4';
    else if(c<='l') res='5';
    else if(c<='o') res='6';
    else if(c<='s') res='7';
    else if(c<='v') res='8';
    else if(c<='z') res='9';
    return res;
}

void solve(string& str)
{
    for(int i=0;i<8;i++)
        if(str[i]>='A'&&str[i]<='Z')
            str[i]+=32;
    
    string tmp="";
    for(int i=0;i<4;i++){
        char ch=f(str[i]);
        tmp+=ch;
    }
    tmp+='-';
    for(int i=4;i<8;i++){
        char ch=f(str[i]);
        tmp+=ch;
    }
    str=tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        solve(str);
        cout<<str<<endl;
    }
    return 0;
}
