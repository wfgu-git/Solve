#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    bool flag = false;
    for(auto c : str){
        if(c == 'H' || c == 'Q' || c == '9'){
            flag = true;
            break;
        }
    }
    if(flag) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}

