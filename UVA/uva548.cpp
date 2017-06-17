#include<bits/stdc++.h>
using namespace std;

const int maxv=10000+10;
int pre_order[maxv],in_order[maxv],post_order[maxv],lch[maxv],rch[maxv];
int n;

bool read_list(int *a)
{
    string line;
    if(!getline(cin,line))  return false;
    stringstream ss(line);
    n=0;
    int x;
    while(ss>>x)    a[n++]=x;
    return n>0;
}

//*************//
//根据 中序+后序还原一颗树
int build1(int L1,int R1,int L2,int R2)
{
    if(L1>R1)   return 0;
    int root=post_order[R2];           //后序遍历最后一个字符是根
    int p=L1;
    while(in_order[p]!=root) p++;      //在中序找到根的位置
    int cnt=p-L1;                      //左子树的结点个数
    lch[root]=build1(L1,p-1,L2,L2+cnt-1);
    rch[root]=build1(p+1,R1,L2+cnt,R2-1);
    return root;
}

//根据 先序+中序还原一颗树
int build(int L1,int R1,int L2,int R2)
{
    if(L2>R2) return 0;
    int root=pre_order[L1];
    int p=L2;
    while(in_order[p]!=root)    p++;
    int cnt=p-L2;
    lch[root]=build(L1+1,L1+cnt-1,L2,p-1);
    rch[root]=build(L1+cnt,R1,p+1,R2);
    return root;
}

int best,best_sum;

void dfs(int u,int sum)
{
    sum+=u;
    if(!lch[u]&&!rch[u])
    {
        if(sum<best_sum||(sum==best_sum&&u<best)) {best=u;best_sum=sum;}
    }
    if(lch[u])  dfs(lch[u],sum);
    if(rch[u])  dfs(rch[u],sum);
}


int main(void)
{
    while(read_list(in_order))
    {
        read_list(post_order);
        build(0,n-1,0,n-1);
        best_sum=100000000;
        dfs(post_order[n-1],0);
        cout<<best<<endl;
    }
    return 0;
}
