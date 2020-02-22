#include <bits/stdc++.h>

#define int long long 
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1000000;

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

void ax (string s, vector<pair<char, int> >& v)
{
    int x = 0;
    char c1;
    for (char c : s)
    {
        if (isalpha(c)) 
        {
            if (x) v.emplace_back(c1, x);
            x = 0;
            c1 = c;
        }
        else
        x = x * 10 + (c - '0');
    }
    v.emplace_back(c1, x);
}

void enter()
{
    string c;

    if (!(cin >> c)) exit (0);
    cout << c << ": ";
    string s1;
    cin >> s1;
    vector<pair<char, int> > a, b;
    string s2;
    if (c[1] == '1')
    {
        cin >> s2;
        ax (s1, a);
        ax (s2, b);
        if (a.back().first == b[0].first)
        {
            a[a.size() - 1].second += b[0].second;
            for (int i = 1; i < b.size(); ++ i)
            a.emplace_back(b[i]);
        }
        else
        {
            for (int i = 0; i < b.size(); ++ i)
            a.emplace_back(b[i]);
        }
        for (auto x : a)
        cout << x.first << x.second; 
    } 
    else if (c[1] == '2')
    {
        int p, c;
        bool ok = 0;
        cin >> p >> c;
        ax (s1, a);
        int s = 0;
        for (int i = 0; i < a.size(); ++ i)
        {
            s += a[i].second;
            if (c + p - 1 <= s)
            {
                a[i].second = (s - (p + c) + 1) + max ((p - (s - a[i].second + 1)), 0ll);
                int k = - 1;
                cerr << a[i].second << "\n";
                for (int j = 0; j < a.size(); ++ j)
                if (a[j].second)
                {
                    if (k != - 1 && a[k].first == a[j].first)
                    {
                        a[k].second += a[j].second;
                        a[j].second = 0;
                    }
                    else
                    k = j;
                }
                for (int j = 0; j < a.size(); ++ j)
                if (a[j].second)
                cout << a[j].first << a[j].second;
                break;
            }
            if (s >= p && !ok)
            {
                ok = 1; 
                a[i].second -= (s - p + 1);
            }
            else if (s - a[i].second + 1 > p && c + p - 1 >= s)
            a[i].second = 0;
            
        }
    }
    else if (c[1] == '3')
    {
        int p, c;
        ax (s1, a);
        cin >> p >> c;
        int s = 0;
        for (int i = 0; i < a.size(); ++ i)
        {
            s += a[i].second;
            if (s >= p + c - 1)
            {
                cout << a[i].first << p + c - 1 - max (s - a[i].second, p - 1);
                break;
            }
            if (s >= p)
            cout << a[i].first << min (s - p + 1, a[i].second);
        }
    }
    else
    {
        int p;
        cin >> s2 >> p;
        -- p;
        ax (s1, a);
        ax (s2, b);
        int s = 0;
        if (!p)
        {
            int c = b.size();
            if (b.back().first == a[0].first)
            {
                a[0].second += b.back().second;
                c = b.size() - 1;
            }
            for (int i = 0; i < c; ++ i)
            cout << b[i].first << b[i].second;
            for (int i = 0; i < a.size(); ++ i)
            cout << a[i].first << a[i].second;
            return;
        }
        for (int i = 0; i < a.size(); ++ i)
        {
            s += a[i].second;
            if (s < p) continue;
            if (s != p)
            {
                int d = 0, c = b.size() - 1;
                int x = p - (s - a[i].second);
                int y = s - p;
                if (b[0].first == a[i].first)
                {
                    x += b[0].second;
                    d = 1;
                }
                if (b.size() > 1 && b.back().first == a[i].first)
                {
                    y += b.back().second;
                    c = b.size() - 2;
                }
                for (int j = 0; j < i; ++ j)
                cout << a[j].first << a[j].second;
                if (c - d + 1 == 0) x += y;
                cout << a[i].first << x;
                for (int i = d; i <= c; ++ i)
                cout << b[i].first << b[i].second;
                if (c - d + 1) cout << a[i].first << y;
                for (int j = i + 1; j < a.size(); ++ j)
                cout << a[j].first << a[j].second;
                break;
            }
            else
            {
                if (i == a.size() - 1)
                {
                    if (a.back().first == b[0].first)
                    {
                        for (int j = 0; j < a.size() - 1; ++ j)
                        cout << a[j].first << a[j].second;
                        cout << a.back().first << a.back().second + b[0].second;
                        for (int j = 1; j < b.size(); ++ j)
                        cout << b[j].first << b[j].second;
                    }
                    else
                    {
                        for (int i = 0; i < a.size(); ++ i)
                        cout << a[i].first << a[i].second;
                        for (auto x : b)
                        cout << x.first << x.second;
                    }
                    break;
                }
                else
                {
                    int d = 0, c = b.size() - 1;
                    if (a[i].first == b[0].first)
                    {
                        a[i].second += b[0].second;
                        d = 1;
                    }
                    if (b.size() >= 2 && a[i + 1].first == b.back().first)
                    {
                        a[i + 1].second += b.back().second;
                        c = b.size() - 2;
                    }
                    for (int j = 0; j <= i; ++ j)
                    cout << a[j].first << a[j].second;
                    for (int i = d; i <= c; ++ i)
                    cout << b[i].first << b[i].second;
                    for (int j = i + 1; j < a.size(); ++ j)
                    cout << a[j].first << a[j].second;
                    break;
                }
            }
        }
    }
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int32_t main()
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