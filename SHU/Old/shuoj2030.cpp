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
#include<utility>
#include<functional>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
#define MP(a,b) make_pair(a,b)
#define MEM(x,i) memset(x,i,sizeof(x))
#define fi first
#define se second
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
char fbi(string s)
{
    int len=s.size();
    int cnt0=0,cnt1=0;
    for(int i=0;i<len;i++){
        if(s[i]=='0')    cnt0++;
        else if(s[i]=='1')    cnt1++;
    }

    if(cnt0==len)    return 'B';
    if(cnt1==len)    return 'I';
    return 'F';
}

string cutl(string s)
{
    string res="";
    int len=s.size();
    for(int i=0;i<len/2;i++)
        res+=s[i];
    return res;
}

string cutr(string s)
{
    string res="";
    int len=s.size();
    for(int i=len/2;i<len;i++)
        res+=s[i];
    return res;
}

typedef struct Node {
    Node *left;
    Node *right;
    char v;
}Btreenode,*bitree;

void build(bitree& node, string str)
{ 
    if(str.size()>1){
        node = new Btreenode;
        node->v=fbi(str);
        build(node->left,cutl(str));
        build(node->right,cutr(str));
    } 
    else {
        node = new Btreenode;
        node->v=fbi(str);
        node->left=NULL;
        node->right=NULL;
    }
}

void postorder(Node *u)
{
    if(u!=NULL){
        postorder(u->left);
        postorder(u->right);
        cout<<u->v;
    }
}

void remove(bitree u)
{
    if(u==NULL) return ;
    remove(u->left);
    remove(u->right);
    delete u;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        bitree root;
        string str;
        cin>>str;
     // cout<<cutl(str)<<endl<<cutr(str)<<endl;
        build(root,str);
        postorder(root);
        cout<<endl;
        remove(root);
    }
    return 0;
}
