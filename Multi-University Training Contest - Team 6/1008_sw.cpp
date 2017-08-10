#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<sstream>
#include<string>
#include<cstring>
#include<deque>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#define sf(a) scanf("%lf",&a)
#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf(a) scanf("%lf",&a)
#define sf2(a,b) scanf("%lf%lf",&a,&b)
#define mp(a,b) make_pair(a,b)
#define maxn 5003
using namespace std;
typedef long long ll;
int m,n;
char s[maxn<<1];
int maxi;
void solve(int center){
    int l = 0,r = n-1;
    if((center&1)==0){
        int c = center/2;
        if(c<=(n-1)/2) r = c*2;
        else   l = c*2-r;
    }else{
        if(center<n)r = center;
        else l = center-n+1;
    }
    int len = 1;
    int cur = abs(s[r]-s[l]);
    int curr = r, curl = l;
    while(1){
        if(cur>m){
            cur-=abs(s[r]-s[l]);
            r--;l++;
            curr--;curl++;
            if(curr<=curl)break;
            cur+=abs(s[curr]-s[curl]);
        }else{
            maxi = max(maxi,len);
            curr--;curl++;
            if(curr<=curl)break;
            cur+=abs(s[curr]-s[curl]);
            len++;
        }
    }
}
int main(){
    int T;
    sd1(T);
    while(T--){
        maxi = 0;
        sd1(m);
        scanf("%s",s);
        n = (int)strlen(s);
        for(int center = 1; center<=(n-1)*2-1; center++)
            solve(center);
        printf("%d\n",maxi);
    }
    return 0;
}
