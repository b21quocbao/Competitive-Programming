#include<bits/stdc++.h>
using namespace std;
char a[1000],b[1000];
int dem[1000];
int main()
{
    freopen ("test.inp", "r", stdin);
    freopen ("test.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	dem[a[i]-'a']++;
	}
	queue<int> q;
	for(int i=0;i<n;i++)
	{
	cin>>b[i];
	dem[b[i]-'a']--;
	if(dem[b[i]-'a']<0) {cout<<-1;exit(0);}
	}	
	for(int i=0;i<n;i++)
			{
				int j=i;
				while(a[j]!=b[i])
					{
					j++;
					
					
					}
				char tmp=a[j];
				for(int k=j;k>i;k--)
					{
					q.push(k);
					a[k]=a[k-1];
					}
				a[i]=tmp;
			}
	cout<<q.size()<<endl;
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	
}