#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f
#define ll long long
#define ms(x) memset(x, 0, sizeof(x))
using namespace std;

int main()
{
    int n, f;
    ll k;
    ll a[100005];
    ll sum[100005];
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%lld",&n,&k);
    ms(a);
    ms(sum);
    int ma = 0,t=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1] + a[i];
        if(ma<a[i])
        {
            ma = a[t = i];
        }
    }
    ll x = n+ma-1;     // 其他人吃1个，吃货吃a[t]个
    ll y = sum[n];     // 每个人都吃a[i]个       x,y就是每一轮人们吃的最少和最多的量
    if(k == 0)
    {
        if(t == 1) f=1;
        else f=0;
    }
    else
    {
        f=0;
        int i  =0;       //i从0开始， 因为第一轮不会都吃到蛋糕嘛
        while(1)
        {
            if((ll)i*x + t-1 > k) break;
            if((ll)i*y + sum[t-1]>=k)
            {
                f=1;
                break;
            }
            i++;
        }
    }
    if(f) printf("YES\n");
    else printf("KEK\n");
    return 0;
}
