#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )

const int MAXN = 50005 ;
const int MAXE = 100005 ;

struct Edge {
	int v , n ;
	Edge () {}
	Edge ( int var , int next ) : v ( var ) , n ( next ) {}
} ;

Edge E[MAXE] ;
int H[MAXN] , cntE ;
int siz[MAXN] ;
int pre[MAXN] ;
LL S[MAXN] , top ;
LL val[MAXN] ;
LL dis[MAXN] ;
LL prime[35] ;
LL pow[35] ;
map < LL , int > mp ;
int Q[MAXN] , head , tail ;
int vis[MAXN] , Time ;
int n , k ;
LL ans ;

void clear () {
	++ Time ;
	ans=0 ;
	cntE = 0 ;
	clr ( H , -1 ) ;
}

void addedge ( int u , int v ) {
	E[cntE] = Edge ( v , H[u] ) ;
	H[u] = cntE ++ ;
}

void init () {
	clr ( vis , 0 ) ;
	Time = 0 ;
	pow[0] = 1 ;
	rep ( i , 1 , 35 ) pow[i] = pow[i - 1] * 3 ;
}

LL match ( LL x , LL res = 0 ) {
	rep ( i , 0 , k ) res += ( 3 - x / pow[i] % 3 ) % 3 * pow[i] ;
	return res ;
}

LL add ( LL x , LL y , LL res = 0 ) {
	rep ( i , 0 , k ) res += ( x / pow[i] % 3 + y / pow[i] % 3 ) % 3 * pow[i] ;
	return res ;
}

int get_root ( int s ) {
	head = tail = 0 ;
	pre[s] = 0 ;
	Q[tail ++] = s ;
	for ( ; head < tail ; ++ head ) {
		int u = Q[head] ;
		for ( int i = H[u] ; ~i ; i = E[i].n ) {
			int v = E[i].v ;
			if ( v == pre[u] || vis[v] == Time ) continue ;
			pre[v] = u ;
			Q[tail ++] = v ;
		}
	}
	int root = s , max_size = tail , tot_size = tail ;
	for ( -- head ; head >= 0 ; -- head ) {
		int u = Q[head] ;
		siz[u] = 1 ;
		int cnt = 0 ;
		for ( int i = H[u] ; ~i ; i = E[i].n ) {
			int v = E[i].v ;
			if ( v == pre[u] || vis[v] == Time ) continue ;
			siz[u] += siz[v] ;
			if ( cnt < siz[v] ) cnt = siz[v] ;
		}
		cnt = max ( cnt , tot_size - siz[u] ) ;
		if ( cnt < max_size ) {
			max_size = cnt ;
			root = u ;
		}
	}
	return root ;
}

void get_dis ( int s , LL value ) {
	head = tail = 0 ;
	pre[s] = 0 ;
	Q[tail ++] = s ;
	dis[s] = value ;
	for ( ; head < tail ; ++ head ) {
		int u = Q[head] ;
		S[top ++] = dis[u] ;
		for ( int i = H[u] ; ~i ; i = E[i].n ) {
			int v = E[i].v ;
			if ( v == pre[u] || vis[v] == Time ) continue ;
			pre[v] = u ;
			dis[v] = add ( dis[u] , val[v] ) ;
			Q[tail ++] = v ;
		}
	}
}

void divide ( int u ) {
	int root = get_root ( u ) ;
	vis[root] = Time ;
	if ( !val[root] ) ++ ans ;
	mp.clear () ;
	for ( int i = H[root] ; ~i ; i = E[i].n ) if ( vis[E[i].v] != Time ) {
		int v = E[i].v ;
		top = 0 ;
		get_dis ( v , val[v] ) ;
		rep ( j , 0 , top ) if ( mp.count ( S[j] ) ) ans += mp[S[j]] ;
		rep ( j , 0 , top ) {
			LL x = add ( S[j] , val[root] ) ;
			LL y = match ( x ) ;
			if ( !x ) ++ ans ;
			if ( mp.count ( y ) ) mp[y] ++ ;
			else mp[y] = 1 ;
		}
	}
	for ( int i = H[root] ; ~i ; i = E[i].n ) if ( vis[E[i].v] != Time ) divide ( E[i].v ) ;
}

void solve () {
	LL x ;
	int u , v ;
	clear () ;
	rep ( i , 0 , k ) scanf ( "%I64d" , &prime[i] ) ;
	For ( i , 1 , n ) {
		scanf ( "%I64d" , &x ) ;
		val[i] = 0 ;
		if ( !x ) continue ;
		rep ( j , 0 , k ) {
			int cnt = 0 ;
			while ( x % prime[j] == 0 ) {
				++ cnt ;
				x /= prime[j] ;
			}
			val[i] += cnt % 3 * pow[j] ;
		}
	}
	rep ( i , 1 , n ) {
		scanf ( "%d%d" , &u , &v ) ;
		addedge ( u , v ) ;
		addedge ( v , u ) ;
	}
	divide ( 1 ) ;
	printf ( "%I64d\n" , ans ) ;
}

int main () {
	init () ;
	while ( ~scanf ( "%d%d" , &n , &k ) ) solve () ;
	return 0 ;
}
