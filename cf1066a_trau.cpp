#include<bits/stdc++.h>

using namespace std;

long long n,dd=600000,dc=600000,ok[2000006];

int main()
{
    freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
	cin>>n;
	long long p;
	char q;
	cin>>q;
	cin>>p;
	ok[p]=dd;
	n--;
	while(n--)
	{
		long long p;
		char q;
		cin>>q;
		cin>>p;
		if(q=='L')
		{
			dd--;
			ok[p]=dd;
		}
		else if(q=='R')
		{
			dc++;
			ok[p]=dc;
		}
		else cout<<min(ok[p]-dd,dc-ok[p])<<'\n';
	}
	
}