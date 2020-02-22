#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define maxn 100000
using namespace std;
struct seg
{
    int l, r, id;
} a[maxn+1];
int n, ans[maxn+1];
bool cmp(const seg &a, const seg &b)
{
    return a.l<b.l||(a.l==b.l&&a.r<b.r);
}
void solve()
{
    bool ok=0;
    sort(a+1, a+n+1, cmp);
    int R=a[1].r;
    ans[a[1].id]=1;
    for(int i=2; i<=n; i++){
        if(a[i].l>R){
            ok=1;
            for(int j=i; j<=n; j++) ans[a[j].id]=2;
            break;
        }
        else{
            ans[a[i].id]=1;
            R=max(R, a[i].r);
        }
    }
    if(!ok) cout<<-1<<'\n';
    else{
        for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
        cout<<'\n';
    }
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("C.inp", "r", stdin);
    //freopen("C.out", "w", stdout);
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i].l>>a[i].r;
            a[i].id=i;
        }
        solve();
    }
}