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
#include<utility>
#include<functional>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn=100005;
int a[maxn];
/*
int n,px,x,l,ans;
int main()
{
    cin>>n;
    for(;cin>>x;px=x,(ans=(l>ans)?l:ans))
        (px>x)? l=1:l++;
    cout<<ans<<endl;
    return 0;
}
*/
int l=1;
int main(void)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    int ans=1;
    for(int i=0;i+1<n;i++){
        if(a[i]<=a[i+1])    l++;
        else l=1;
        ans=max(ans,l);
    }
    cout<<ans<<endl;
    return 0;
}
