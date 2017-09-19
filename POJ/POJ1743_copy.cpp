#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int t1[MAXN],t2[MAXN],c[MAXN];

bool cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int str[],int sa[],int ra[],int height[],int n,int m)
{
    n++;
    int i,j,p,*x=t1,*y=t2;
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=str[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        for(i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p>=n) break;
        m=p;
    }
    int k=0;
    n--;
    for(i=0;i<=n;i++) ra[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k) k--;
        j=sa[ra[i]-1];
        while(str[i+k]==str[j+k])k++;
        height[ra[i]]=k;
    }
}
int ra[MAXN],height[MAXN];
int sa[MAXN];
int str[MAXN];
int n;
int check(int k)
{
    int minsa=0,maxsa=0;
    for(int i=1;i<=n;i++)
    {
        if(height[i]<k) {
            minsa=sa[i];maxsa=sa[i];
        }
        else
        {
            minsa=min(minsa,sa[i]);
            maxsa=max(maxsa,sa[i]);
            if(maxsa-minsa>=k) return 1;
        }
    }
    return 0;
}

int main()
{
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
    while(scanf("%d",&n)!=EOF&&n)
    {
    for(int i=0;i<n;i++)
        scanf("%d",&str[i]);
    for(int i=0;i<n-1;i++)
        str[i]=str[i+1]-str[i]+100;
    str[--n]=0;
    da(str,sa,ra,height,n,200);
    int l=3,r=n;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
        }
        else r=mid-1;
    }
    if(r<4) printf("0\n");
    else
    printf("%d\n",r+1 );
    }
}
