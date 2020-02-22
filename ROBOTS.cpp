x`#include <bits/stdc++.h>

#define fn "test"
#define fn1 "ROBOTS"

using namespace std;

const int mn = 2 * (int)(1e4) + 10;
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
#define y1 __y1


struct Z
{
    long long x, y1, y2;
    int id;
    Z (){}
    Z (const long long& X, const long long& Y1, const long long& Y2, const int& Id)
    {
        x = X; y1 = Y1; y2 = Y2; id = Id;
    }
    bool operator < (const Z& b) const
    {
        return x < b.x;
    }
};

template<class T>
class IT
{
    void Assign (T& a, T b)
    {
        a += b;
    }
    public:
        int it[mn << 2], la[mn << 2];
        int n;
        bool Lazy;
        IT (int N = mn, bool LazY = 0)
        {
            n = N;
            Lazy = LazY;
            // clear();
        }   

        void resize (int N)
        {
            n = N;
        }

        void lazy (int id, T w)
        {
            Assign (it[id], w);
            Assign (la[id], w);
        }

        void layd (int id)
        {
            if (!la[id]) return;
            int i = id << 1;
            lazy (i, la[id]);
            lazy (i ^ 1, la[id]);
            la[id] = 0;
        }

        void clear (int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            it[id] = la[id] = 0;
            if (l == r) return;
            int i = id << 1, m = (l + r) >> 1;
            clear (i, l, m);
            clear (i ^ 1, m + 1, r);
        }

        void ud (int a, int b, T w, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > b || r < a) return;
            if (l >= a && r <= b)
            {
                lazy (id, w);
                return;
            }
            int m = (l + r) >> 1, i = id << 1;
            layd (id);
            ud (a, b, w, i, l, m);
            ud (a, b, w, i ^ 1, m + 1, r);
            it[id] = min (it[i], it[i ^ 1]);
        }

        bool qu (int a, int b, int id = 1, int l = 1, int r = - 1)
        {
            if (r == - 1) r = n;
            if (l > b || r < a) return 1;
            if (l >= a && r <= b)
            {
                // if (!it[id]) cerr << l << " " << r << "\n";
                return (it[id] ? 1 : 0);
            }
            int i = id << 1, m = (l + r) >> 1;
            layd (id);
            return (qu (a, b, i, l, m) & qu (a, b, i ^ 1, m + 1, r));
        }
};

int x[mn], y[mn], vy[mn];
Z v[mn];

void enter()
{
    int u, n;
    read (u); read (n);
    for (int i = 0; i <= u; ++ i)
    {
        read (x[i]); read (y[i]);
    }
    int inf = 0, sup = 2 * (int)(1e9), sol = - 1;
    IT<int> it (2 * u, 1);
    inf = sup = 31;
    while (inf <= sup)
    {
        it.clear();
        int cv = 0, cvy = 0, mid = (inf + sup) >> 1; 
        for (int i = u; i >= 0; -- i)
        {
            int d = (i == u ? n : mid);
            long long X1 = 0ll + x[i] + y[i] - d;
            long long X2 = 0ll + x[i] + y[i] + d + 1;
            long long Y1 = 0ll + y[i] - x[i] - d;
            long long Y2 = 0ll + y[i] - x[i] + d - 1;
            if (i != u)
            {
                if (X1 >= v[1].x) continue;
                if (X2 < v[0].x) continue;
                if (Y1 > vy[1]) continue;
                if (Y2 < vy[0]) continue;
            }
            v[cv ++] = {X1, Y1, Y2, (i == u ? 0 : 1)}; 
            v[cv ++] = {X2, Y1, Y2, (i == u ? 0 : - 1)};
            vy[cvy ++] = Y1;
            vy[cvy ++] = Y2;
        }
        sort (v, v + cv);
        vy[cvy ++] = vy[0] + 1;
        vy[cvy ++] = vy[1] - 1;
        sort (vy, vy + cvy);
        cvy = (unique (vy, vy + cvy) - vy);
        bool res = 1;
        bool ok = 0;
        int y1, y2, x;
        int cn = 0;
        for (int i = 0; i < cv; ++ i)
        {
            // bool O = (v[i].y1 <= 115 && v[i].y2 >= 115);
            // if (O)
            // cout << v[i].y1 << " " << v[i].y2 << " " << "\n";
            v[i].y1 = lower_bound(vy, vy + cvy, v[i].y1) - vy + 1;
            v[i].y2 = lower_bound(vy, vy + cvy, v[i].y2) - vy + 1;
            cout << v[i].x << " " << v[i].y1 << " " << v[i].y2 << " " << v[i].id << "\n";
                // cn += v[i].id;  
            int d = abs ((0ll + x - v[i].x) % 2);
            if (!v[i].id)
            {
                ok ^= 1;
                x = v[i].x;
                y1 = v[i].y1, y2 = v[i].y2;
                if (!ok) break;
            }
            else 
            it.ud (v[i].y1, v[i].y2, v[i].id);
            if (ok && (i == cv - 1 || v[i].x != v[i + 1].x))
            if (!it.qu (y1 + d, y2 - d))
            {
                cerr << it.qu(461, 461) << "\n";
                cerr << i << " " <<d << "\n";
                res = 0;
                break;
            }
            // if (i == 919) break;
        }
        // cerr << cn;
        if (res)
        {
            sol = mid;
            sup = mid - 1;
        }
        else
        inf = mid + 1; 
    }
    cout << sol;
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