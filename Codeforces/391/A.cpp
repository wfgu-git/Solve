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

string str;
int find(int ch)
{
    int cnt=0;
    for(const char &c : str){
        if(c==ch) cnt++;
    }
    return cnt;
}

int main()
{
    cin>>str;
    int B=find('B'),u=find('u')/2,l=find('l'),b=find('b'),a=find('a')/2,s=find('s'),r=find('r');
    int ans=min(B,u);
    ans=min(ans,l);
    ans=min(ans,b);
    ans=min(ans,a);
    ans=min(ans,s);
    ans=min(ans,r);
    cout<<ans<<endl;
    
    return 0;
}
