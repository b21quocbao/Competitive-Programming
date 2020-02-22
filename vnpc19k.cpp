#include <bits/stdc++.h>
#define ll long long 
#define N 2005
#define fort(i,a,b) for(ll i=(a);i<=(b);++i)
#define oo 2000000000

 
using namespace std;

ll n,m,t,a[N],b[N],c[N],pos[N],f[N][N],inf[N][N];

ll gett(ll i,ll t){
	ll l=i,r=m+1;
	
	while (l<r){

		ll mid=(l+r)/2;
		ll j=pos[mid];

		if (a[j]>=t) r=mid;
		else 
			l=mid+1;		
	}
	return l;
}

ll lui(ll i,ll x){
	
	if (f[i][x]!=-1) return f[i][x];
	if (i>m || i==0) return 0;


	ll xx=x, j=pos[i];
	if (a[j]>=xx) xx=0;
	ll ans=lui(i+1,xx);

	if (xx==0) ans=max(ans,lui(i+1,b[j])+c[j]);
	else{
		ll tmp=inf[i+1][min(b[j],xx)];
		ans=max(ans,lui(tmp,max(b[j],xx))+c[j]);
	}

	return f[i][x]=ans;
}

int main(){
 
	// freopen("test.inp","r",stdin);
	// freopen("test.out","w",stdout);
 	scanf("%lld",&t);
 	while (t--){
 		scanf("%lld %lld",&n,&m);

 		fort(i,1,m){
 			scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
 			pos[i]=i;
 		} 		

 		sort(pos+1,pos+m+1,[](const int& i, const int& j)
            {
                return a[i] < a[j];
            });
        fort (i, 0, m + 1)
        fort (j, 0, n + 1)
        {
            f[i][j] = - 1;
            inf[i][j] = 0;
        }
 		fort(i,1,m) 
        fort (j,0,n) 
        inf[i][j]=gett(i,j);
 		
 		cout<<lui(1,0)<<"\n";
 		// printf("1\n");
 	}
 	
	return 0;

}