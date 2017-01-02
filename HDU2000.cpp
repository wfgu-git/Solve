#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[5050];

int main(void)
{
    string s;
    while(cin>>s)
    {
        int len=s.length();
        for(int i=0;i<len;i++)
            a[i]=s[i];
        sort(a,a+len);
        for(int i=0;i<len;i++){
            if(i)   cout<<" ";
            printf("%c",a[i]);
        }
        cout<<endl;
    }
    return 0;
}
