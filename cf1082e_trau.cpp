#include <bits/stdc++.h>
#define int long long
#define MAXN 500005
#define MOD 1000000007
#define sz(a) static_cast<long long>(a.size())
#define INF 2000000000000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
int n,c,ans=0,a[MAXN],dem[MAXN];
main(){
	ios::sync_with_stdio(false); cin.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
	//freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
	//freopen(".INP","r",stdin); freopen(".OUT","w",stdout);
	cin>>n>>c; int i,j,k,demgoc=0,demc=0;;
	for (i=1;i<MAXN;i++) dem[i]=0;
	for (i=1;i<=n;i++){
		cin>>a[i]; if (a[i]==c) demgoc++;
	}
	ans=max(ans,demgoc); demc=0;
	for (i=1;i<=n;i++){
		j=a[i];
		if (j==c){
			demc++;
		}
		else{
			dem[j]++;
			if (dem[j]-1-demc<0){
				dem[j]=demc+1;
			}
			ans=max(ans,demgoc+dem[j]-demc);
		}
	}
	cout<<ans;
	
}