#include <bits/stdc++.h>
#define int long long
#define MAXN 100005
#define sz(a) static_cast<long long>(a.size())
#define INF 2000000000000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
int n,t; string s;
double tg=0;
main()
{
    cin>>t; int i,j,k;
    while (t--){
        cin>>n; map<string,int> m; tg=0;
        for (i=1;i<=n;i++){
            cin>>s; double h=0;
            h+=0.2; int v1=0,v2=0;
            for (j=1;j<s.size();j++){
                v1=0; v2=0;
                if (s[j]=='f'||s[j]=='d') v1=1;
                if (s[j-1]=='f'||s[j-1]=='d') v2=1;
                if (v1==v2) h+=0.4;
                else h+=0.2;
            }
            //cout<<h<<'\n';
            if (m[s]>0) h/=2; m[s]++;
            tg+=h;
        }
        cout<<tg*10<<'\n';
    }
}
bai1