#include<bits/stdc++.h>
using namespace std;
long long n,dem=0,m,luu=1;
string s,t,a,b;
void nhap()
{
 cin>>n;
	cin>>s;
	cin>>t;
	a=s;
	b=t;

}
bool check()
{
    for(int i=0;i<n;i++)
		{
			if(a[i]!=b[i])
			{
				m=-1;
				for(int j=i+1;j<n;j++)
				{
					if(a[j]==b[i])
					{
						m=j;
						break;
					}
				}
				if(m==-1)
				{
					luu=0;
					break;
				}
				else
				{
					for(int j=m;j>i;j--)
					{
						dem++;
						swap(a[j],a[j-1]);
					}
				}
			}
		}
    if(luu==0)return 0;
    return 1;
}
void xuly()
{
    if(!check())
    {
        cout<<-1;return ;
    }
    cout<<dem<<endl;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				m=-1;
				for(int j=i+1;j<n;j++)
				{
					if(s[j]==t[i])
					{
						m=j;
						break;
					}
				}
				if(m==-1) break;
				else
				{
					for(int j=m;j>i;j--)
					{
						dem++;
						swap(s[j],s[j-1]);
						cout<<j<<" ";
					}
				}
			}
		}
}
int main()
{
    freopen ("test.inp", "r", stdin);
    freopen ("test.out", "w", stdout);
	nhap();
	xuly();
}