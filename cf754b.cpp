/*************************************************************************
	> File Name: cf754b.cpp
	> Author:Pr 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 09时55分23秒
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
char pic[4][4];

set<string> ans={"xx.",".xx","x.x","xxx"};

bool inside(int r,int c){
    if(r<0||r>=4||c<0||c>=4)    return false;
    return true;
}

int main(void)
{
    for(int r=0;r<4;r++)    scanf("%s",pic+r);

    //r 
    for(int r=0;r<4;r++){
        string pat1="",pat2="";
        for(int c=0;c<3;c++)    pat1+=pic[r][c];
        for(int c=1;c<4;c++)    pat2+=pic[r][c];
        if(ans.count(pat1)||ans.count(pat2)){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    
    //c
    for(int c=0;c<4;c++){
         string pat1="",pat2="";
        for(int r=0;r<3;r++)    pat1+=pic[r][c];
        for(int r=1;r<4;r++)    pat2+=pic[r][c];
        if(ans.count(pat1)||ans.count(pat2)){
            cout<<"YES"<<endl;
            return 0;
        }
    }
       
    //diagonal
    string dia[9];
    for(int i=1;i<=8;i++)    dia[i]="";

    for(int i=0;i<3;i++){
        dia[1]+=pic[i][i];
        dia[3]+=pic[i][4-i-1];
    }
    for(int i=1;i<4;i++){
        dia[2]+=pic[i][i];
        dia[4]+=pic[i][4-i-1];
    }
    

    for(int i=0;i<3;i++){
        dia[5]+=pic[i][i+1];
        dia[7]+=pic[i][4-i-2];
    }

    for(int i=1;i<4;i++){
        dia[6]+=pic[i][i-1];
        dia[8]+=pic[i][4-i];
    }
    for(int i=1;i<=8;i++){
        if(ans.count(dia[i])){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
