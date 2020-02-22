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

string s;
int n;

int main()
{
    FAST
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]>s[i+1])
        {
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<i+2;
            return 0;
        }
    }
    cout<<"NO";
}