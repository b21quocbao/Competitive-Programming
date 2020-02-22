#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
stack<int> st;
int x, n, a[maxn+1], ans[maxn+1], sl=0;
bool avail[maxn+1];
main()
{
    freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("B.INP", "r", stdin);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]; avail[i]=true;
    }
    for(int i=n; i>0; i--)
    {
        st.push(a[i]);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(!avail[x]) ans[i]=0;
        else
        {
            sl=0;
            while(st.top()!=x)
            {
                avail[st.top()]=false; st.pop(); sl++;
            }
            avail[x]=false; sl++; st.pop();
            ans[i]=sl;
        }
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;

}
