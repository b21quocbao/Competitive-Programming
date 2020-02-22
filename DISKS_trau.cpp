#include<bits/stdc++.h>

using namespace std;
long long n,m,c[300005],a[300005],b[300005];
map<long long,long long> vt;
bool cmp(long long i,long long j)
{
	return i>j;
}
main()
{
	freopen("test.inp","r",stdin);
	freopen("test.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
		c[i]=b[i];
	}
	sort(c+1,c+m+1,cmp);
	long long i=1,j=1;
	while(1)
	{
		if(a[i]>=c[j])
		{
			i++;
		}
		else
		{
			vt[c[j]]=i-1;
			j++;
		}
		if(j==m+1) break;
	}
	long long res=1e9;
	for(int i=1;i<=m;i++)
	{
		res=max(0ll,min(res-1,vt[b[i]]));
	}
	cout<<res;

}