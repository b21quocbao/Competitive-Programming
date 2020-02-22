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

int a[6] = {4, 8, 15, 16, 23, 42};
int sol[6];
pair<int, int> v[mn];

void enter()
{
    int x, y;
    for (int i = 0; i < 6; ++ i)
    for (int j = 0; j < i; ++ j)
    v[a[i] * a[j]] = {i, j};
    cout << "? 1 2" << endl;
    cin >> x;
    cout << "? 2 3" << endl; 
    cin >> y;
    sol[0] = v[x].first;
    sol[1] = v[x].second;
    if (v[y].second == sol[0] || v[y].second == sol[1])
    swap (v[y].first, v[y].second);
    if (v[y].first == sol[0]) swap (sol[0], sol[1]);
    sol[2] = v[y].second;
    cout << "? 4 5" << endl; 
    cin >> x;
    cout << "? 5 6" << endl; 
    cin >> y;
    sol[3] = v[x].first;
    sol[4] = v[x].second;
    if (v[y].second == sol[3] || v[y].second == sol[4])
    swap (v[y].first, v[y].second);
    if (v[y].first == sol[3]) swap (sol[3], sol[4]);
    sol[5] = v[y].second;
    cout << "! ";
    for (int i = 0; i < 6; ++ i)
    cout << a[sol[i]] << " ";
    cout << endl;
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