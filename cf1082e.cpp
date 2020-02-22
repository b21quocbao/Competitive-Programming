#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 500005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, c, t;
vector <int> Pos[mn];
int mcd[mn];
	
signed main()
{
    freopen("test.inp", "r", stdin);
freopen("test.out", "w", stdout);
#ifdef SMURF
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>c;
	for (int i=1; i<=n; i++) 
	{
		cin>>t;
		Pos[t].push_back(i);
		if (t==c) mcd[i]=1;
	}
	for (int i=1; i<mn; i++) mcd[i]+=mcd[i-1];
	int ans=Pos[c].size(), ad=0;
	for (int i=1; i<mn; i++) if (Pos[i].size()>0 && i!=c)
	{
		vector <int> cng={1}, M={0};
		for (int j=1; j<Pos[i].size(); j++) 
		{
			cng.push_back(mcd[Pos[i][j-1]]-mcd[Pos[i][j]]);
			cng.push_back(1);
		}
		for (int i:cng) M.push_back(M.back()+i);
		int MIN=M[0];
		for (int i=1; i<M.size(); i++)
		{
			ad=max(ad, M[i]-MIN);
			MIN=min(MIN, M[i]);
		}
	}
	cout<<ans+ad;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by Smurf_Wolli
// www.codeforces.com/profiles/Smurf_Wolli