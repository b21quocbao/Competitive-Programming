#include<bits/stdc++.h>
#define pii pair<int, int>
#define ppii pair<pii, pii>
#define vi vector<int>
#define vl vector<long long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define F1(i, a, b) for(int i=a; i<=b; i++)
#define F2(i, a, b) for(int i=a; i>=b; i--)
#define ull unsigned long long
#define mod 1000000000
using namespace std;
template<typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}
template <typename T>
void viet(T x){
  if(x>9) viet(x/10);
  putchar(x%10+'0');
}
string s[10];
int len(ll a1)
{
    if(a1==0) return 1;
    int foo=0;
    while(a1>0){
        foo++;
        a1/=10;
    }
    return foo;
}
vl add(vl a1, vl a2)
{
    ll sum=0, cr;
    vl a3;
    for(int i=0; i<max(a1.size(), a2.size()); i++){
        sum=(((i<a1.size())?a1[i]:0)+((i<a2.size())?a2[i]:0)+cr)%mod;
        a3.pb(sum%mod);
        cr=sum/mod;
    }
    while(sum){
        a3.pb(sum%mod);
        sum/=mod;
    }
    while(!a3.empty()&&a3.back()==0) a3.pop_back();
    return a3;
}
vl sub(vl a1, vl a2)
{
    vl a3;
    ll dif=0, cr;
    for(int i=0; i<max(a1.size(), a2.size()); i++){
        dif=(((i<a1.size())?a1[i]:0)-((i<a2.size()?a2[i]:0))-cr)%mod;
        if(dif<0){
            dif+=mod;
            cr=1;
        }
        else cr=0;
        a3.pb(dif);
    }
    while(!a3.empty()&&a3.back()==0) a3.pop_back();
    return a3;
}
vl mul1(vl a1, ll a2)
{
    vl a3;
    ll sum=0, cr=0;
    for(int i=0; i<a1.size(); i++){
        sum=(a1[i]*a2+cr)%mod;
        a3.pb(sum%mod);
        cr=sum/mod;
    }
    while(sum){
        a3.pb(sum%mod);
        sum/=mod;
    }
    while(!a3.empty()&&a3.back()==0) a3.pop_back();
    return a3;
}
vl mul2(vl a1, vl a2)
{
    vl a3, a4, a5=vl(1, 0);
    ll it=-1;
    for(int i=0; i<a1.size(); i++){
        a3.clear();
        a3=vl(it++, 0);
        a4=mul1(a2, a1[i]);
        for(int j=0; j<a4.size(); j++) a3.pb(a4[j]);
        a5=add(a5, a3);
    }
    while(!a5.empty()&&a5.back()==0) a5.pop_back();
    return a5;
}
ll Stol(string a1)
{
    ll sum=0;
    for(int i=0; i<a1.size(); i++) sum=sum*10+a1[i]-'0';
    return sum;
}
vl stov(string a1)
{
    vl a2;
    int it;
    string foo;
    for(int i=(int)a1.size()-1; i>=0; i-=9){
        it=max(0, i-9+1);
        foo=a1.substr(it, i-it+1);
        a2.pb(Stol(foo));
    }
    return a2;
}
void output(vl a1)
{
    int foo;
    cout<<a1.back();
    for(int i=(int)a1.size()-2; i>=0; i--) cout<<s[len(a1[i])]<<a1[i];
    cout<<'\n';
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("bignum.inp", "r", stdin);
    //freopen("bignum.out", "w", stdout);
    s[1]="0";
    for(int i=2; i<=8; i++) s[i]=s[i-1]+'0';
    string foo;
    vl a1, a2;
    cin>>foo; a1=stov(foo);
    cin>>foo; a2=stov(foo);
    output(add(a1, a2));
    output(sub(a1, a2));
    output((mul1(a1, 90)));
    output((mul2(a1, a2)));
}

