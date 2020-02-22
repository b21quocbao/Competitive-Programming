#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
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

int id[mn], a[mn], b[mn];
bool ok[mn];

void enter()
{
    int n;
    cin >> n;
    cin.ignore();
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qu;
    for (int i = 1; i <= n; ++ i)
    {
        id[i] = i;
        string s;
        int sum = 0;
        getline (cin, s);
        for (char c : s)
        {
            if (c == '(')
            ++ a[i];
            else 
            -- a[i];
            b[i] = min (b[i], a[i]);
        }
        qu.emplace (b[i], i);
    }
    sort (id + 1, id + n + 1, [](int i, int j)
         {
             if (a[i] >= 0 && a[j] < 0) return true;
             if (a[i] < 0 && a[j] >= 0) return false;
             if (a[i] >= 0) 
             {
                 if (b[i] != b[j])
                 return (b[i] > b[j]);
                 return (a[i] > a[j]);
             }
             return a[i] > a[j];
         });
    int s = 0;
    vector<int> v;
    for (int j = 1; j <= n; ++ j)
    {
        int i = id[j];
        if (ok[i]) continue;
        if (a[i] >= 0)
        {
            if (s + b[i] < 0)
            {
                cout << "NO";
                return;
            }
            s += a[i];
            ok[i] = 1;
            v.emplace_back (i);
            continue;
        }
        ok[i] = 1;
        while (qu.size())
        {
            auto x = qu.top(); qu.pop();
            if (ok[x.second]) continue;
            if (s + a[i] + b[x.second] >= 0) break;
            if (s + b[x.second] < 0)
            {
                if (n == 66664)
                cerr << s << " " << s + b[x.second] << "\n";
                cout << "NO";
                return;
            }
            s += a[x.second];
            v.emplace_back(x.second);
            ok[x.second] = 1;
        }
        if (s + b[i] < 0)
        {
            cout << "NO";
            return;
        }
        s += a[i];
        v.emplace_back(i);
    }
    if (s)
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for (int i : v)
    cout << i << " ";
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
