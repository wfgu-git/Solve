//Life has never been fucking so easy...
//...Acm without girlfriend
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<functional>
#include<memory>
#include<utility>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<cctype>
#include<cstdlib>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

//map<int, char> f;
//map<char, int> rf;
//struct Trie {
//    Trie *son[40];
//    Trie() {
//        for(int i = 0; i < 40; i++)  son[i] = NULL;
//    }
//};
//
//Trie *NewTrie()
//{
//    Trie *temp = new Trie;
//    return temp;
//}
//
//void getMap()
//{
//    f[39] = '/';
//    f[38] = ' ';
//    int p = 0;
//    for(char a = '0'; a <= '9' ; a++)  f[p++] = a;
//    for(char a = 'A'; a <= 'Z'; a++)  f[p++] = a;
//
//    for(auto kv : f)
//        rf[kv.second] = kv.first;
//}
//
//void Insert(Trie *rt, char *s)
//{
//    Trie *temp = rt;
//    int id;
//    while(*s) {
//        id = rf[*s];
//        if(temp->son[id] == NULL)
//            temp->son[id] = NewTrie();
//        temp = temp->son[id];
//        s++;
//    }
//}
//
//void Remove(Trie *rt)
//{
//    for(int i = 0; i < 40; i++) {
//        if(rt->son[i] != NULL) {
//            Remove(rt->son[i]);
//        }
//    }
//    delete[] rt;
//    rt = NULL;
//}
//
////void naiveRev(char *s)
////{
////    char *p, *q, t;
////    for(q = s; *q != '\0'; q++);
////    q--;
////    for(p = s; p < q; p++, q--) {
////        t = *p;
////        *p = *q;
////        *q = t;
////    }
////}
//
//void printTrie(Trie *rt, int deep)
//{
//    for(int i = 0; i < 40; i++) {
//        if(rt->son[i] != NULL) {
//            if(i != 39) {
//                //for(int k = 0; k < deep * 4; k++)  putchar(' ');
//                printf("%c", f[i]);
//            } else {
//                printf("\n");
//            }
//            printTrie(rt->son[i], deep + 1);
//        }
//    }
//    printf("\n");
//}
//
//int main()
//{
//    getMap();
//    //for(auto kv : f)  cout << kv.first << " " << kv.second << endl;
//
//    char line[105];
//    Trie *root = NewTrie();
//    while(cin.getline(line, 105)) {
//        if(line[0] == '0') {
//            // print the ret of cur case
//            printTrie(root, 0);
//            Remove(root);
//            root = NewTrie();
//        } else {
//            //naiveRev(line);
//            //puts(line);
//            Insert(root, line);
//        }
//    }
//    return 0;
//}

struct name {
    string s;
    int isBook;
    friend bool operator < (name a, name b) {
        if(a.s == b.s)
            return a.isBook < b.isBook;
        return a.s < b.s;
    }
};

struct Trie {
    map<name, Trie *> son;
    string s;
    Trie() {
        s = "";
        son.clear();
    }
} rt;

Trie *NewTrie()
{
    Trie *temp = new Trie;
    return temp;
}

void Insert(vector<string> &s)
{
    int isBook;
    Trie *p = &rt;
    for(int i = 0; i < (int)s.size(); i++) {
        if(i == (int)s.size() - 1)  isBook = 1 ;
        else isBook = 0;
        name  cur = {s[i], isBook};
        if(p->son.find(cur) != p->son.end()) {
            p = p->son[cur];
        } else {
            // new Menu
            p->son[cur] = NewTrie();
            p->son[cur]->s = cur.s;
            p = p->son[cur];
        }
    }
}

void preSolve(string str, vector<string> &s)
{
    string p = "";
    int len = str.size();
    for(int i = 0; i < len; i++) {
        if(str[i] != '/')  {
            p.push_back(str[i]);
        } else {
            s.push_back(p);
            p = "";
        }
    }
    s.push_back(p);
}

void print(Trie *p, int cnt)
{
    for(int i = 0; i < cnt; i++)  cout << "    ";
    cout << p->s << endl;
}

void dfs(Trie *p, int cnt)
{
    if(p == NULL)  return;
    queue<Trie *> ret;
    map<name, Trie *>::iterator it;
    for(it = p->son.begin(); it != p->son.end(); it++) {
        if(it->second->son.size())
            print(it->second, cnt);
        else
            ret.push(it->second);
        dfs(it->second, cnt + 1);
    }
    while(!ret.empty())  print(ret.front(), cnt), ret.pop();
}

int main()
{
    ios::sync_with_stdio(false);
    string str;        // read input
    int kase = 0 ;
    vector<string> s;  // save the list
    while(getline(cin, str)) {
        if(str == "0") {
            // pinrt ret
            cout << "Case " << ++kase << ":" << endl;
            dfs(&rt, 0);
            s.clear();
            rt.son.clear();
        } else {
            preSolve(str, s);
            Insert(s);
            s.clear();
        }
    }
    return 0;
}
