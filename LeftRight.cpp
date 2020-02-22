#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

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

// class LeftRight
// {
//     public:

//     vector<int> L, R, a;
//     int n;
//     bool lh;

//     LeftRight (int N, bool Lh = 0) : n (N), k (K);
//     {
//         L.resize (n + 2);
//         R.resize (n + 2);
//         lh = Lh;
//     }

//     void AddElement(int x)
//     {
//         a.emplace_back (x);
//     }

//     void operator = (int x[])
//     {
//         a.reserve (n + 2);
//         a.emplace_back(0);
//         for (int i = 1; i <= n; ++ i)
//         a.emplace_back(x[i]);
//     }

//     void process ()
//     {
//         for (int i = 1; i <= n; ++ i)
//         {
        
//         } 
//     }
// }

bool myfunction (int i,int j) { return (i<j); }

template<class T, class compare >
class IT
{
    compare 
    void ud (T u, T v)
    {

    }
};
void ud (T u, T v, compare cmp)
{
    int sol = 0;
    if (cmp (u, v)) cout << "dmm";
}

void enter()
{
    // IT <int, cmp> it;
    ud (3, 1);
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