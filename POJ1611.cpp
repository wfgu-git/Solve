#include<iostream>
using namespace std;

const int maxn=30000;
struct Node{
    int data,rank,parent;
}node[maxn];

void init(int n){
    for(int i=0;i<=n;i++){
        node[i].parent=i;
        node[i].rank=0;
    }
}

int get_parent(int i){
    if(node[i].parent==i)
        return i;
    return get_parent(node[i].parent);
}

void Union(int a,int b){
    a=get_parent(a);
    b=get_parent(b);
    if(node[a].rank>node[b].rank)
        node[b].parent=a;
    else{
        node[a].parent=b;
        if(node[a].rank==node[b].rank)
            node[b].rank++;
    }
}

int main(void) {
    int n,m;
    while(cin>>n>>m&&(n+m)){
        init(n);

        for(int i=1;i<=m;i++){
            int k,a,b;
            cin>>k;
            cin>>a;
            while(--k){
                cin>>b;
                Union(a,b);
            }
        }
        int sum=1;
        for(int i=1;i<n;i++){
            if(get_parent(i)==get_parent(0))    sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
