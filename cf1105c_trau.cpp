#include<bits/stdc++.h>
#define base 1000000007
#define int long long
using namespace std;
//int a[100005];
int f[300005][4];
int l,r,n;
int dem[4];

int F(int i,int j)
{
    //if(i==n) cerr<<j<<endl;
   // cerr<<i<<" "<<j<<endl;
    if(i==n&&j==0) return 1;
    else if(i==n) return 0;//dem[(3-j)%3];
    //else if(i==n) return 0;

    if(f[i][j]!=-1) return f[i][j];
    f[i][j]=0;

    for(int k=0;k<=2;k++)
    {

    int tmp=(j+k)%3;

    f[i][j]=(f[i][j]+dem[k]*F(i+1,tmp)%base)%base;;
    }
    return f[i][j];
}
main()
{
    freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
    cin>>n>>l>>r;
    int l1=l/3*3;
    int r1=r/3*3;

    dem[0]=(r1-l1)/3+1;
    dem[1]=(r1-l1)/3;
    dem[2]=(r1-l1)/3;
    if(r%3>=1) dem[1]++;
    if(r%3>=2) dem[2]++;

    if(l%3>0) dem[0]--;
    if(l%3>1) dem[1]--;
   // if(l%3<=2&&r%3>=2) dem[2]++;
    memset(f,-1,sizeof(f));
  //  cerr<<dem[0]<<endl;

    cout<<F(0,0);
}