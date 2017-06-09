#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld pi = 3.1415926535;
struct Cir{
	int x, y, r;
	int tag;
	ld area;
	Cir(){}
	Cir(int _x, int _y, int _r) : x(_x), y(_y), r(_r) {
		area = Area();	
	}
	bool Cover(const Cir &rhs) const {
		int dx = x - rhs.x;
		int dy = y - rhs.y;
		ld d = hypot(dx, dy);
		return d < r + rhs.r;
	}	
	bool operator < (const Cir &rhs) const {
		return r < rhs.r;
	}
	ld Area() const {
		return pi * r * r;
	}
};

vector<Cir> v;
vector< vector<int> > g;
int fa[1002];
bool vis[1002];
void dfs(int u, int level = 0)
{
	vis[u] = true;
	if(level == 0 || level & 1) v[u].tag = 1;
	else v[u].tag = -1;
	for(auto _v : g[u]){
		dfs(_v, level + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x, y, r;
		cin >> x >> y >> r;	
		v.push_back( Cir(x, y, r) );
	}
	sort(v.begin(), v.end());
	//reverse(v.begin(), v.end());	
	g.resize(n + 2);
	g.clear();
	memset(fa, -1, sizeof(fa));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(fa[j] == -1 && v[i].Cover(v[j]) == true){
				fa[j] = i;
				g[i].push_back(j);
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++){
		if(!vis[i])
			dfs(i);
	}
	ld ret = 0;
	for(const auto cir : v){
		//cout << cir.x << ", " << cir.y << " " << cir.r << "\t";
		//cout << cir.area << endl;
		ret += cir.tag * cir.area;
	}
	cout << fixed << setprecision(9) << ret << endl;	
	return 0;
}
