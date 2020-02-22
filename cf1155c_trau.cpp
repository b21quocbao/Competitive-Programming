/*
    Code by CNH_Tourist
*/
#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unrolled-loops")

using namespace std;

#define inp "TestCode.inp"
#define out "TestCode.out"
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FileInOut freopen(inp,"r",stdin);freopen(out,"w",stdout);
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define pi acos(-1)
#define pii pair<int,int>
#define ppiii pair< pair <int,int> ,int>
#define INF 1000000
#define endl '\n'
#define ll long long
#define pq priority_queue
const int mod=1e9+7;
int test=1;

int n,m;
ll x[300300];
ll p[300300];

ll gcd(ll a, ll b)
{
    ll r;
    while(b>0)
    {
        r=a%b;
        a=b;b=r;
    }
    return a;
}

int main()
{
    FAST
    freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    for(int i=1;i<=m;i++)
        cin>>p[i];
    ll y=x[1];
    for(int i=1;i<=n;i++)
        x[i]-=y;
    for(int i=3;i<=n;i++)
        x[i]=gcd(x[i],x[i-1]);
    for(int i=1;i<=m;i++)
        if(x[n]%p[i]==0)
        {
            cout<<"YES"<<endl;
            cout<<y<<" "<<i;
            return 0;
        }
    cout<<"NO";
}