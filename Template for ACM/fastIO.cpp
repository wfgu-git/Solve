// 普通版
template<class T> inline bool read(T &n){
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T> inline void write(T n){
    if(n < 0){putchar('-');n = -n;}
    int len = 0,data[20];
    while(n){data[len++] = n%10;n /= 10;}
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
