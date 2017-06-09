#include <bits/stdc++.h>
using namespace std;

string chn[] = {"ong", "ang", "uang", "an", "ing", "ie", "uo", "ou", "ian", "en", "ai", "ao", "eng"};
string jpn[] = {"shi", "chi", "ni", "ta", "ga"};
string eng[] = {"and", "of", "the", "an", "ing", "ed"};
int cnt_chn, cnt_jpn, cnt_eng;
void check(const string &word)
{
    int n = word.size();
    for (auto pat : chn) if (word.find(pat) < n) cnt_chn++;
    for (auto pat : jpn) if (word.find(pat) < n) cnt_jpn++;
    for (auto pat : eng) if (word.find(pat) < n) cnt_eng++;
}
int main()
{
    string w;
    while (cin >> w) {
        check(w);
    }
    int Max = max(cnt_chn, max(cnt_jpn, cnt_eng));
    if (Max == cnt_chn) cout << "Chinese" << endl;
    else if (Max == cnt_jpn) cout << "Japanese" << endl;
    else cout << "English" << endl;
    return 0;
}

