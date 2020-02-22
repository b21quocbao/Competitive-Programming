#include<bits/stdc++.h>
using namespace std;
int ok[10];
char a[10];
int ook[10];
int minn=1e9;
string s;
string res="000";
int n;
void xl()
{

    int dem=0;
    for(int i=0;i<3;i++)
    {
        if(ok[i]==0)
        a[i]='R';
        else if(ok[i]==1)
        a[i]='B';
        else a[i]='G';
    }
//    cout<<int(a[0])<<int(a[1])<<int(a[2])<<endl;
//    cout<<a[0]<<a[1]<<a[2]<<endl;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=a[i%3])
            dem++;
    }
    if(minn>dem)
    {
        minn=dem;
        res[0]=a[0];
        res[1]=a[1];
        res[2]=a[2];
    }
}
void snp(int dem)
{
    if(dem==3)
    {
        xl();
        return;
    }
    for(int i=0;i<3;i++)
    {
        if(ook[i]==0)
        {
            ook[i]=1;
            ok[dem]=i;
            snp(dem+1);
            ook[i]=0;
        }
    }
}
main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    cin>>n;
    cin>>s;
    if(s.length()<=3)
    {
        if(s.length()==1)
            cout<<0<<endl<<s;
        else if(s.length()==2)
        {
            if(s[0]==s[1])
                if(s[0]=='B')
                cout<<1<<endl<<"BG";
                else cout<<1<<endl<<"B"<<s[0];
            else
                cout<<0<<endl<<s;
        }
        else
        {
            if(s[0]==s[1]&&s[1]==s[2])
            {
                if(s[0]=='B')
                    cout<<2<<endl<<"BGR";
                else if(s[0]=='G')
                    cout<<2<<endl<<"GBR";
                else cout<<2<<endl<<"RGB";
            }
            else if(s[0]!=s[1]&&s[0]!=s[2]&&s[1]!=s[2])
                cout<<0<<endl<<s;
            else
            {
                cout<<1<<endl;
                if(s[0]==s[1])
                {
                    if(s[2]=='B')
                        cout<<"GRB";
                    else if(s[2]=='G')
                        cout<<"BRG";
                    else cout<<"BGR";
                }
                else if(s[1]==s[2])
                {
                    if(s[0]=='B')
                        cout<<"BGR";
                    else if(s[0]=='G')
                        cout<<"GBR";
                    else cout<<"RBG";
                }
                else
                {
                    if(s[1]=='B')
                        cout<<"RBG";
                    else if(s[1]=='G')
                        cout<<"RGB";
                    else cout<<"GRB";
                }
            }
        }
    }
    else
    {
        snp(0);
        cout<<minn<<endl;
        for(int i=0;i<n/3;i++)
            cout<<res;
        for(int i=0;i<n%3;i++)
            cout<<res[i];
    }
}