#include <bits/stdc++.h>
#define int long long
#define MAXN 200005
#define sz(a) static_cast<long long>(a.size())
#define INF 2000000000000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
int n,a[MAXN];
main(){
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("test.inp", "r", stdin);
freopen("test.out", "w", stdout);
    //freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
    //freopen(".INP","r",stdin); freopen(".OUT","w",stdout);
    cin>>n; int i,j,ans=0;; double w,h;
    for (i=1;i<=n;i++){
        cin>>w>>h;
        if (w/h>=1.6&&w/h<=1.7||h/w>=1.6&&h/w<=1.7) ans++;
    }
    cout<<ans;
}