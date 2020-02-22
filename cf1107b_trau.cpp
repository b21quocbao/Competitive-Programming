#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
	int q; cin >> q;
	while(q--)
    {
        int n; cin >> n;
        string s; cin >> s;
        if(s.length()==2&&s[0]>=s[1]||s.length()==3&&s[1]=='0')
        {
            cout << "NO" << '\n';
            continue;
        }
        else if(s.length()==4&&s[0]>s[2]||s.length()==4&&s[0]==s[2]&&s[1]>=s[3])
        {
            cout << "NO" << '\n';
            continue;
        }
        else cout << "YES" << '\n' << 2 << '\n';
        if(s[1]!='0')
        {
            cout << s[0] << " ";
        for(int i=1; i<n; i++) cout << s[i];
        }
        else
        {
            cout << s[0] << s[1] << " ";
            for(int i=2; i<n; i++) cout << s[i];
        }
        cout << '\n';
    }
}