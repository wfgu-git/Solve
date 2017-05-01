//lIFe has never been fucking so easy...
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
    char mean[12];
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

void Insert(Trie *rt, char *s, char *trans)
{
    Trie *temp = rt;
    while(*s) {
        if(temp->son[*s - 'a'] == NULL) {
            temp->son[*s - 'a'] = NewTrie();
        } else {
            temp->son[*s - 'a']->cnt++;
        }
        temp = temp->son[*s - 'a'];
        s++;
    }
    temp->exist = true;
    strcpy(temp->mean, trans);
}

char *Query(Trie *rt, char *s)
{
    Trie *temp = rt;
    while(*s) {
        if(temp->son[*s - 'a'] == NULL)  return NULL;
        temp = temp->son[*s - 'a'];
        s++;
    }
    return temp->exist ? temp->mean : NULL;
}

const int maxn = 3030;
char str1[maxn], str2[maxn], str[maxn];
int main()
{
    // build root
    Trie *root = NewTrie();

    scanf("%s", str1);
    while(scanf("%s", str1) && strcmp(str1, "END") != 0) {
        scanf("%s", str2);
        Insert(root, str2, str1);
    }

    getchar();
    //cin.getline(str1, maxn);
    scanf("%s", str1);
    getchar();
    int p = 0;
    char *ret;
    while(cin.getline(str1, maxn)) {
        if(strcmp(str1, "END") == 0)
            break;

        for(int i = 0; str1[i] != '\0'; i++) {
            if(str1[i] >= 'a' && str1[i] <= 'z') {
                str[p++] = str1[i];
            } else {
                str[p] = '\0';
                ret = Query(root, str);
                if(ret == NULL)
                    printf("%s", str);
                else
                    printf("%s", ret);
                p = 0;
                printf("%c", str1[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
