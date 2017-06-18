#include <bits/stdc++.h>
using namespace std;

bool isDigital(char ch) {return (ch >= '0' && ch <= '9');}
map<char, string> ma[5];
map<char, bool> vow;
string s;
void init() {
    vow['a'] = true, vow['e'] = true, vow['i'] = true, vow['o'] = true, vow['u'] = true, vow['v'] = true;
    ma[1]['a'] = "ā", ma[1]['e'] = "ē", ma[1]['i'] = "ī", ma[1]['o'] = "ō", ma[1]['u'] = "ū", ma[1]['v'] = "ǖ";
    ma[2]['a'] = "á", ma[2]['e'] = "é", ma[2]['i'] = "í", ma[2]['o'] = "ó", ma[2]['u'] = "ú", ma[2]['v'] = "ǘ";
    ma[3]['a'] = "ǎ", ma[3]['e'] = "ě", ma[3]['i'] = "ǐ", ma[3]['o'] = "ǒ", ma[3]['u'] = "ǔ", ma[3]['v'] = "ǚ";
    ma[4]['a'] = "à", ma[4]['e'] = "è", ma[4]['i'] = "ì", ma[4]['o'] = "ò", ma[4]['u'] = "ù", ma[4]['v'] = "ǜ";
}

bool find(char c) {
    bool flag = false;
    for(auto ch : s) {
        if(ch == c) {
            flag = true;
            break;
        }
    }
    return flag;
}

int main(int argc, char const *argv[]) {
    init();
    int kase;
    cin >> kase;
    for(int i = 1; i <= kase; i++) {
        cin >> s;
        int n = s.size();
        char diao =  s[n - 1];
        // pre do sth

        if(!isDigital(diao)) {
            cout << "Case " << i << ": ";
            for(int i = 0; i < n; i++) {
                if(s[i] == 'v') {
                    if(i + 1 < n && s[i + 1] == 'e') cout << 'u';
                    else cout << "ü";
                } else {
                    cout << s[i];
                }
            }
            cout << endl;
        } else {
            s = s.substr(0, s.size() - 1);
            cout << "Case " << i << ": ";
            int t = diao - '0';
            if(find('a')) {
                for(auto c : s) {
                    if(c != 'a') cout << c;
                    else cout << ma[t][c];
                }
                cout << endl;
            } else if(find('o')) {
                for(auto c : s) {
                    if(c != 'o') cout << c;
                    else cout << ma[t][c];
                }
                cout << endl;
            } else if(find('e')) {
                for(auto c : s) {
                    if(c != 'e') {
                        if(c == 'v') cout << "u";
                        else cout << c;
                    } else cout << ma[t][c];
                }
                cout << endl;
            } else {
                // bool flag = false;
                for(int i = 0; i < (int)s.size(); i++) {
                    if(!vow[s[i]]) cout << s[i];
                    else if(s[i] == 'i') {
                        if(i + 1 < n && s[i + 1] == 'u') cout << 'i' << ma[t][s[++i]];
                        else cout << ma[t][s[i]];
                    } else if(s[i] == 'u') {
                        if(i + 1 < n && s[i + 1] == 'i') cout << 'u' << ma[t][s[++i]];
                        else cout << ma[t][s[i]];
                    } else {
                        cout << ma[t][s[i]];
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
