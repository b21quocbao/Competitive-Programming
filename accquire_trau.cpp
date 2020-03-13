#include <bits/stdc++.h>
 
#define fn1 "GROUP"
 
using namespace std;
 
const int mn = 3 * int(1e5) + 10;
const int mod = 1 * int(1e5) + 10;
const int mm = 1 * int(1e5) + 10;
 
int tt, ntest = 1;
int n;
pair<int, int> a[mn];
vector <pair <long long, long long> > d;
int p;
 
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   if (ifstream("test.inp"))
   {
       freopen("test.inp", "r", stdin);
       freopen("test.ans", "w", stdout);
   }else if (ifstream(fn1".inp"))
   {
       freopen(fn1".inp", "r", stdin);
       freopen(fn1".out", "w", stdout);
   }
}
 
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
 
void write(int a)
{
    int i = 0;
    char S[20];
    if (a == 0) {putchar('0'); return;}
    while(a > 0)
    {
        S[i++] = a % 10 + '0';
        a /= 10;
    }
    --i;
    while(i >= 0) putchar(S[i--]);
}
 
void enter()
{
    n = read();
    for (int i = 0; i < n; ++ i)
    {
    	a[i].first = read();
    	a[i].second = read();
    }
}
 
bool kt (int a, int b, int c)
{
    long long res1 = (d[a].second - d[b].second) * (d[b].first - d[c].first);
    long long res2 = (d[c].second - d[b].second) * (d[b].first - d[a].first);
    return res1 < res2;
}
 
void ud (long long a, long long b)
{
    d.push_back({a, b});
    while (d.size() >= 3 && kt (d.size() - 3, d.size() - 2, d.size() - 1))
	d.erase(d.end() - 2);
}
 
long long s (pair <long long, long long> d, long long x)
{
    return d.first * x + d.second;
}
 
long long query (long long x)
{
    if (p >= d.size()) p = d.size() - 1;
    while (p < d.size() - 1 && s(d[p + 1], x) < s(d[p], x)) ++ p;
    return s (d[p], x);
}
 
void solve()
{
	sort (a, a + n);
	vector < pair<int, int> > v;
    for (int i = 0; i < n; ++ i)
    {
        while (v.size() && v.back().second <= a[i].second) v.pop_back();
        v.push_back(a[i]);
    }
    ud (v[0].second, 0);
    for (int i = 0; i < v.size(); ++ i)
    {
        long long f = query(v[i].first);
        if (i != v.size() - 1)
        ud (v[i + 1].second, f);
        else cout << f;
    }
}
 
void print_result()
{
 
}
 
int main()
{
    docfile();
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}