#include <bits/stdc++.h>
#define ll long long
#define fort(i,a,b) for(ll i=(a);i<=(b);++i)
#define ford(i,a,b) for(ll i=(a);i>=(b);--i)
#define N 1000005
 
using namespace std;
 
string s;
ll t;
 
int main()
{
   // freopen("t.inp","r",stdin);
   // freopen("t.out","w",stdout);
 
    cin>>t;
    while (t--){
        cin>>s;
        ll n=s.length();
        ll ans=0,d=0;
        fort(i,1,n){
            if (s[i-1]=='R') d=0;else d++;
            ans=max(ans,d);
        }
        cout<<ans+1<<"\n";
    }
 
    return 0;
}