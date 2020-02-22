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

vector<bool> ok;
int k;
string s, s1, s2, dd;

void print (string dd)
{
    cout << "YES\n";
    int i = 0;
    for (char& c : dd)
    if (c == '#')
    {
        while (ok[i]) ++ i;
        c = (char)('a' + i);
        ++ i;
    }
    cout << dd;
}

bool attemp (int vt, int d, bool ok1)
{
    if (vt == k) return 1;
    char C, D;
    if (!ok1)
    {
        C = s1[vt] + 1;
        D = s2[vt] - 1;
    }
    else
    {
        if (d) 
        {
            C = 'a';
            D = s2[vt] - 1;
        }
        else
        {
            C = s1[vt] + 1;
            D = (char)('a' + (k - 1));
        }
    }
    for (char c = C; c <= D; ++ c)
    if (!ok[c - 'a'])
    {
        ok[c - 'a'] = 1;
        dd[s[vt] - 'a'] = c;
        return 1;
    }
    if (!d)
    {
        if (ok[s1[vt] - 'a']) return 0;
        ok[s1[vt] - 'a'] = 1;
        dd[s[vt] - 'a'] = s1[vt];
        int i;
        for (i = vt + 1; i < k; ++ i)
        if (dd[s[i] - 'a'] != '#')
        {
            if (dd[s[i] - 'a'] < s1[i] || dd[s[i] - 'a'] > s2[i])
            return 0;
        }
        else if (s1[i] == s2[i])
        {
            if (ok[s1[i] - 'a']) return 0;
            ok[s1[i] - 'a'] = 1;
            dd[s[i] - 'a'] = s1[i];
        }
        else break;
        return attemp (i, 0, 1);
    }
    else
    {
        if (ok[s2[vt] - 'a']) return 0;
        ok[s2[vt] - 'a'] = 1;
        dd[s[vt] - 'a'] = s2[vt];
        int i;
        for (i = vt + 1; i < k; ++ i)
        if (dd[s[i] - 'a'] != '#')
        {
            if (dd[s[i] - 'a'] < s1[i] || dd[s[i] - 'a'] > s2[i])
            return 0;
        }
        else if (s1[i] == s2[i])
        {
            if (ok[s1[i] - 'a']) return 0;
            ok[s1[i] - 'a'] = 1;
            dd[s[i] - 'a'] = s1[i];
        }
        else break;
        return attemp (i, 1, 1);
    }
}

void enter()
{
    cin >> k;
    cin.ignore();
    ok.clear();
    s.clear();
    s1.clear();
    s2.clear();
    dd.clear();
    getline (cin, s);
    getline(cin, s1);
    getline (cin, s2);
    int i;
    dd.resize(k, '#');
    ok.resize (k, 0);
    for (i = 0; i < k; ++ i)
    if (dd[s[i] - 'a'] != '#')
    {
        if (dd[s[i] - 'a'] < s1[i] || dd[s[i] - 'a'] > s2[i])
        {
            cout << "NO";
            return;
        }
        if (s1[i] == s2[i]) continue;
        if (s1[i] > s[i] - )
        id = - 1;
        break;
    }
    else if (s1[i] == s2[i])
    {
        if (ok[s1[i] - 'a'])
        {
            cout << "NO";
            return;
        }
        ok[s1[i] - 'a'] = 1;
        dd[s[i] - 'a'] = s1[i];
    }
    else break;
    auto DD = dd;
    auto Ok = ok;
    if (attemp (i, 0, 0)) 
    {
        print (dd);
        return;
    }
    dd = DD;
    ok = Ok;
    if (attemp (i, 1, 0))
    {
        print (dd);
        return;
    }
    cout << "NO";
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
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}