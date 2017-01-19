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
string bulbs;
int kr,kb,ky,kg;
int idxr,idxb,idxy,idxg;
int cnt[5];
int main(void)
{
    cin>>bulbs;
    int len=(int)bulbs.size();
    for(int i=0;i<len;i++){
        if(bulbs[i]=='!')
            cnt[i%4]++;
        if(bulbs[i]=='R')    idxr=i%4;
        if(bulbs[i]=='B')    idxb=i%4;
        if(bulbs[i]=='Y')    idxy=i%4;
        if(bulbs[i]=='G')    idxg=i%4;
    }
    kr=cnt[idxr],kb=cnt[idxb],ky=cnt[idxy],kg=cnt[idxg];
    cout<<kr<<" "<<kb<<" "<<ky<<" "<<kg<<endl;
    return 0;
}
