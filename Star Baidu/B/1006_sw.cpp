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
#define maxn 100005
using namespace std;
typedef long long ll;
int n,m;
struct P{
    int l, r;
    bool operator < (const P& oth)const{
        return l < oth.l;
    }
}p[maxn];
int main(){
    while(sd2(n, m)==2){
        for(int i = 0; i <n ; i++){
            sd2(p[i].l, p[i].r);
        }
        sort(p,p+n);
        int cur = p[0].r,need = 0;
        int l = 0,r = -1;
        int maxi = 0;
        int ans = 0;
        while(r+1<n){
            if(cur<p[r+1].l){
                int gap = p[r+1].l-cur-1;
                if(need+gap<=m){
                    r++;
                    cur = max(cur,p[r].r);
                    need+=gap;
                    if(maxi <= cur-p[l].l){
                        maxi = cur-p[l].l;
                        ans = max(ans,maxi+m-need);
                    }
                }else{
                    need-=max(0,(p[l+1].l-p[l].r-1));
                    l++;
                }
            }else{
                cur = max(p[r+1].r,cur);r++;
                if(maxi <= cur-p[l].l){
                    maxi = cur-p[l].l;
                    ans = max(ans,maxi+m-need);
                }
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
