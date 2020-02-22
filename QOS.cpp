#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int, int>
#define ll long long
#define pb push_back
#define maxn 1000
using namespace std;
const int oo=2*1e9;
int n, m, minc=101, t, k, dist[maxn+1];
int done[maxn+1], mind, cnt=0, curd=0;
stack<int> st;
vector<pii> ke[maxn+1];
bool ok=0;
void dijkstra()
{
    for(int i=1; i<=n; i++) dist[i]=oo;
    dist[1]=0;
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push({0, 1});
    int u, foo;
    while(!pq.empty()){
        while(!pq.empty()&&done[pq.top().se]) pq.pop();
        if(pq.empty()) break;
        u=pq.top().se;
        pq.pop();
        done[u]=1;
        for(pii i:ke[u]){
            foo=dist[u]+i.se;
            if(foo<dist[i.fi]){
                dist[i.fi]=foo;
                pq.push({dist[i.fi], i.fi});
            }
        }
    }
}
void dfs1(int u)
{
    if(ok) return;
    if(u==t){
        cnt++;
        if(cnt==k){
            ok=1;
            stack<int> ans;
            while(!st.empty()&&st.top()!=1){
                ans.push(st.top());
                st.pop();
            }
            ans.push(1);
            cout<<ans.size()<<'\n';
            while(!ans.empty()){
                cout<<ans.top()<<" ";
                ans.pop();
            }
        }
        return;
    }
    for(pii i:ke[u]){
        if(!done[i.fi]&&curd+i.se<=mind){
            done[i.fi]=1;
            curd+=i.se;
            st.push(i.fi);
            dfs1(i.fi);
            done[i.fi]=0;
            curd-=i.se;
            cerr << st.size() << "\n";
            st.pop();
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin>>n>>m>>t>>k;
    int u, v, c;
    for(int i=1; i<=m; i++){
        cin>>u>>v>>c;
        ke[u].pb({v, c});
        minc=min(minc, c);
    }
    if(n<=10){
        for(int i=1; i<=n; i++) if(!ke[i].empty()) sort(ke[i].begin(), ke[i].end());
        dijkstra();
        if(!done[t]) cout<<-1<<'\n';
        else{
            mind=dist[t]+minc;
            for(int i=1; i<=n; i++) done[i]=0;
            done[1]=1;
            st.push(1);
            //for(pii i:ke[1]) cout<<i.fi<<" "<<i.se<<'\n';
            dfs1(1);
            if(!ok) cout<<-1<<'\n';
        }
        return 0;
    }
}

