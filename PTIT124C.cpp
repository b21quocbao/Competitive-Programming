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
int e[100][2];
int f[100];

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

void dfs (int u)
{
    if (!u) return;
    dfs (e[u][0]);
    dfs (e[u][1]);
    f[u] = 2 * max (f[e[u][0]], f[e[u][1]]);
}

void enter()
{
    string s;
    if (tt == 1)
    getline (cin, s);
    getline (cin, s);
    vector<int> v, st;
    int cnt = 0;
    f[0] = 1;
    for (int i = 0; i < s.size(); ++ i)
    if (s[i] == '[') 
    {
        v.emplace_back(++ cnt);
        e[cnt][0] = e[cnt][1] = 0;
    }
    else 
    {
        for (int j = 0; j < 2; ++ j)
        if (st.size() && st.back() > v.back())
        {
            e[v.back()][j] = st.back();
            st.pop_back();
        }
        st.emplace_back(v.back());
        v.pop_back();
    }
    if (!s.size())
    {
        cout << tt << " 1\n";
        return;
    }
    dfs (1);
    cout << tt << " " << f[1] << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}