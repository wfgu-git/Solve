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
const int maxn=1010;
int a1[1010];
int a2[1010];

int main()
{
    int n1,n2;
    while(cin>>n1>>n2){
        for(int i=0;i<n1;i++) cin>>a1[i];
        for(int i=0;i<n2;i++) cin>>a2[i];

        sort(a1,a1+n1);
        sort(a2,a2+n1);
        
        int dist=INF;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                dist=min(dist,abs(a1[i]-a2[j]));
            }
        }
        cout<<dist<<endl;
    }
    return 0;
}
