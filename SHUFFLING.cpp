#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SHUFFLING"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
bool ok[mn];
vector<int> v[30], v1[30];
int id[30];

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
    string s;
    cin >> n >> s;
    string s1 = s;
    for (int i = 0; i < n; ++ i)
    {
        v[s[i] - 'a'].emplace_back(i);
        v1[s[i] - 'a'].emplace_back(i);
    }
    for (int i = 0; i < 26; ++ i)
    id[i] = i;
    sort (id, id + 26, [](int i, int j)
         {
             return v[i].size() > v[j].size();
         });
    for (int j = 0; j < 26; ++ j)
    {
        int i = id[j];
        char c = ('a' + i);
        for (int k = j + 1; k < 26 && v[i].size(); ++ k)
        while (v1[id[k]].size())
        {
            int j = id[k];
            if (v[i].empty()) break;
            s1[v1[j].back()] = c;
            v[i].pop_back();
            v1[j].pop_back();
        }
        if (v[i].empty()) continue;
        if (j != 0)
        while (v1[id[0]].size())
        {
            int j = id[0];
            if (v[i].empty()) break;
            s1[v1[j].back()] = c;
            v[i].pop_back();
            v1[j].pop_back();
        }
        if (v[i].size())
        {
            cout << "Impossible";
            return;
        }
    }
    cout << s1;
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