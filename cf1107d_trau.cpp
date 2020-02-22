#include<bits/stdc++.h>
#define fi first
#define ll long long
#define pii pair<int, int>
#define se second
#define pb push_back
#define maxn 5200
using namespace std;
int n;
string s[maxn];
int a[maxn+1][maxn+1];
string hex2bi(int x)
{
    string ret;
    for(int i=1; i<=4; i++){
        ret=(char)(x%2+48)+ret;
        x/=2;
    }
    return ret;
}
int xuly(char c)
{
    if(isdigit(c)) return (c-'0');
    return 10+(c-'A');
}
int get_sum(pii i, pii j)
{
    return a[j.fi][j.se]-a[i.fi-1][j.se]-a[j.fi][i.se-1]+a[i.fi-1][i.se-1];
}
bool check(int x)
{
    int foo;
    for(int i=1; i<=n; i+=x){
        for(int j=1; j<=n; j+=x){
            foo=get_sum({i, j}, {i+x-1, j+x-1});
            if(foo!=0&&foo!=(x*x)) return 0;
        }
    }
    return 1;
}
main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);  
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("D.inp", "r", stdin);
    //freopen("", "w", stdout);
    cin>>n;
    string s1;
    int foo;
    for(int i=1; i<=n; i++){
        cin>>s1;
        for(int j=0; j<s1.size(); j++){
            foo=xuly(s1[j]);
            s[i-1]+=hex2bi(foo);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j]=(s[i-1][j-1]-'0')+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
            //cout<<a[i][j]<<" ";
        }
        //cout<<'\n';
    }
    for(int i=n; i>1; i--){
        if(n%i==0&&check(i)){
            cout<<i<<'\n';
            return 0;
        }
    }
    cout<<1<<'\n';
}