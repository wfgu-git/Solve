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
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pr(a) printf("%d\n",a)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define mset(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
#define lch l,m,rt<<1
#define rch m+1,r,rt<<1|1
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;

const int maxn=50010;
int color[maxn];
int pos[maxn];
int n,m;
int block_size,block_id;
ll num[maxn],up[maxn],down[maxn];
//num  存color[i]的个数
//up   存结果的分子
//down 存结果的分母
ll ans,aa,bb,cc;
struct Node{
    int l,r;
    int block_id;
}qry[maxn];
bool cmp(Node a, Node b)
{
    //先按所在块升序
    //再按R升序
    if(pos[a.l] == pos[b.l]){
        return a.r < b.r;
    } else {
        return pos[a.l] < pos[b.l]; 
    }
}

//[L,R] --> [L,R+/-1] [L+/-1,R] O(1)
void update(int x, int d)
{
    ans -= num[color[x]] * num[color[x]];
    num[color[x]] += d;
    ans += num[color[x]] * num[color[x]];
}

ll gcd(ll a, ll b)
{
    ll temp;
    while((temp = a%b)){
        a = b;
        b = temp;
    }
    return b;
}

int main(void)
{
    sc2(n,m);
    block_size = ceil(sqrt(n));
    for(int i=1; i<=n; i++){
        sc(color[i]);    
        pos[i]=(i-1)/block_size;
        //[Li,Ri]在第几块
    }

    for(int i=0; i<m; i++){
        sc2(qry[i].l,qry[i].r); 
        qry[i].block_id = i;
    }
    //将查询的区间排序
    sort(qry,qry+m,cmp);

    int pl,pr;
    pl = 1;
    pr = 0;
    for(int i=0; i<m; i++){
        block_id = qry[i].block_id;
        //区间长度为1时 肯定是0/1 袜子得两只。。。
        if(qry[i].l == qry[i].r){
            up[block_id] = 0;
            down[block_id] = 1;
        }

        if(pr < qry[i].r){
            for(int j=pr+1; j<=qry[i].r; j++){
                update(j,1);
            }
        } else{
            for(int j=pr; j>qry[i].r; j--){
                update(j,-1);
            }
        }

        pr = qry[i].r;
        if(pl < qry[i].l){
            for(int j=pl; j<qry[i].l; j++){
                update(j,-1);
            }
        } else{
            for(int j=pl-1; j>=qry[i].l; j--){
                update(j,1);
            }
        }
        pl = qry[i].l;
        //用组合数来计算概率
        aa = ans - qry[i].r + qry[i].l - 1;
        bb = (ll)(qry[i].r - qry[i].l + 1) *(qry[i].r - qry[i].l);
        cc = gcd(aa,bb); //cc用来成 最简分数
        aa /= cc, bb /= cc;
        up[block_id] = aa;
        down[block_id] = bb;
    }
    //output
    for(int i=0; i<m; i++){
        printf("%lld/%lld\n",up[i],down[i]);
    }
    return 0;
}
