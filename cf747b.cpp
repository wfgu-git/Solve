/*************************************************************************
	> File Name: cf747b.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月03日 星期二 14时23分21秒
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
    string dna;
    cin>>n>>dna;
    int a=0,c=0,g=0,t=0;
    for(const char & ch : dna){
        if(ch=='A') a++;
        if(ch=='C') c++;
        if(ch=='G') g++;
        if(ch=='T') t++;
    }
    if(a*4>n||c*4>n||g*4>n||t*4>n||n%4!=0) {cout<<"==="<<endl; return 0;}
    int num=n/4;
    int ta=num-a,tg=num-g,tc=num-c,tt=num-t;
    while(ta--){
        for(int i=0;i<n;i++){
            if(dna[i]=='?'){
                dna[i]='A';
                break;
            }
        }
    }
    while(tc--){
        for(int i=0;i<n;i++){
            if(dna[i]=='?'){
                dna[i]='C';
                break;
            }
        }
    }
    while(tg--){
        for(int i=0;i<n;i++){
            if(dna[i]=='?'){
                dna[i]='G';
                break;
            }
        }
    }
    while(tt--){
        for(int i=0;i<n;i++){
            if(dna[i]=='?'){
                dna[i]='T';
                break;
            }
        }
    }     
    cout<<dna<<endl;
    return 0;
}
