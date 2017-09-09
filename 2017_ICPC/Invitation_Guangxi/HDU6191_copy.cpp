#include<bits/stdc++.h>
using namespace std;
#define N 100005
template <class T> inline void in(T &x)
{
    T f = 1;
    char c;
    while ((c = getchar()) < '0' || c > '9') if (c == '-') f = -1;
    x = c - '0';
    while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}
struct ask
{
    int u, id;
};
struct Trie
{
    Trie *nxt[2];
    Trie()
    {
        nxt[0]=nxt[1]=NULL;
    }
};
int ans[N], val[N], n, q;
vector<int> G[N];
vector<ask> Q[N];
Trie *root[N];
void Insert(Trie *rt, int x)
{
    int id;
    for(int i=30; i>=0; i--)
    {
        id=0;
        if(x&(1<<i)) id=1;
        if(rt->nxt[id]==NULL)
        {
            Trie *temp=new Trie();
            rt->nxt[id]=temp;
        }
        rt=rt->nxt[id];
    }
}
int query(Trie *rt, int x)
{
    int ret=0, id;
    for(int i=30; i>=0; i--)
    {

        id=0;
        if(x&(1<<i)) id=1;
        if(rt->nxt[id^1]!=NULL)
        {
            rt=rt->nxt[id^1];
            ret|=(1<<i);
        }
        else
            rt=rt->nxt[id];
    }
    return ret;
}
Trie* Merge(Trie *p, Trie *q)
{
    if(p==NULL) return q;
    if(q==NULL) return p;
    p->nxt[0]=Merge(p->nxt[0], q->nxt[0]);
    p->nxt[1]=Merge(p->nxt[1], q->nxt[1]);
    free(q);
    return p;
}
void build(int u)
{
    int v;
    root[u]=new Trie();
    Insert(root[u], val[u]);
    for(int i=0; i<G[u].size(); i++)
    {
        v=G[u][i];
        build(v);
        root[u]=Merge(root[u], root[v]);
    }
    for(int i=0; i<Q[u].size(); i++)
        ans[Q[u][i].id]=query(root[u], Q[u][i].u);
}
void Delete(Trie *rt)
{
    if(rt->nxt[0]) Delete(rt->nxt[0]);
    if(rt->nxt[1]) Delete(rt->nxt[1]);
    free(rt);
}
void solve()
{
    int u, x;
    ask temp;
    for(int i=1; i<=n; i++)
    {
        G[i].clear();
        Q[i].clear();
        in(val[i]);
    }
    for(int i=2; i<=n; i++)
    {
        in(x);
        G[x].push_back(i);
    }
    for(int i=1; i<=q; i++)
    {
        in(u);
        in(x);
        temp.u=x;
        temp.id=i;
        Q[u].push_back(temp);
    }
    build(1);
    for(int i=1; i<=q; i++) printf("%d\n", ans[i]);
    Delete(root[1]);
}
int main()
{
    while(scanf("%d%d", &n, &q)!=EOF)
    {
        solve();
    }
    return 0;
}
