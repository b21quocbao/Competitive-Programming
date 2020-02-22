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
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int Q, K;

//sub1:
deque <pii> dish={};
int quer3(int u)
{
	int ret=0;
	vector <int> mcd={0};
	int mi=0;
	for (pii i: dish) if (u-K<=i.XX && i.XX<=u+K) 
	{
	//	cerr<<"__"<<u<<' '<<K<<' '<<i.XX<<"\n";
		mcd.push_back(mcd.back()+i.YY);
		mi=min(mi, mcd.back());
		ret=max(mcd.back()-mi, ret);
	}
	return ret;
}
//end sub1

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
	int qq, c, d, ans=0;
	cin>>Q>>K;
	while (Q--)
	{
		cin>>qq;
		if (qq==3)
		{
			cin>>c;
			c=(c^ans);
		//	cerr<<qq<<" "<<c<<"\n";
			ans=quer3(c);
			
			cout<<ans<<"\n";
		}
		else
		{
			cin>>c>>d;
			c=(c^ans);
			if (qq==1) dish.push_back({c, d});
			else dish.push_front({c, d});
		}
	}
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/

