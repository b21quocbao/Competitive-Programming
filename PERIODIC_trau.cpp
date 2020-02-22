#include <bits/stdc++.h>
#define MAXN 100005
#define sz(a) static_cast<long long>(a.size())
#define INF 2000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
int n,t,a[MAXN];
int gcd(int x,int y){
	x=abs(x); y=abs(y);
	while (x!=0&&y!=0){
		if (x>=y) x%=y; else y%=x;
	}
	return x+y;
}
void read(int &x){
	bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}
main(){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
	//freopen("inp.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//freopen(".INP","r",stdin); freopen(".OUT","w",stdout);
	scanf("%ld",&t);
	//t=100;
	int i,j,k,g,ans,mx,st,en,dapso; bool sai;
	while (t--){
		scanf("%ld",&n);
		//n=10000;
		ans=INF; mx=-1;
		for (i=1;i<=n;i++){
			scanf("%ld",&a[i]);
			 //if (i%2==1) a[i]=-1; else a[i]=i;
			mx=max(a[i],mx);
		}
	
		if (mx==-1) printf("inf\n");
		else{
			//vector <int> v;
			 g=0; dapso=-1;
			i=1; sai=false; a[0]=-1;
			
			while (a[i]==-1) i++; 
			while (i<=n){
				if (sai) break;
			while (i<=n&&a[i]!=-1){
				if (sai) break;
				if (a[i]!=a[i-1]+1&&a[i]!=1&&a[i-1]!=-1){
					printf("impossible\n"); sai=true;
				}
				if (sai) break;
				if (a[i]==1&&a[i-1]!=-1){
					if (dapso!=-1){
						printf("impossible\n"); sai=true;
					}
					dapso=a[i-1];
				}
				i++;
			}
			if (sai) break;
			st=i-1;
			while (i<=n&&a[i]==-1){
				i++;
			}
			if (i>n) break;
			en=i;
			en-=(a[en]-1); st-=(a[st]-1);
			g=gcd(g,en-st);
			}
			//cout<<"ez"; return 0;
			if (sai) continue;
			if (g!=0&&dapso!=-1&&g!=dapso) sai=true;
			if (g!=0&&g<mx||dapso!=-1&&dapso<mx) sai=true;
			if (sai) printf("impossible\n");
			else if (dapso==-1&&g==0) printf("inf\n");
			else{
				dapso=max(dapso,g);
				printf("%ld\n",dapso);
			}
		}
	}
}