/*************************************************************************
	> File Name: cf729b.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月03日 星期二 22时47分44秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
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
const int maxn=1005;
int a[maxn][maxn];

int main(void)
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    
    int ans=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                cnt++;
            }
            else{
                ans+=cnt;
                cnt=0;
            }
        }
        cnt=0;
        for(int j=m-1;j>=0;j--){
            if(a[i][j]==0){
                cnt++;
            }
            else{
                ans+=cnt;
                cnt=0;
            }
        } 
    }
    for(int j=0;j<m;j++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i][j]==0){
                cnt++;
            }
            else{
                ans+=cnt;
                cnt=0;
            }
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(a[i][j]==0){
                cnt++;
            }
            else{
                ans+=cnt;
                cnt=0;
            }
        } 
    }  
        cout<<ans<<endl;

    return 0;
}
