#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

inline long long hashh(int u, int v){
	return 1ll * u*MAXN + v;
}

struct Fenwick{
	unordered_map<int, int> mp;
	void update(int u, int v,int n, int val){
		for(int i= u; i <= n; i += i&(-i))
			for(int j=v; j<= n; j += j&(-j)){
				int h= hashh(i, j);
				mp[h] += val;
			}
	}
	int get(int u, int v){
		int ans = 0;
		for(int i= u; i; i-= i&(-i))
			for(int j = v; j; j-=j&(-j)){
				int h= hashh(i, j);
				if(mp.count(h)) ans += mp[h];
			}
		return ans;
	}
};

int n;
int a[MAXN];
vector<int> posb(MAXN, 0);
vector<int> posc(MAXN, 0);
long long ans = 0;
Fenwick fen;

signed main(){
	cin >> n;
	for(int i=1; i<= n; ++i) cin >> a[i];
	for(int i=1; i<= n; ++i){
		int x; cin >> x; posb[x] = i;
	}
	for(int i=1; i<= n; ++i){
		int x; cin >> x; posc[x] = i;
	}
	for(int i=1; i<= n; ++i){
		ans += fen.get(posb[a[i]], posc[a[i]]);
		fen.update(posb[a[i]], posc[a[i]], n, 1);
	}
	cout << ans;
}