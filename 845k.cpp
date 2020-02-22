#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXINGRES = 1005;
const int MAXDISHES = 80;
const int INF = 1e18;

int r, s, m, d, n;
vector<int> b(MAXINGRES, 0);
vector<bitset<MAXINGRES> > dishes(MAXDISHES);
set<pair<int, int> > notgood;

bitset<MAXINGRES> tmp;
int ans = 0LL;

signed main(){
	cin >> r >> s >> m >> d >> n;
	for(int i=0; i< r; ++i) cin >> b[i];
	for(int i=1; i <= s+m+d; ++i){
		int k; cin >> k;
		while(k--){
			int u; cin >> u; --u;
			dishes[i].set(u);
		}
	}
	while(n--){
		int x, y; cin >> x >> y;
		notgood.insert({min(x,y), max(x, y)});
	}
	for(int i=1; i<= s; ++i)
		for(int j=s+1; j<= s+m; ++j)
			for(int k = s+m+1; k<= s+m+d; ++k){
				if(notgood.count({i, j}) || notgood.count({j, k}) || notgood.count({i, k})) continue;
				tmp = (dishes[i]|dishes[j])|dishes[k];
				if(!tmp.any()) continue;
				int cnt = 1;
				for(int i=0; i< r; ++i) if(tmp.test(i)){
                    if (INF / b[i] < cnt)
                    {
                        cout << "too many";
                        return 0;
                    }
					cnt *= b[i];
					if(cnt > INF){
						cout << "too manyc";
						return 0;
					}
				}
				ans += cnt;
				if(ans > INF){
					cout << "too many";
					return 0;
				}
			}
	cout << ans;
}