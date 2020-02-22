#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cstring>
#include <iomanip>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
#define inf 280201280201280201
#define mn 200005
#define FLN "test"
typedef pair<int, int> ii;
//constance

//common data structures and templates
template<typename T>
struct SegmentTree{
};
//gb
int n;
int a[mn];
vector<vector<int> > g;
vector<int> divv[mn];
int f[mn][165];
int ans;
//functions here
void input(){
  cin >> n;
  g.assign(n, vector<int>());
  for(int i=0; i< n; ++i) cin >> a[i];
  for(int i=1; i< n; ++i){
    int x, y; cin >> x>> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
}
void dfs(int v,int p){
  for(int i=0; i< divv[a[v]].size(); ++i) f[v][i] = 1;
  for(int u: g[v]){
    if(u== p) continue;
    dfs(u, v);
    for(int i=0; i< divv[a[v]].size(); ++i){
      if(a[u]%divv[a[v]][i] == 0){
        int x=  lower_bound(divv[a[u]].begin(), divv[a[u]].end(), divv[a[v]][i])- divv[a[u]].begin();
        f[v][i] = max(f[v][i], f[u][x]+1);
      }
    }
  }
  
}
void calc(int v, int p){
  for(int u: g[v]){
    if(u==p) continue;
    calc(u, v);
  }
  for(int i=0; i< divv[a[v]].size(); ++i){
    int mx1=  -n, mx2 = -n;
    ans = max(ans, f[v][i]);
    for(int u : g[v]){
      if(u!= p){
        if(a[u]%divv[a[v]][i] == 0){
          int x= lower_bound(divv[a[u]].begin(), divv[a[u]].end(), divv[a[v]][i])- divv[a[u]].begin();
          if(mx1 <= f[u][x]) mx2 = mx1, mx1 = f[u][x];
          else mx2 = max(mx2, f[u][x]);
        }
      }
    }
    ans = max(ans, mx2+mx1+1);
  }
}
void solve(){
  for(int i=2; i< mn; ++i){
    for(int j= i; j< mn; j+=i) divv[j].push_back(i);
  }
  
  //for(int i=0; i< n; ++i) cerr << f[i][1] << " ";
  ans = 0;
  dfs(0, -1);
  for(int i=0; i < divv[a[0]].size(); ++i) ans = max(ans, f[0][i]);
  
  calc(0, -1);
  cout << ans;
}

//#define LOCAL 1

signed main(signed argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	   freopen(FLN".inp", "r", stdin);
	   freopen(FLN".out", "w", stdout);
#endif
  freopen("test.inp", "r", stdin);
  freopen("test.ans", "w", stdout);
	  input();
	  solve();
	return 0;
}