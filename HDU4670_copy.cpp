#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
#define NN 51000

int te;
int fi[NN];
struct edge{int v,ne;}ed[NN*2];

map<long long,int> mp[NN];
int tr;
int root[NN];
int cnt[NN];
int son[NN];
long long sum[NN];

long long pp[50];
long long state[NN];
long long ans;
int n,k;

void addedge(int fr,int to){
    ++te;ed[te].ne=fi[fr];fi[fr]=te;ed[te].v=to;
}

void getpr(int now,long long v){
    int i,tmp;
    long long sta=0;
    for(i=1;i<=k;++i){
        tmp=0;
        while(1){
            if (v%pp[i]) break;
            v=v/pp[i];
            tmp++;
        }
        tmp=tmp%3;
        sta=sta*3+tmp;
    }
    state[now]=sta;
}

int tsv[50];
long long mergeval(long long v1,long long v2){
    long long ret=0;
    int i;
    for(i=k;i>=1;--i){
        tsv[i]=(v1+v2)%3;
        v1/=3;v2/=3;
    }
    for(i=1;i<=k;++i){
        ret=ret*3+tsv[i];
    }
    return ret;
}

long long rev(long long v1,long long v2){
    long long ret=0;
    int i;
    for(i=k;i>=1;--i){
        tsv[i]=((v1-v2)%3+3)%3;
        v1/=3;v2/=3;
    }
    for(i=1;i<=k;++i){
        ret=ret*3+tsv[i];
    }
    return ret;
}


void dfs(int u,int fa){
    int ts=1;
    int e,v;
    long long tmp;
    int mas=-1;son[u]=u;
    int nr,vr;
    map<long long,int>::iterator it;
    for(e=fi[u];e!=-1;e=ed[e].ne){
        v=ed[e].v;
        if (v==fa) continue;

        dfs(v,u);
        ts+=cnt[v];
        if (cnt[v]>mas) {mas=cnt[v];son[u]=v;}
    }
    cnt[u]=ts;

    if (ts==1){
        if (state[u]==0) ans++;
        root[u]=++tr;
        mp[root[u]][0]=1;
        sum[u]=state[u];
    }
    else{
        tmp=state[u];
        if (state[u]==0) ans++;
        sum[u]=mergeval(tmp,sum[son[u]]);
        nr=root[u]=root[son[u]];
        ans+=mp[nr][rev(0,sum[u])];
        mp[nr][rev(0,sum[son[u]])]++;
        for(e=fi[u];e!=-1;e=ed[e].ne){
            v=ed[e].v;
            if (v==fa||v==son[u]) continue;
            vr=root[v];
            for(it=mp[vr].begin();it!=mp[vr].end();++it){
                tmp=mergeval(sum[u],sum[v]);
                tmp=mergeval(tmp,it->first);
                tmp=rev(0,tmp);
                ans+=(long long)it->second*mp[nr][tmp];
            }
            for(it=mp[vr].begin();it!=mp[vr].end();++it){
                tmp=mergeval(sum[v],it->first);
                tmp=rev(tmp,sum[son[u]]);
                mp[nr][tmp]+=it->second;
            }
        }
    }
}

int main(){
    //freopen("4670in.txt","r",stdin);
    int i;
    int a,b;
    long long la;
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&k);
        for(i=1;i<=k;++i){
            scanf("%I64d",&pp[i]);
        }
        for(i=1;i<=n;++i){
            scanf("%I64d",&la);
            getpr(i,la);
            mp[i].clear();
        }
        memset(fi,-1,sizeof(fi));
        te=-1;
        for(i=1;i<n;++i){
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        }
        ans=0;
        tr=0;
        dfs(1,-1);
        printf("%I64d\n",ans);
    }
    return 0;
}
