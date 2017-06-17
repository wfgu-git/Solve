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

struct Trie {
    bool exist;
    Trie *son[26];
    string trans;
    Trie() {
        exist = false;
        for(int i = 0; i < 26; i++)  son[i] = NULL;
    }
};

Trie *NewNode()
{
    Trie *temp = new Trie;
    return temp;
}

void Insert(Trie *rt, string s, string ss)
{
    Trie *temp = rt;
    char *p = &s[0];
    while(*p) {
        if(temp->son[*p - 'a'] == NULL)
            temp->son[*p - 'a'] = NewNode();
        temp = temp->son[*p - 'a'];
        p++;
    }
    temp->exist = true;
    temp->trans = ss;
}

string Search(Trie *rt, string s)
{
    Trie *temp = rt;
    char *p = &s[0];
    while(*p) {
        if(temp->son[*p - 'a'] == NULL)  return "eh";
        temp = temp->son[*p - 'a'];
        p++;
    }
    return temp->exist ? temp->trans : "eh";
}

void preSolve(string &line, string &fi, string &se)
{
    int p = line.find_first_of(' ');
    fi = line.substr(0, p);
    int q = line.find_first_not_of(' ', p);
    se = line.substr(q, line.size() - q);
}

int main()
{
    Trie *root = NewNode();
    string line, fi, se;
    while(getline(cin, line)) {
        if(line.size() == 0) break;
        preSolve(line, fi, se);
        Insert(root, se, fi);
    }
    while(getline(cin, line)) {
        cout << Search(root, line) << endl;
    }
    return 0;
}
