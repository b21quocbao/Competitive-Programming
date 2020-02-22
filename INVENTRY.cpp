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
int fa[mn], ne[mn], d[mn], cn[mn];

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

int Fa (int i)
{
    if (i == - 1) return - 1;
    return (fa[i] == i ? i : fa[i] = Fa (fa[i]));
}

void enter()
{
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline (cin, s);
    int j = - 1;
    for (int i = s.size() - 1; i >= 0; -- i)
    if (s[i] == '#')
    {
        fa[i] = i;
        if (j == - 1) d[i] = max ((int)s.size() - 2 - i, 0);
        else if (j - i > 2) d[i] = j - i - 2;
        else fa[i] = j;
        cn[i] = 1;
        ne[i] = j;
        j = i;
    }
    else cn[i] = 0;
    for (int i = 1; i < s.size(); ++ i)
    cn[i] += cn[i - 1];
    int sol = 0;
    j = - 1;
    for (int i = 0; i < s.size(); ++ i)
    if (s[i] == '#')
    {
        if (i == j + 1) 
        {
            ++ j;
            continue;
        }
        if (i < s.size() - 1 && s[i + 1] == '.') 
        {
            sol += i - j - 1;
            ++ j;
            continue;
        }
        if (i == s.size() - 1) 
        {
            cout << - 1;
            return;
        }
        int x = Fa (i +8 1);
        if (x != - 1 && d[x] >= 2 * (cn[x] - cn[i]) - (x - i))
        {
            x += 2 * (cn[x] - cn[i]) - (x - i);
            int k = i;
            sol += (k - (j ++));
            for (k = i + 1; k <= x; k += 2)
            sol += (k - (j ++));
            k = x;
            for (int t = x; t >= i + 1; -- t)
            if (s[t] == '#')
            {
                sol += k - t;
                k -= 2;
            }
            i = x;
        }
        else
        {
            cout << - 1;
            return;
        }
    }
    cout << sol;
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int main()
{
    docfile();
    cin>>ntest;
    // cin.ignore();
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}