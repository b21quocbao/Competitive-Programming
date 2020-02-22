#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 100005
#define inf 1e17
int n,m,x,y,a[oo],minn[oo*5],f[oo*10],k;
bool t;
char s[oo],g;
void nhap(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]=='(') a[i]=a[i-1]+1;
        else a[i]=a[i-1]-1;
    }
}
void lazy(int id){
    if(f[id]==0) return;
    minn[id]+=f[id];
    f[id*2]+=f[id];
    f[id*2+1]+=f[id];
    f[id]=0;
}
void build(int id,int l,int r){
    if(l==r){
        minn[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    minn[id]=min(minn[id*2],minn[id*2+1]);
}
void update(int id,int l,int r,int u,int v){
    lazy(id);
    if(v<l || u>r) return;
    if(u<=l && r<=v){
        f[id]+=k;
        lazy(id);
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    minn[id]=min(minn[id*2],minn[id*2+1]);
}
int get(int id,int l,int r,int u,int v){
    lazy(id);
    if(v<l || u>r) return inf;
    if(u<=l && r<=v) return minn[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void xuly(){
    if(g==s[x]) return;
    s[x]=g;
    if(g=='(') k=2;
    else k=-2;
    update(1,1,n,x,n);
}
void xuly1(){
    int cuoi=get(1,1,n,y,y),z=get(1,1,n,x,y),dau;
    if(x==1) dau=0;
    else dau=get(1,1,n,x-1,x-1);
    if(z<dau || dau!=cuoi) cout<<0;
    else cout<<1;
}
main(){
    freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    nhap();
    build(1,1,n);
    while(m--){
        cin>>t>>x;
        if(t==0){
            cin>>g;
            xuly();
        }
        else{
            cin>>y;
            xuly1();
        }
    }
}
