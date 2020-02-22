
#include<bits/stdc++.h>
#define fi first
#define ll long long
#define pii pair<int, int>
#define se second
#define pb push_back
using namespace std;
const int N=102;
const ll oo=1e8;
ll dp[N][N][2][N], ans[N][N], a[N];
int n;
string s;
ll cal_dp(int l, int r, int id, int cnt);
ll cal_ans(int l, int r)
{
    if(ans[l][r]!=-1) return ans[l][r];
    if(l>r) return 0;
    ans[l][r]=0;
    for(int id=0; id<=1; id++){
        for(int cnt=1; cnt<=r-l+1; cnt++){
            ans[l][r]=max(ans[l][r], cal_dp(l, r, id, cnt)+a[cnt]);
        }
    }
    return ans[l][r];
}
ll cal_dp(int l, int r, int id, int cnt)
{
    if(dp[l][r][id][cnt]!=-1) return dp[l][r][id][cnt];
    if(cnt==0) return cal_ans(l, r);
    dp[l][r][id][cnt]=-oo;
    for(int mid=l; mid<=r; mid++){
        if(s[mid-1]-'0'==id){
            dp[l][r][id][cnt]=max(dp[l][r][id][cnt], cal_ans(l, mid-1)+cal_dp(mid+1, r, id, cnt-1));
        }
    }
    return dp[l][r][id][cnt];
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    cin>>n>>s;
    for(int i=1; i<=n; i++) cin>>a[i];
    memset(ans, -1, sizeof(ans));
    memset(dp, -1, sizeof(dp));
    cout<<cal_ans(1, n)<<'\n';
}
