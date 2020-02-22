#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define read() 	        freopen("in.txt","r",stdin)
#define write()         freopen("out.txt","w",stdout)
#define sf(n) 	        scanf("%d",&n)
#define sfd(n)          scanf("%lf",&n)
#define sl(x)           scanf("%I64d",&x)
#define sfl(n) 	        scanf("%lld", &n)
#define sfc(n)          scanf(" %c",&n)
#define sful(n)         scanf("%ull",&n)
#define ull             unsigned long long int
#define endll           pf("\n")
#define pf              printf
#define pi              acos(-1.0)
#define eps 	        1e-10
#define mem(a,b)        memset(a,b,sizeof(a))
#define pb              push_back
#define xx              first
#define yy              second
#define pii             pair<int, int>
#define pll             pair<ll, ll>
#define MP make_pair
#define ll              long long
#define uniq(a)      a.erase(unique(a.begin(), a.end()), a.end())
bool Check(ll  N,int pos){return (bool)(N & (1LL<<pos));}
ll  Set(ll  N,int pos){	return N=N | (1LL<<pos);}
#define cnd tree[idx]
#define lnd tree[idx<<1]
#define rnd tree[(idx<<1)+1]
#define lndp (idx<<1),(b),((b+e)>>1)
#define rndp ((idx<<1)+1),(((b+e)>>1)+1),(e)
#define inf 1999999999
#define mod 1000000007
#define var    int ii=1,i,j,k,n,m,z=0,c=0,t,x,y,l,r,mid
//int dx[8]={0,0,1,1,-1,-1,1,-1};  //8 direction
//int dy[8]={1,-1,1,-1,1,-1,0,0};
//int dx[4]={1,-1,0,0};  //4 direction
//int dy[4]={0,0,1,-1};

int main()
{
	freopen ("test.inp", "r", stdin);
freopen ("test.ans", "w", stdout);
    ll var;
    cin>>n>>m>>k;
    c=k/m;
    if(k<m || k>(n-1)*m)
    {
        cout<<"NO"<<endl;return 0;
    }

    cout<<"YES"<<endl;
    y=1;
    x=k%m;
    l=0;
    for(i=1;i<=m;i++)
    {
        if(x>0)
        {
            x--;
            if(l%2)y-=(c+1);
            else y+=c+1;
            l++;
            cout<<y<<" ";
        }
        else
        {
            if(l%2)y-=c;
            else y+=c;
            l++;
            cout<<y<<" ";
        }
    }
}