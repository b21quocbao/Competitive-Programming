//sieu nhan
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inp "test.inp"
#define out "test.out"
#define oo 1005
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define y1 hungdzno1
#define inf 1e15
int n,m,bac[oo],res,dem,lt[oo],ans,ok1[oo][oo];
bool ok[oo],ve[oo][oo];
vector<int> kq[oo],ke[oo],le,day1,day2;
void nhap(){
  cin>>n>>m;
  for(int i=1;i<=m;++i){
    int x,y;
    cin>>x>>y;
    ke[x].pb(y);
    ke[y].pb(x);
    ++bac[x];
    ++bac[y];
  }
}
void dfs(int u){
  ok[u]=1;
  if(bac[u]%2) le.pb(u);
  for(int i=0;i<ke[u].size();++i){
    int z=ke[u][i];
    if(!ok[z]) dfs(z);
  }
}
void dfs1(int u){
  // cerr<<u<<" ";
  --bac[u];
  day1.pb(u);
  for(int i=0;i<ke[u].size();++i){
    // cerr<<u<<" ";
    int z=ke[u][i];
    if(bac[z]>0 && ok1[u][z]>0){
      --ok1[u][z];
      --ok1[z][u];
      --bac[z];
      dfs1(z);
      break;
    }
  }
}
void xuly(){
  for(int i=1;i<=n;++i){
    if(!ok[i]){
      le.clear();
      dfs(i);
      if(le.size()>2){
        for(int j=0;j<le.size()-2;j+=2){
          ve[le[j]][le[j+1]]=1;
          ve[le[j+1]][le[j]]=1;
          ke[le[j]].pb(le[j+1]);
          ke[le[j+1]].pb(le[j]);
          ++bac[le[j]];
          ++bac[le[j+1]];
        }
        lt[++ans]=le[le.size()-1];
      }
      else{
        if(le.size()<2) lt[++ans]=i;
        else lt[++ans]=le[0];
      }
    }
  }
  for(int i=1;i<=n;++i){
    for(int j=0;j<ke[i].size();++j){
      ++ok1[i][ke[i][j]];
      // cout<<i<<" "<<ke[i][j]<<'\n';
    }
  }
  dem=0;
  for(int i=1;i<=ans;++i){
    day1.clear();
    day2.clear();
    dfs1(lt[i]);
    cerr<<"ok";
    // cout<<'\n';
    // for(int j=0;j<day1.size();j++) cout<<day1[j]<<" ";
    while(!day1.empty()){
      int j=day1.size()-1;
      int z=day1[j];
      day1.pop_back();
      if(bac[z]>0){
        day1.pb(z);
        dfs1(z);
        // cerr<<z;
      }
      else day2.pb(z);
    }
    // cout<<'\n';
    // for(int j=0;j<day2.size();j++) cout<<day2[j]<<" ";
    if(day2.size()<2) continue;
    kq[++dem].pb(day2[0]);
    for(int j=1;j<day2.size();++j){
      if(ve[day2[j]][day2[j-1]]){
        ++dem;
        ve[day2[j]][day2[j-1]]=0;
        ve[day2[j-1]][day2[j]]=0;
      }
      kq[dem].pb(day2[j]);
    }
  }
  cout<<max(dem-1,0ll)<<'\n';
  for(int i=1;i<=dem;++i){
    if(kq[i].size()>1){
      for(int j=0;j<kq[i].size();++j) cout<<kq[i][j]<<" ";
      cout<<'\n';
    }
  }
}
main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen(inp,"r",stdin);
  freopen(out,"w",stdout);
  nhap();
  xuly();
}
