#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("test.inp", "r", stdin);
freopen("test.out", "w", stdout);
    int n,a;
    cin>>n;
    if(n%2==1) cout<<n/2<<" "<<(n/2+1);
    else
    {
        for(int k=2;k<=n;k++)
        if((n-k *(k + 1) / 2)%k==0)
        {
            a=(n-k*(k+1)/2)/k;
            for(int i=1;i<=k;i++)
            {
                cout<<a+i<<" ";
            }
            return 0;
        }
    }
}