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

bool ok1[30], ok[30][30];

void enter()
{
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline (cin, s);
    vector<pair<int, char> > v;
    int sol = 0, r = 0;
    memset (ok, 0, sizeof (ok));
    memset (ok1, 0, sizeof (ok1));
    char c1 = s[0];
    for (int i = 0; i < n; ++ i)
    {
        ok1[s[i] - 'a'] = 1;
        if (i)
        ok[s[i] - 'a'][s[i - 1] - 'a'] = 1;
        if (i && s[i] == s[i - 1]) ++ r;
        else r = 1;
        if (r >= 3) v.emplace_back(r, s[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    sol += v.size();
    for (char c = 'a'; c <= 'z'; ++ c)
    sol += ok1[c - 'a'];
    for (char c1 = 'a'; c1 <= 'z'; ++ c1)
    for (char c2 = 'a'; c2 <= 'z'; ++ c2)
    sol += ok[c1 - 'a'][c2 - 'a'];
    cout << sol << "\n";
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