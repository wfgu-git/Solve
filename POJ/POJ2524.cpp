#include<iostream>
using namespace std;

const int maxn=50010;
struct Node{
    int parent,rank,relation;
}node[maxn];

void init(int n)
{
    for(int i=0;i<=n;i++){
        node[i].parent=i;
        node[i].rank=0;
    }
}

int find(int x)
{
    if(x!=node[x].parent)   node[x].parent=find(node[x].parent);
    return node[x].parent;
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(node[a].rank<node[b].rank)
        node[a].parent=b;
    else{
        node[b].parent=a;
        if(node[a].rank==node[b].rank)
            node[b].rank++;
    }
}

int m,n;
int main(void)
{
    ios::sync_with_stdio(false);
    int kase=0;
    while(cin>>n>>m&&(n+m)){
        init(n);
        int a,b;
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            Union(a,b);
        }

        int sum=0;
        for(int i=1;i<=n;i++){
            if(i==find(i)) sum++;
        }
        cout<<"Case "<<++kase<<": "<<sum<<endl;
    }
    return 0;
}

