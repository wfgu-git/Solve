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

int main()
{
    int n;
    cin>>n;
    string str="";
    for(int i=0;i<n;i++) {
        char s;
        cin>>s;
        str+=s;
    }
    
    int l=0,r=n-1;
    int sum=0;
    while(l<=r){
        bool left;
        for(int i=0;i+l<=r;i++){
            if(str[i+l]<str[r-i]){
                left=true;
                break;
            }
            else if(str[i+l]>str[r-i]){
                left=false;
                break;
            }
        }
        if(left) putchar(str[l++]);
        else putchar(str[r--]);
        sum++;
        if(sum%80==0)
            printf("\n");
    }
    return 0;
}
