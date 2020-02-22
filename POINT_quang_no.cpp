#include<bits/stdc++.h>

using namespace std;
long long n,e=1,t,f[2005];
#define pll pair<long long,long long>
pll a[2005];
struct bo
{
	long long x,y,dd,kc,dc;
};
struct bo w[4000006],r[4000006];
long long ucln(long long a,long long b)
{
	if(b==0) return a;
	else return ucln(b,a%b);
}
bool operator < (bo a, bo b)
{
    if (a.x != b.x)
    return a.x < b.x;
    if (a.y != b.y)
    return a.y < b.y;
    if(a.dd!=b.dd)
    return a.dd<b.dd;
    return a.kc<b.kc;
}
bool cmp(bo a,bo b)
{
	return a.kc>b.kc;
}

int sqr (int x)
{
	return x * x;
}
long long khc(pll i,pll j)
{
	return sqr(i.first-j.first)+sqr(i.second-j.second);
}

void xepbo()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			w[e].x=a[i].first-a[j].first;
			w[e].y=a[i].second-a[j].second;
			long long d=ucln(abs(w[e].x),abs(w[e].y));
			w[e].x/=d;
			w[e].y/=d;
			if((w[e].x<0&&w[e].y<0)||(w[e].x>0&&w[e].y<0))
			{
				w[e].x=-w[e].x;
				w[e].y=-w[e].y;
			}
			w[e].dd=i;
			w[e].dc=j;
			w[e].kc=khc(a[i],a[j]);
			e++;
		}
	}
	sort(w+1,w+e);
	e--;
	r[1]=w[1];
	t=2;
	for(int q=2;q<=e;q++)
	{
		if(w[q].x==w[q-1].x&&w[q].y==w[q-1].y&&w[q].dd==w[q-1].dd)
		{
			continue;
		}
		else 
		{
			r[t]=w[q];
			t++;
		}
	}
	sort(r+1,r+t,cmp);
}
void qhd()
{
	for(int i=1;i<=n;i++) f[i]=1;
	--t;
	long long kq=0;
	for(int i=2;i<=t + 1;i++)
	{
		vector<pair<int, long long> > v;
		while ((i <= t + 1) && (r[i].kc == r[i-1].kc))
		{
			v.push_back(make_pair(r[i - 1].dd, f[r[i - 1].dc] + 1));
			v.push_back(make_pair(r[i - 1].dc, f[r[i - 1].dd] + 1));
			++ i;
		}
		v.push_back(make_pair(r[i - 1].dd, f[r[i - 1].dc] + 1));
		v.push_back(make_pair(r[i - 1].dc, f[r[i - 1].dd] + 1));
		for (int i = 0; i < v.size(); ++ i)
		{
			f[v[i].first] = max (f[v[i].first], v[i].second);
			kq = max (kq, f[v[i].first]);	
		}
	}
	cout<<kq;
}
int main()
{
	freopen("POINT.inp","r",stdin);
	freopen("POINT.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	sort(a+1,a+n+1);
	xepbo();
	qhd();
}


