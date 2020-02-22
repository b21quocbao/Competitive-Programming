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
string s[mn];
bool ok[mn];
int vl[mn];
int id[mn];

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

void enter()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        ok[i] = 0;
        cin >> s[i];
        for (char c : s[i])
        if (c == 'm') ok[i] = 1;
        id[i] = i;
    }
    sort (id, id + n, [](int i, int j)
         {
             return s[i] < s[j];
         });
    for (int i = 0; i < n; ++ i)
    {
        vl[id[i]] = i;
        reverse(s[i].begin(), s[i].end());
    }
    sort (id, id + n, [](int i, int j)
         {
             return s[i] < s[j];
         });
    vector<int> v1, v2;
    for (int i = 0; i < n; ++ i)
    {
        int j = id[i];
        int x1 = upper_bound (v1.begin(), v1.end(), vl[j]) - v1.begin();
        int x2 = upper_bound (v2.begin(), v2.end(), vl[j]) - v2.begin();
        if ((x1 - ok[j]) % 2 == 0)
        {
            if (x1 == v1.size()) v1.emplace_back(vl[j]);
            else v1[x1] = vl[j];
        }
        if ((x2 - ok[j]) % 2)
        {
            if (x2 == v2.size()) v2.emplace_back(vl[j]);
            else v2[x2] = vl[j];
        }
    }
    cout << max (v1.size(), v2.size()) << "\n";
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