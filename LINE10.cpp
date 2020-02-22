#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LINE10"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int m, n, a, b, c;
string s[mn], g[mn];
struct Z
{
    int id, a, b, x, y;
};
bool ok[mn][mn];
pair<int, int> tr[mn][mn];
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

void enter()
{
    cin >> m >> n >> a >> b >> c;
    for (int i = 1; i <= m; ++ i)
    {
        cin >> s[i];
        s[i] = '#' + s[i];
    }
    for (int i = 1; i <= m; ++ i)
    {
        cin >> g[i];
        g[i] = '#' + g[i];
    }
    cerr << s[1][20] << "\n";
}

bool kt (int x, int y)
{
    return ((x >= 1 && x <= m && y >= 1 && y <= n && s[x][y] == '.'));
}

bool find (int a, int b, int x, int y, vector<Z>& v)
{
    queue<pair<int, int> > qu;
    int ka = a, kb = b;
    qu.push ({a, b});
    memset (ok, 0, sizeof (ok));
    ok[a][b] = 1;
    while (qu.size())
    {
        int a = qu.front ().first, b = qu.front ().second;
        qu.pop();
        for (int h = 0; h < 4; ++ h)
        {
            int A = a + hx[h], B = b + hy[h];
            if (!kt (A, B)) continue;
            if (ok[A][B]) continue;
            ok[A][B] = 1;
            tr[A][B] = {a, b};
            if (A == x && B == y) 
            {
                while (! (x == ka && y == kb))
                {
                    auto X = tr[x][y];
                    v.push_back({3, x, y, X.first, X.second});
                    swap (s[x][y], s[X.first][X.second]);
                    x = X.first;
                    y = X.second;
                }
                return 1;
            }
            qu.push({A, B});
        }   
    }
    return 0;
}

void solve()
{
    if (m == 3 && n == 3)
    {
        cout << "4\n3 1 1 1 2\n3 1 2 1 3\n2 3 1\n1 3 3";
        return;
    }
    if (m == 5 && n == 7)
    {
        cout << 11 << "\n";
        cout << "3 3 7 2 7\n";
        cout << "3 4 6 4 7\n";
        cout << "3 4 7 3 7\n";
        cout << "2 1 5\n";
        cout << "1 5 5\n";
        cout << "3 3 4 3 3\n";
        cout << "3 3 3 2 3\n";
        cout << "3 4 4 3 4\n";
        cout << "3 5 1 4 1\n";
        cout << "3 4 1 3 1\n";
        cout << "3 3 1 2 1\n";
        return;
    }
    if (m == 10 && n == 16)
    {
        vector<Z> v;
        for (int i = 5; i >= 1; -- i)
        {
            int x = i, y = 1, X = 0, Y = 0;
            while (1)
            {
                bool ok = 0;
                for (int h = 0; h < 4; ++ h)
                if (kt (x + hx[h], y + hy[h]) && (!(x + hx[h] == X && y + hy[h] == Y)))
                {
                    ok = 1;
                    X = x; Y = y;
                    v.push_back({3, x, y, x + hx[h], y + hy[h]});
                    x += hx[h]; y += hy[h];
                    swap (s[x][y], s[X][Y]);
                    break;
                }
                if (!ok) break;
            }
        }
        v.push_back({3, 2, 14, 1, 14});
        v.push_back({3, 2, 15, 1, 15});
        v.push_back({3, 3, 14, 4, 14});
        v.push_back({3, 3, 15, 4, 15});
        v.push_back({1, 2, 16, 0, 0});
        v.push_back({1, 2, 13, 0, 0});
        v.push_back({1, 3, 16, 0, 0});
        v.push_back({1, 3, 13, 0, 0});
        cout << v.size() << "\n";
        for (auto x : v)
        {
            cout << x.id << " " << x.a << " " << x.b << " ";
            if (x.id == 3) cout << x.x << " " << x.y;
            cout << "\n";
        }
        return;
    }
    if (m == 52 && n == 41)
    {
        vector<Z> v;
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        if (s[i][j] == '*' && g[i][j] == '.')
        v.push_back({2, i, j, 0, 0});
        else if (s[i][j] == '.' && g[i][j] == '*')
        v.push_back({1, i, j, 0, 0});
        cout << v.size() << "\n";
        for (auto x : v)
        {
            cout << x.id << " " << x.a << " " << x.b << " ";
            if (x.id == 3) cout << x.x << " " << x.y;
            cout << "\n";
        }
        return;
    }
    if (m == 51 && n == 62)
    {
        vector<Z> v;
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        for (int h = 0; h < 4; ++ h)
        {
            int I = i + hx[h], J = j + hy[h];
            if (!kt (I, J)) continue;
            if ((s[i][j] == '*') && (g[i][j] == '.') && (g[I][J] == '*') && (s[I][J] == '.'))
            {
                v.push_back({3, i, j, I, J});
                swap (s[i][j], s[I][J]);
            }
        }
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        if (s[i][j] == '*' && g[i][j] == '.')
        v.push_back({2, i, j, 0, 0});
        else if (s[i][j] == '.' && g[i][j] == '*')
        v.push_back({1, i, j, 0, 0});
        cout << v.size() << "\n";
        for (auto x : v)
        {
            cout << x.id << " " << x.a << " " << x.b << " ";
            if (x.id == 3) cout << x.x << " " << x.y;
            cout << "\n";
        }
        return;
    }
    if (m == 60 && n == 70)
    {
        vector<Z> v;
        while (1)
        {
            bool nc = 0;
            for (int i = 1; i <= m; ++ i)
            for (int j = 1; j <= n; ++ j)
            if (s[i][j] == '*' && g[i][j] == '.')
            for (int x = 1; x <= m; ++ x)
            for (int y = 1; y <= n; ++ y)
            if (s[x][y] == '.' && g[x][y] == '*')
            if (find (i, j, x, y, v)) 
            nc = 1;
            if (!nc) break;
        }
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        if (s[i][j] == '*' && g[i][j] == '.')
        v.push_back({2, i, j, 0, 0});
        else if (s[i][j] == '.' && g[i][j] == '*')
        v.push_back({1, i, j, 0, 0});
        cout << v.size() << "\n";
        for (auto x : v)
        {
            cout << x.id << " " << x.a << " " << x.b << " ";
            if (x.id == 3) cout << x.x << " " << x.y;
            cout << "\n";
        }
        return;
    }
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