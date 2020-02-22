#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MQUEEN"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
unordered_map<long long , int> mu;
int n;
int ok[mn];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};

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

bool kt1 (pair<int, int> i)
{
    return (i.first >= 0 && i.first < n && i.second >= 0 && i.second < n);
}

bool kt (vector<pair<int, int> > v)
{
    vector<int> e;
    bool Ok = 1;
    for (auto i : v)
    {
        if (++ ok[i.first] == 2) Ok = 0;
        if (++ ok[i.second + 200] == 2) Ok = 0;
        if (++ ok[i.first - i.second + 400] == 2) Ok = 0;
        if (++ ok[i.first + i.second + 600] == 2) Ok = 0;
        e.emplace_back(i.first);
        e.emplace_back(i.second + 200);
        e.emplace_back(i.first - i.second + 400);
        e.emplace_back(i.first + i.second + 600);
    }
    for (int i : e)
    ok[i] = 0;
    return Ok;
}

int ch (vector<pair<int, int> > v)
{
    long long r = 0;
    for (auto i : v)
    {
        r = r * n + i.first;
        r = r * n + i.second;
    }
    return r;
}

void enter()
{
    cin >> n;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++ i)
    {
        string s;
        cin >> s;
        v.emplace_back((n - (s[1] - '0')), s[0] - 'a');
    }
    mu[ch (v)] = 0;
    priority_queue<vector<pair<int, int> > > qu;
    qu.push(v);
    while (qu.size())
    {
        auto v = qu.front();
        int x = mu[ch (v)];
        qu.pop();
        if (kt (v))
        {
            cout << x;
            return;
        }
        for (auto& i : v)
        for (int h = 0; h < 4; ++ h)
        {
            auto j = i;
            i.first += hx[h];
            i.second += hy[h];
            int r = ch (v);
            if (kt1 (i) && (mu.find (r) == mu.end())) 
            {
                qu.push (v);
                mu[r] = x + 1;
            }
            i = j;
        }
    }
    cout << - 1;
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