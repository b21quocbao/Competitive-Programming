#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SUMCOING"

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

pair<int, int> operator + (pair<int, int> x, int y)
{
    swap (x.first, x.second);
    x.first += y;
    return x;
}

int n;
int a[2010];
pair<int, int> f[2010][2010];

// pair<int, int> F (int i, int d)
// {
//     if (i > n) return {0, 0};
//     if (f[i][d].first) return f[i][d]; 
//     for (int j = i + 1; j <= i + 2 * d; ++ j)
//     f[i][d] = max (f[i][d], F (j, j - i) + (a[j - 1] - a[i - 1]));
//     return f[i][d];
// }

// template<class T>
// class IT
// {
//     T MAX (T a, T b)
//     {
//         return a + b;
//     }
//     void Assign (T& a, T b)
//     {
//         a += b;
//     }
//     public:
//         vector<T> it, la;
//         // int n;
//         bool Lazy;
//         // IT (int N = mn, bool LazY = 0)
//         // {
//         //     n = N;
//         //     it.resize(4 * n + 10);
//         //     la.resize(4 * n + 10);
//         //     Lazy = LazY;
//         //     clear();
//         // }   

//         IT ()
//         {
//             it.resize(4 * n + 10);
//             la.resize(4 * n + 10);
//             Lazy = 0;
//             clear();
//         }

//         void resize (int N)
//         {
//             n = N;
//             it.resize (4 * n + 10);
//             la.resize (4 * n + 10);
//         }

//         void lazy (int id, T w)
//         {
//             Assign (it[id], w);
//             if (!Lazy) return;
//             Assign (la[id], w);
//         }

//         void layd (int id)
//         {
//             if (!Lazy) return;
//             int i = id << 1;
//             lazy (i, la[id]);
//             lazy (i ^ 1, la[id]);
//             la[id] = 0;
//         }

//         void clear (int id = 1, int l = 1, int r = - 1)
//         {
//             if (r == - 1) r = n;
//             it[id] = 0;
//             if (l == r) return;
//             int i = id << 1, m = (l + r) >> 1;
//             clear (i, l, m);
//             clear (i ^ 1, m + 1, r);
//             it[id] = MAX (it[i], it[i ^ 1]);
//         }

//         void ud (int a, int b, T w, int id = 1, int l = 1, int r = - 1)
//         {
//             if (r == - 1) r = n;
//             if (l > b || r < a) return;
//             if (l >= a && r <= b)
//             {
//                 lazy (id, w);
//                 return;
//             }
//             int m = (l + r) >> 1, i = id << 1;
//             layd (id);
//             ud (a, b, w, i, l, m);
//             ud (a, b, w, i ^ 1, m + 1, r);
//             it[id] = MAX (it[i], it[i ^ 1]);
//         }

//         T qu (int a, int b, int id = 1, int l = 1, int r = - 1)
//         {
//             if (r == - 1) r = n;
//             if (l > b || r < a) return 0;
//             if (l >= a && r <= b)
//             return it[id];
//             int i = id << 1, m = (l + r) >> 1;
//             layd (id);
//             return MAX (qu (a, b, i, l, m), qu (a, b, i ^ 1, m + 1, r));
//         }
// };

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    // IT<pair<int, int> > it[n + 2];
    int sol = 0;
    for (int i = n; i >= 1; -- i)
    for (int j = 1; j <= i; ++ j)
    {
        if (i + j * 2 > n)
        f[i][j] = {a[n] - a[i - 1], 0};
        f[i][j] = max (f[i][j], f[i][j - 1]);
        if (i != j)
        f[i - j][(j + 1) / 2] = max (f[i - j][(j + 1) / 2], f[i][j] + (a[i - 1] - a[i - j - 1]));
        if (i == 1)
        sol = max (sol, f[i][j].first);
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