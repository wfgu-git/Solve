
//#include<iostream>
//using namespace std;
//
//const int maxn=1010;
//int fa[maxn];
//
//void init(int n)
//{
//    for(int i=0;i<=n;i++)
//        fa[i]=i;
//}
//
//int find(int x)
//{
//    if(fa[x]!=x){
//        fa[x]=find(fa[x]);
//    }
//    return fa[x];
//}
//
//void Union(int a,int b)
//{
//    a=find(a);
//    b=find(b);
//    if(a==b) return ;
//    fa[a]=b;
//}
//
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    int m,n;
//    while(cin>>n&&n){
//        init(n);
//        cin>>m;
//        int a,b;
//        for(int i=1;i<=m;i++){
//            cin>>a>>b;
//            Union(a,b);
//        }
//
//        int sum=0;
//        for(int i=1;i<=n;i++)
//        {
//            if(find(i)==i)
//                sum++;
//        }
//        cout<<sum-1<<endl;
//    }
//    return 0;
//}


//struct

#include<iostream>
using namespace std;

const int maxn=1010;
struct Node{
    int parent,rank,data;
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
    if(node[x].parent!=x)    node[x].parent=find(node[x].parent);
    return node[x].parent;
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);

    if(node[a].rank<node[b].rank){
        node[a].parent=b;
    }
    else{
        node[b].parent=a;
        if(node[a].rank==node[b].rank)
            node[b].rank++;
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    int m,n;
    while(cin>>n&&n){
        init(n);
        cin>>m;
        int a,b;
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            Union(a,b);
        }

        int sum=0;
        for(int i=1;i<=n;i++){
            if(find(i)==i)
                sum++;
        }

        cout<<sum-1<<endl;
    }
    return 0;
}
