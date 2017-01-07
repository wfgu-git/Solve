/*************************************************************************
> File Name: HDU2203.cpp
> Author:Prgu 
> Mail:peter.wfgu@gmail.com 
> Created Time: 2017年01月07日 星期六 13时03分52秒
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

//const int maxn=100005;
//int f[maxn];
//
//void getfail(const string& pat,int f[]){
//    f[0]=-1;
//    int j=0,k=-1;
//    while(j<pat.length()-1)
//    if(k==-1||pat[k]==pat[j])
//    f[++j]=++k;
//    else
//    k=f[k];
//} 
//
//int KMP(const string& ob,const string& pat,int p=0)
//{
//    getfail(pat,f);
//    int i=p,j=0;
//    while(i<ob.length()&&j<pat.length()&&pat.length()-j<=ob.length()-i){
//        if(j==-1||pat[j]==ob[i]){
//            i++;j++;
//        }
//        else
//        j=f[j];
//    }
//    if(j<pat.length())    return -1;
//    else    return i-j;
//}
//
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    string a,b;
//    while(cin>>a>>b){
//        string c=a+a; 
//        if(b.length()>a.length())   {cout<<"no"<<endl;continue;}
//        if(KMP(c,b)!=-1){
//            cout<<"yes"<<endl;
//        }
//        else{
//            cout<<"no"<<endl;
//        }
//    }
//    return 0;
//}


const int maxn=100005;
char ob[maxn],pat[maxn],newob[maxn];

int main(void)
{
    while(~scanf("%s",ob)){
        scanf("%s",pat);
        strcpy(newob,ob);
        strcat(newob,ob);
        if(strstr(newob,pat))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
