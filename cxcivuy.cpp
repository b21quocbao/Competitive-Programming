#include<bits/stdc++.h>
using namespace std;
int a[10010];
int tcs(int n)
{
    int tong=0,m;
    while(n>0)
    {
        m=n%10;
        tong=tong+m;
        n=n/10;
    }
    return tong;
}
int main()
{
    int n,dem=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (!a[i]) return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]%tcs(a[i])==0) dem++;
    }
    cout<<dem;
}