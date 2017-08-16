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
    Trie *son[26];
    // create the a duixiang
    Trie() {
        cnt = 1;
        exist = false;
        for(int i = 0; i < 26; i++)  son[i] = NULL;
    }
};

Trie *NewTrie()
{
    Trie *temp = new Trie;
    return temp;
}

void Insert(Trie *rt, char *s)
{
    Trie *temp = rt;
    while(*s != '\0') {
        if(temp->son[*s - 'a'] == NULL) {
            temp->son[*s - 'a'] = NewTrie(); // not exist ==> create
        } else {
            temp->son[*s - 'a']->cnt++;      // if exist ==> cnt++
        }
        temp = temp->son[*s - 'a'];
        s++;
    }
    temp->exist = true;
}

int Search(Trie *rt, char *s)
{
    Trie *temp = rt;
    while(*s != '\0') {
        if(temp->son[*s - 'a'] == NULL)  return 0;
        temp = temp->son[*s - 'a'];
        s++;
    }
    return temp->cnt;
}

int main()
{
    int t, m;
    char q[12], word[12];
    while(scanf("%d", &t) == 1) {
        Trie *root = NewTrie();
        for(int i = 0; i < t; i++) {
            scanf("%s", word);
            Insert(root, word);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%s", q);
            printf("%d\n", Search(root, q));
        }
    }
    return 0;
}
