#include <bits/stdc++.h>
#define int long long
#define MAXN 100005
#define MOD 1000000007
#define sz(a) static_cast<long long>(a.size())
#define INF 2000000000000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
int n,m;
struct qua{
	int gia,hot,ind;
};
qua a[MAXN],b[MAXN]; pp d[MAXN];
struct TsegmentTree{
	int l[4*MAXN],h[4*MAXN],mn[4*MAXN],leaf[MAXN];
	void Build(int x,int lo,int hi){
		l[x]=lo; h[x]=hi;
		if( lo==hi){
			leaf[lo]=x; mn[x]=INF;
			return;
		}
		int mid=(lo+hi)/2;
		Build(2*x,lo,mid); Build(2*x+1,mid+1,hi);
		mn[x]=min(mn[2*x],mn[2*x+1]);
	}
	void Add(int x){
		int t=leaf[x]; mn[t]=b[x].gia;
		for (int i=t/2; i>0; i/=2) mn[i]=min(mn[2*i],mn[2*i+1]);
	}
	int qi,qj,qval,don;
	void Strike(int x){
		while (l[x]<h[x]){
			if( mn[x]==mn[2*x]) x=2*x;
			else x=2*x+1;
		}
		mn[x]=INF;
		for (int i=x/2;i>0;i/=2) mn[i]=min(mn[2*i],mn[2*i+1]);
		don=1;
	}
	void Go(int x){
		if (don==1) return;
		if (l[x] > qj || h[x] <qi) return;
		else if (qi<=l[x]&&h[x]<=qj){
			if (mn[x]!=qval) return;
			Strike(x);
		}
		Go(2*x); Go(2*x+1);
	}
	void Update(int i,int j,int val){
		qi=i; qj=j; qval=val; don=0;
		Go(1);
	}
	int Query(int x){
		if (l[x] > qj || h[x] < qi) return INF;
		if (qi <=l[x] && h[x] <= qj){
			return mn[x];
		}
		return min(Query(2*x),Query(2*x+1));
	}
	int Get(int i,int j){
		qi=i; qj=j;
		return Query(1);
	}

};
bool cmp(qua x,qua y){
	return x.gia < y.gia;
}
bool cmp3(qua x,qua y){
	return x.hot >y.hot;
}
bool cmp2(pp x,pp y){
	return x.second > y.second;
}
TsegmentTree tree;
int low_bound(int lo,int hi,int val){
	int cnt=hi-lo;
	while (cnt>0){
		int mid=lo+cnt/2;
		if (b[mid].gia<val){
			lo=++mid;
			cnt-=(cnt/2+1);
		}
		else cnt=cnt/2;
	}
	return lo;
}
int ans=0;
main(){
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
	cin>>m>>n; int i,j,k,pos,val;
	for( i=1;i<=m;i++){
		cin>>d[i].first>>d[i].second;
	}
	sort(d+1,d+m+1,cmp2);
	tree.Build(1,1,n);
	for (i=1;i<=n;i++){
		cin>>a[i].gia>>a[i].hot;
	}
	sort(a+1,a+n+1,cmp); for( i=1;i<=n;i++) a[i].ind=i;
	for (i=1;i<=n;i++) b[i]=a[i];
	sort(a+1,a+n+1,cmp3);
	//for (i=1;i<=n;i++) cout<<a[i].ind<<' '<<a[i].gia<<'\n'; return 0;
	j=1;
	//cout<<b[1].gia; return 0;
	for (i=1;i<=m;i++){
		//cout<<d[i].first<<' '<<d[i].second<<'\n';
		while (j<=n&&a[j].hot>=d[i].second){
			//cout<<i<<' '<<a[j].gia<<'\n';
			tree.Add(a[j].ind); j++;
		}
		pos = low_bound(1,n,d[i].first);
		val=tree.Get(pos,n);
		//cout<<pos<<' '<<val<<'\n';
		if (val==INF){
			cout<<-1; return 0;
		}
		else{
			ans+=val;
			tree.Update(pos,n,val);
		}
	}
	cout<<ans;
}
