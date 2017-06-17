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
    int cnt;
    bool exist;
    Trie *son[2];
    Trie() {
        cnt = 1;
        exist = false;
        son[0] = son[1] = NULL;
    }
};

Trie *newNode()
{
    Trie *temp = new Trie;
    return temp;
}

void Insert(Trie *rt, string s)
{
    Trie *temp = rt;
    char *p = &s[0];
    while(*p) {
        if(temp->son[*p - '0'] == NULL) {
            temp->son[*p - '0'] = newNode();
        } else {
            temp->son[*p - '0']->cnt++;
        }
        temp = temp->son[*p - '0'];
        p++;
    }
    temp->exist = true;
}

bool Search(Trie *rt, string s)
{
    Trie *temp = rt;
    char *p = &s[0];
    while(*p) {
        if(temp -> son[*p - '0'] == NULL) return false;
        temp = temp->son[*p - '0'];
        p++;
    }
    return temp->cnt > 1 ? true : false;
}

void clear(Trie *rt)
{
    for(int i = 0; i < 2; i++) {
        if(rt->son[i] == NULL) continue;
        clear(rt->son[i]);
        delete[] rt->son[i];
        rt->son[i] = NULL;
    }
}

void Remove(Trie *rt)
{
    clear(rt);
    rt->son[0] = rt->son[1] = NULL;
}

int main()
{
    Trie *root = newNode();
    string line;
    int kase = 0;
    vector<string> save;
    while(cin >> line) {
        bool flag = true;
        if(line == "9") {
            for(const string  & s : save) {
                //cout << s << endl;
                if(Search(root, s) == true) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cout << "Set " << ++kase << " is immediately decodable" << endl;
            else
                cout << "Set " << ++kase << " is not immediately decodable" << endl;
            Remove(root);
            root = newNode();
            save.clear();
        } else {
            save.push_back(line);
            Insert(root, line);
        }
    }
    return 0;
}
