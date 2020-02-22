#include<bits/stdc++.h>
using namespace std;
long long n;
int ok[10];
int dem=0;
vector <int> a;
main()
{
    freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
    cin>>n;
    if(n%10==n)
        cout<<9;
    else
    {
        if(n%10==0)
        {
            n++;
            dem++;
        }
        while(n%10!=n)
        {
            int d=0;
//            cout<<n<<" ";
            while(n%10==0)
            {
                d=1;
                n=n/10;
//                cout<<n<<" ";
            }
            if(n%10==n)
                break;
            int add=10-n%10;
//            cout<<add<<" ";
            n=n+add;
            dem+=add;
        }
        cout<<dem+9;
    }
}