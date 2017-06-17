#include<cstdio>

int fa[50000*3+10];

void init(int n) {
    for(int i=0; i<=3*n; i++)
        fa[i]=i;
}

int find(int x) {
    if(x!=fa[x])    fa[x]=find(fa[x]);
    return fa[x];
}

void Union(int a,int b) {
    a=find(a);
    b=find(b);
    if(a!=b)
        fa[a]=b;
}

bool same(int a,int b) {
    return find(a)==find(b);
}

int N,k;

int main(void) {
    scanf("%d%d",&N,&k);
    init(N);
    int cnt=0,x,y,d;
    for(int i=1; i<=k; i++) {
        scanf("%d%d%d",&d,&x,&y);
        if(x>N||y>N)    {
            cnt++;
            continue;
        }
        if(d==1) {
            if(same(x,y+N)||same(x,y+2*N))
                cnt++;
            else {
                Union(x,y);
                Union(x+N,y+N);
                Union(x+2*N,y+2*N);
            }
        } else {
            if(same(x,y)||same(x,y+2*N))
                cnt++;
            else {
                Union(x,y+N);
                Union(x+N,y+2*N);
                Union(x+2*N,y);
            }
        }
    }
    printf("%d\n",cnt);

    return 0;
}
