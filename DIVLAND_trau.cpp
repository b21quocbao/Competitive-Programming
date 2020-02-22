    #include <bits/stdc++.h>
    #define int long long

    #define fn "test"
    #define fn1 "DIVLAND"

    using namespace std;

    const int mn = 1 * (int)(1e5) + 10;
    const int mod = 1 * (int)(1e9) + 7;
    const int mm = 1 * (int)(1e3) + 10;
    const int base = 1 * (int)(1e9);
    const bool aNs = 1;

    int tt, ntest = 1;
    int x[mn], y[mn], k[mn], vt[mn], id[mn];
    bool ok[mn];
    int Ok[1010][1010];

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
        int n, W, H;
        read (n); read (W); read (H);
        
        for (int i = 1; i <= n; ++ i)
        {
            read (x[i]); read (y[i]);
            k[i] = y[i];
            id[i] = i;
            vt[i] = i;
        }
        if (n % 2)
        {
            cout << - 1;
            return;
        }
        int cur = 0, sol = - 1, tt = 0;
        if (W <= 1000 && H <= 1000)
        {
            for (int i = 1; i <= n; ++ i)
            Ok[x[i]][y[i]] = 1;
            for (int i = 1; i <= W; ++ i)
            for (int j = 1; j <= H; ++ j)
            {
                Ok[i][j] += Ok[i][j - 1] + Ok[i - 1][j] - Ok[i - 1][j - 1];
                if (Ok[i][j] == n / 2)
                {
                    sol = max (sol, W * H - i * j);
                }
            }
            cout << sol;
            return;
        }
        sort (id + 1, id + n + 1, [](int i, int j)
            {
                return x[i] < x[j];
            });
        sort (k + 1, k + n + 1);
        for (int i = 1; i <= n; ++ i)
        {
            int j = id[i];
            int l = lower_bound(k + 1, k + n + 1, y[j]) - k;
            int r = vt[l];
            ok[vt[l]] = 1;
            ++ vt[l];
            if (i <= n / 2) 
            {
                cur = max (cur, r);
                ++ tt;
            }
            else if (r < cur) ++ tt; 
            if (tt > n / 2) 
            {
                for (int j = cur; j >= 1; -- j)
                {
                    if (ok[j] && k[j] != k[cur])
                    {
                        cur = j;
                        break;
                    }
                    if (ok[j]) -- tt;
                }
            }
            if (i >= n / 2 && (i == n || x[id[i]] != x[id[i + 1]]))
            {
                int r = x[id[i]] * k[cur];
                if (tt == n / 2)
                sol = max (sol, W * H - r);
            }
        }
        cout << sol;
    }

    void solve()
    {

    }

    void print_result()
    {

    }

    main()
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