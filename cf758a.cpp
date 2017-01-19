//a native acmer
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
#include<climits>
#include<utility>
#include<functional>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int n;
int a[110];
int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)  cin>>a[i];
    int maxi=-INF;
    for(int i=0;i<n;i++){
        maxi = (maxi<a[i])?a[i]:maxi;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans+maxi-a[i];
    }
    cout<<ans<<endl;
    return 0;
}
