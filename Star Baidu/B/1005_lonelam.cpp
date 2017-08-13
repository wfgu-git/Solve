#include <bits/stdc++.h>
using namespace std;
bool flg;
const int maxm=10000+100;    //最大点数
const int INF=0x3f3f3f3f;

const int MAXBUF = 100000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext() {
  if (++ps == pe)
    pe = (ps = buf) +
         fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}
template <class T>
inline bool in(T &ans) {
  ans = 0;
  T f = 1;
  if (ps == pe) return false;  // EOF
  do {
    rnext();
    if ('-' == *ps) f = -1;
  } while (!isdigit(*ps) && ps != pe);
  if (ps == pe) return false;  // EOF
  do {
    ans = (ans << 1) + (ans << 3) + *ps - 48;
    rnext();
  } while (isdigit(*ps) && ps != pe);
  ans *= f;
  return true;
}
const int MAXOUT = 100000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write() {
  fwrite(bufout, sizeof(char), pout - bufout, stdout);
  pout = bufout;
}
inline void out_char(char c) {
  *(pout++) = c;
  if (pout == pend) write();
}
inline void out_str(char *s) {
  while (*s) {
    *(pout++) = *(s++);
    if (pout == pend) write();
  }
}
template <class T>
inline void out_int(T x) {
  if (!x) {
    out_char('0');
    return;
  }
  if (x < 0) x = -x, out_char('-');
  int len = 0;
  while (x) {
    outtmp[len++] = x % 10 + 48;
    x /= 10;
  }
  outtmp[len] = 0;
  for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
  out_str(outtmp);
}

struct edge{        //边：起点、终点、容量、流量、单位费用
    int from,to,c,f,cost;
    edge(int a,int b,int m,int n,int p):from(a),to(b),c(m),f(n),cost(p){}
};

int aabs(int a){
    return a>=0?a:-a;
}

struct MCMF{
    int m,s,t;
    vector<edge>e;
    vector<int>g[maxm];
    int dis[maxm],a[maxm],p[maxm];
    bool vis[maxm];

    void init(int n){        //初始化函数
        for(int i=0;i<=n;i++)g[i].clear();
        e.clear();
    }

    void add(int a,int b,int c,int v){    //加边函数
        e.push_back(edge(a,b,c,0,v));
        e.push_back(edge(b,a,0,0,-v));
        m=e.size();
        g[a].push_back(m-2);
        g[b].push_back(m-1);
    }

    bool spfa(int& flow,int& cost){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(s);
        vis[s]=1;
        dis[s]=0;
        p[s]=0;
        a[s]=INF;
        while(!q.empty()){
            int u=q.front();q.pop();
            vis[u]=0;
            for(int i=0;i<g[u].size();i++){
                edge tmp=e[g[u][i]];
                if(dis[tmp.to]>dis[u]+tmp.cost&&tmp.c>tmp.f){
                    dis[tmp.to]=dis[u]+tmp.cost;
                    p[tmp.to]=g[u][i];
                    a[tmp.to]=min(a[u],tmp.c-tmp.f);
                    if(!vis[tmp.to]){
                        q.push(tmp.to);
                        vis[tmp.to]=1;
                    }
                }
            }
        }
        //求最大费用最大流的情况下可能要修改！
        if(dis[t]==INF || dis[t] > 0) return 0;
        flow+=a[t];
        cost+=dis[t]*a[t];
        int u=t;
        while(u!=s){
            e[p[u]].f+=a[t];
            e[p[u]^1].f-=a[t];
            u=e[p[u]].from;
        }
        return 1;
    }

    int MF(int s,int t, int& flow){
        flow = 0;
        this->s=s;this->t=t;
        int cost=0;
        while(spfa(flow,cost));
        return cost;
    }

} G;
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    int S = n + 1;
    int T = n + 2;
    int SS = n + 3;
    G.init(n + 3);
    int ans = 0;
    G.add(SS, S, 0, 0);
    for (int i = 1; i <= n; ++i) {
      int a, b, c, d;
      in(a); in(b); in(c); in(d);
      // scanf("%d%d%d%d", &a, &b, &c, &d);
      G.add(S, i, b, a);
      G.add(i, T, d, -c);
    }
    for (int i = 0; i < m; ++i) {
      int u, v, k;
      in(u); in(v); in(k);
      // scanf("%d%d%d", &u, &v, &k);
      G.add(u, v, INF, k);
      G.add(v, u, INF, k);
    }
    G.e[0].c = INF;
    flg = true;
    int flow;
    int tmp = G.MF(SS, T, flow);
    tmp = -tmp;
    ans = max(ans, tmp);
    out_int(ans); out_char('\n');
    // printf("%d\n", ans);
  }
  write();
  return 0;
}
