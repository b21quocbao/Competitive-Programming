#include <bits/stdc++.h>

#define fn "test"
#define fn1 "INDUST"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

template <typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
void write (T a)
{
    if (a < 0)
    {
        putchar ('-');
        write (-a); 
        return;
    }
    if (a < 10)
    {
        putchar ('0' + a);
        return;
    }
    write (a / 10);
    putchar ((char)('0' + (a % 10)));
}

int area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))); 
} 
  
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) 
{    
   int A = area (x1, y1, x2, y2, x3, y3); 
   int A1 = area (x, y, x2, y2, x3, y3); 
   int A2 = area (x1, y1, x, y, x3, y3); 
   int A3 = area (x1, y1, x2, y2, x, y); 
   if (A != A1 + A2 + A3)
   {
       cerr << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << x << " " << y << "\n";
   }
   return (A == A1 + A2 + A3); 
} 

int n, x[610], y[610], X[10010], Y[10010], W[10010], m;
pair<int, int> operator - (pair<int, int> x, pair<int, int> y)
{
    return {x.first - y.first, x.second - y.second};
}

int operator * (pair<int, int> x, pair<int, int> y)
{
    return x.first * y.second - x.second * y.first;
}

pair<int, int> a[610], b[10010];
int d[610][610], w[610], e[610][610];

void enter()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i].first >> a[i].second;
    }
    cin >> m;
    for (int i = 0; i < m; ++ i)
    {
        pair<int, int> x;
        int W;
        cin >> x.first >> x.second >> W;
        for (int k = 0, j = 1; k < n; ++ k)
        {
            if (a[k] == x) ++ w[k];
            if (j == k) j = (j + 1) % n;
            while ((a[j] - a[k]) * (x - a[k]) < 0) j = (j + 1) % n;
            d[k][j] += W;
        }
        for (int k = 0, j = 1; k < n; ++ k)
        {
            if (a[k] == x) ++ w[k];
            if (j == k) j = (j + 1) % n;
            while ((j != k) && (a[j] - a[k]) * (x - a[k]) <= 0) j = (j + 1) % n;
            if (j == k) continue;
            e[k][j] += W;
        }
    }
    for (int i = 0; i < n; ++ i)
    for (int j = i + 1, r = 0; j != i; r = d[i][j], j = (j + 1) % n)
    d[i][j] += r;
    for (int i = 0; i < n; ++ i)
    for (int j = i + 1, r = 0; j != i; r = e[i][j], j = (j + 1) % n)
    e[i][j] += r;
    int sol = INT_MIN;
    for (int i = 0; i < n; ++ i)
    for (int j = (i + 1) % n; j != i; j = (j + 1) % n)
    for (int k = (i + 1) % n; k != j; k = (k + 1) % n)
    {
        int r = d[i][j] - e[i][k] - e[k][j];
        sol = max (sol, r);
    }
    cout << sol;
}

void solve()
{

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