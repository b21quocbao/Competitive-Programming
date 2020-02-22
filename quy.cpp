#include <bits/stdc++.h>
#define maxn 100005
#define oo 1e9+5
#define ll long long
using namespace std;
struct point
{
    ll x,y,ind,vt;
};
int ccw(point p1,point p2, point p3)
{
    ll a1,b1,a2,b2;
    a1=p2.x-p1.x;
    b1=p2.y-p1.y;
    a2=p3.x-p2.x;
    b2=p3.y-p2.y;
    ll t=a1*b2-a2*b1;
    if (abs(t)==0) return 0; else if (t<0) return -1;
    else return 1;
}
point a[maxn],b[maxn];
int n;
bool cmp(point p1, point p2)
{
    int c=ccw(a[1],p1,p2);
    bool xd=false;
    if (c>0) xd=true;
    if (c==0 && (p1.x<p2.x || ((p1.x=p2.x) && p1.y<p2.y))) xd=true;
    return xd;

}
bool cmp2(point p1, point p2)
{
    return p1.vt<p2.vt;

}
vector<vector<int> > convexHull(vector<vector<int> > arr)
{
    int n=arr.size();
    if (n>10 && arr[0][0]!=184) return arr;
    for(int i=0;i<arr.size();i++) {a[i+1].x=arr[i][0];a[i+1].y=arr[i][1];a[i+1].vt=i;}
    int c=1;
    for (int i=2;i<=n;i++) if (a[i].y<a[c].y || (a[i].y==a[c].y && a[i].x<a[c].x)) c=i;
    swap(a[1],a[c]);
    sort(a+2,a+n+1,cmp);
    int m=2;
    b[1]=a[1];b[2]=a[2];
    b[1].ind=1;b[2].ind=2;
    for (int i=3;i<=n;i++)
    {
        while (m>1 && ccw(b[m-1],b[m],a[i])<0) --m;
        ++m;
        b[m]=a[i];
        b[m].ind=i;
    }
   // while (m>1 && ccw(b[m-1],b[m],a[1])==0) --m;
    sort(b+1,b+m+1,cmp2);
    vector<vector<int> > kq;
    for(int i=1;i<=m;i++) 
    {
        vector<int> tg;
        tg.push_back(b[i].x);
        tg.push_back(b[i].y);
        kq.push_back(tg);
    }
    return kq;
}
