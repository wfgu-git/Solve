#include <bits/stdc++.h>
using namespace std;
const int charsize = 26;
const int maxn = 500000;
struct Node { // you need to modify a lot ... before using it
  int tot;
  int root;
  int next[maxn][charsize];
  int fail[maxn];
  int end[maxn]; // the cont of the word

  inline int getid(const char& c) {}
  inline int newnode() {
    for (int i = 0; i < charsize; ++i) {
      next[tot][i] = -1;
    }
    end[tot++] = 0;
    return tot - 1;
  }

  inline void init() {
    tot = 0;
    root = newnode();
  }

  inline void insert(const char* str) {
    int now = root;
    while(*str) {
      int charid = getid(*str);
      if (next[now][charid] == -1) next[now][charid] = newnode();
      now = next[now][charid];
      ++str;
    }
    ++end[now];
  }

  inline void build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < charsize; ++i) {
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      }
    }

    while (!q.empty()) {
      int now = q.front(); q.pop();
      for (int i = 0; i < charsize; ++i) {
        if (next[now][i] == -1) {
          next[now][i] = next[fail[now]][i];
        } else {
          fail[next[now][i]] = next[fail[now]][i];
          q.push(next[now][i]);
        }
      }
    }
  }

  int solve(const char* str) {
    int ret = 0, k = 0;
    while (*str) {
      int charid = getid(*str);
      k = next[k][charid];
      int j = k;
      while (j) {
        ret += end[j];
        end[j] = 0;
        j = fail[j];
      }
      ++str;
    }
    return ret;
  }

} AC;
