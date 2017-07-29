#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<cctype>
#include<climits>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=200010;

int pre[maxn],ch[maxn][2],key[maxn];
int root,tot;
void push_down(int r){
    if(!r)return;

}

void push_up(int x) {


}
int newnode(int x,int fa)
{
    int ret=++tot;
    key[ret]=x;
    pre[ret]=fa;
    ch[ret][0]=ch[ret][1]=0;
    return ret;
}

void rotate(int x,int d)
{
    const int y=pre[x];
    ch[y][!d]=ch[x][d];
    if(ch[x][d]) pre[ch[x][d]]=y;
    pre[x]=pre[y];
    if(ch[pre[y]][0]==y)ch[pre[x]][0]=x;
    else if(ch[pre[y]][1]==y) ch[pre[x]][1]=x;
    ch[x][d]=y;
    pre[y]=x;
    push_up(y);
}

bool _splay_parent(int x, int &y,int goal) {
    return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}

void splay(int x, int goal) {
    push_down(x);
    if(goal==0) root=x;
    for (int y, z; _splay_parent(x, y,goal);) {
        if (_splay_parent(y, z,goal)) {
            push_down(z);
            push_down(y);
            push_down(x);
            int d = y == ch[z][0];
            if (x == ch[y][d])rotate(x, d ^ 1), rotate(x, d);
            else rotate(y, d), rotate(x, d);

        } else {
            push_down(y), push_down(x);
            rotate(x, x == ch[y][0]);
            break;

        }

    }
    push_up(x);

}


int insert(int r,int x)
{
    if(key[r] == x) return 1;
    else{
        int d = x > key[r];
        if(ch[r][d])    return insert(ch[r][d],x);

        int cur = newnode(x,r);
        ch[r][d] = cur;
        splay(cur,0);
        return 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    ll ans=0;
    root=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(i==0){
            ans=num;
            root=newnode(num,0);
        }
        else{
            if(insert(root,num)) continue;
            else{
                int l = ch[root][0];
                ll tmp=LONG_MAX;
                if(l){
                    while(ch[l][1]){
                        l = ch[l][1];
                    }
                    tmp = min(tmp, (ll)num-key[l]);
                }
                int r = ch[root][1];
                if(r){
                    while(ch[r][0]){
                        r = ch[r][0];
                    }
                    tmp = min(tmp, (ll)key[r]-num);
                }
                ans+=tmp;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
