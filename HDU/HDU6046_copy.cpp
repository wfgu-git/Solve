#include<cstdio>
#include<map>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int maxn=1001;
unordered_map<ll,P>M;
char s[maxn][maxn];
inline unsigned sfr(unsigned h, unsigned x)
{
    return h>>x;
}
int f(ll i, ll j)
{
    ll w=i*1000000ll+j;
    int h=0;
    for(int k=0;k<5;k++)
    {
        h+=(int)((w>>(8*k))&255);
        h+=(h<<10);
        h^=sfr(h,6);
    }
    h+= h<<3;
    h^=sfr(h,11);
    h+=h<<15;
    return sfr(h,27)&1;
}
int Case=1,T;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        for(int i=1;i<=1000;i++)scanf("%s",s[i]+1);
        M.clear();
        for(int i=1;i<=992;i++)
            for(int j=1;j<=992;j++)
            {
                ll temp=0;
                for(int k=0;k<8;k++)
                    for(int l=0;l<8;l++)
                    {
                        temp<<=1;
                        if(s[i+k][j+l]=='1')temp|=1;
                    }
                M[temp]=P(i,j);
            }
        int gg=1;
        for(int i=1;i<=1e6&&gg;i+=984)
            for(int j=1;j<=1e6&&gg;j+=984)
            {
                ll temp=0;
                for(int k=0;k<8;k++)
                    for(int l=0;l<8;l++)
                    {
                        temp<<=1;
                        if(f(i+k,j+l))temp|=1;
                    }
                if(M.find(temp)!=M.end())
                {
                    P ans=M[temp];
                    gg=0;
                    printf("Case #%d :%d %d\n",Case++,i-ans.first+1,j-ans.second+1);
                }
            }
    }
}
