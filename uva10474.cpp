#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[10005];

int main(void)
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int n,t,x;
    int kase=0;
    while(~scanf("%d%d",&n,&t)&&n)
    {
        printf("CASE# %d:\n",++kase);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        while(t--)
        {
            scanf("%d",&x);
            int p=lower_bound(a,a+n,x)-a;
            if(a[p]==x)
                printf("%d found at %d\n",x,p+1);
            else
                printf("%d not found\n",x);
        }
    }
    return 0;
}
