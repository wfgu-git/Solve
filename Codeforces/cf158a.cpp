/*************************************************************************
	> File Name: cf158a.cpp
	> Author:Prgu 
	> Mail:peter.wfgu@gmail.com 
	> Created Time: 2017年01月07日 星期六 18时56分16秒
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
const int maxn=55;
int a[maxn];

int main(void)
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    int mark=a[k];

    if(mark==0){
        while(k){
            if(a[k])
                break;
          k--;
        }
    cout<<k<<endl;
    }
    
    else{
        int ans=k;
        while(k<=n){
            if(mark==a[++k])
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
