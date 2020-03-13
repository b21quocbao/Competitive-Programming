/*
Code by b21
Time: 20:15 Sun 23/02/2020
*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;
typedef pair<int, int> ii;
#define X first
#define Y second

int tt, ntest = 1;
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("acm_training_F.inp"))
    {
        freopen("acm_training_F.inp", "r", stdin);
        freopen("acm_training_F.out", "w", stdout);
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

ii a[12309];


long long polygonArea(int n) 
{ 
    long long area = 0.0; 
  
    int j = n; 
    for (int i = 1; i <= n; i++) 
    { 
        area += (a[j].X + a[i].X) * (a[j].Y - a[i].Y); 
        j = i;  
    } 
  
    return abs(area); 
} 


ii origin;
void operator -= (ii &A, ii B){ A.X-=B.X; A.Y-=B.Y; }
bool ccw(ii O, ii A, ii B){ A-=O, B-=O; return A.X*B.Y > A.Y*B.X; }
bool cmp(ii A, ii B){ return ccw(origin, A, B); }

void enter()
{
    int t;
    cin >> t;
    long long s = 0;
    for (int i = 0; i < t; ++ i) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i ++)
        cin >> a[i].X >> a[i].Y;
        // sort(a + 1, a + n + 1);
        // origin = a[1];
        // sort(a + 2, a + n + 1, cmp);
        // a[0] = a[n]; 
        // a[n + 1] = a[1];
        // int j=1;
        // for (int i = 1; i <= n + 1; i ++) { 
        //     while (j > 2 && !ccw(a[j - 2], a[j - 1], a[i])) j --;
        //     a[j++] = a[i];
        // }
        // n = j - 2;
        s += polygonArea(n);
    }
    cout << s / 2;
}

void solve()
{

}

void print_result()
{

}

main()
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