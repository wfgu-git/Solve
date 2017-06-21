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
int P(int a,int b)
{
    ll ans=1;
    while(b){
        ans*=a--;
        b--;
    }
    return ans; 
}

int main()
{
    ios::sync_with_stdio(false);
    int m,n;
    while(cin>>m>>n){
        cout<<P(n-1,n-1)*P(n,m)<<endl;
    }
    return 0;
}
