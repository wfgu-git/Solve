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

const int maxn = 26;
char word[11];
char q[11];
struct Trie {
    Trie *son[maxn];
    int cnt;
    bool exist;
    Trie() {
        cnt = 1;
        exist = false;
        for(int i = 0; i < maxn; i++)  son[i] = NULL;
    }
};

Trie *NewTrie()
{
    Trie *temp = new Trie;
    return temp;
}

void Insert(Trie *root, char *word)
{
    Trie *temp = root;
    while(*word) {
        if(temp->son[*word - 'a'] == NULL) {
            temp->son[*word - 'a'] = NewTrie();
        } else {
            temp->son[*word - 'a']->cnt++;
        }
        temp = temp->son[*word - 'a'];
        word++;
    }
    temp->exist = true;
}

int Search(Trie *root, char *word)
{
    Trie *temp = root;
    while(*word) {
        if(temp->son[*word - 'a'] == NULL)  return 0;
        temp = temp->son[*word - 'a'];
        word++;
    }
    return temp->cnt;
}

int main()
{
    Trie *root = NewTrie();
    root->cnt = 0;
    while(cin.getline(word, maxn) && strcmp(word, "") != 0) {
        Insert(root, word);
    }
    while(cin >> q) {
        cout << Search(root, q) << endl;
    }
    return 0;
}
