//sieu nhan
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inp "test.inp"
#define out "test.out"
#define oo 300005
#define inf 1e15
#define mod 1000000007
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define y1 hungdzno1
int n,x,j,res,a[oo],f[oo],t[oo],p[oo];
void nhap(){
  cin>>n>>x;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    f[i]=f[i-1]+a[i];
  }
}
void xuly(){
  for(int i=n;i>0;--i) t[i]=max(t[i+1]+a[i],(int)(0));
  for(int i=1;i<=n;++i) p[i]=max(p[i-1]+a[i],(int)(0));
  for (int i=1;i<=n;++i){
    res=max(res,t[i+1]+f[i]*x-(f[j]*x-p[j]));
    if(f[j]*x-p[j]>f[i]*x-p[i]) j=i;
  }
  res=max(res,f[n]);
  cout<<res;
}
main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
  //freopen(inp,"r",stdin);
  //freopen(out,"w",stdout);
  nhap();
  xuly();
}