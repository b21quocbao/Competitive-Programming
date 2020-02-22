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
    // if (ifstream(fno
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
    srand (time(nullptr));
    
    if (n <= 2)
    {
        cout << "! ";
        cout << n << " ";
        for (int i = 1; i <= n; ++ i)
        cout << i << " ";
        cout << endl;
        return;
    }
    unordered_set<int> mu;
    for (int i = 1; i <= n; ++ i)
    mu.emplace(i);
    for (int tt = 0; tt < 4; ++ tt)
    {
        vector<int> v2;
        for (const int&i : mu)
        v2.emplace_back (i);
        int x = v2[rand() % (int)(v2.size())];
        mu.erase (x);
        int s1 = 0, s2 = 0;
        vector<int> v, v1;
        for (const int&i : mu)
        {
            char c1, c;
            cout << "? " << x << " " << i << endl;
            cin >> c >> c1;
            if (c1 == '+') 
            {
                ++ s1;
                v1.emplace_back (i);
            }
            else ++ s2;
            if (c == '+') 
            v.emplace_back(i); 
        }
        if (s1 >= s2)
        {
            v.emplace_back (x);
            cout << "! ";
            cout << v.size() << " ";
            for (const int& i : v)
            cout << i << " ";
            cout << endl;
            break;
        }
        else
        {
            for (int i : v1)
            mu.erase(i);
        }
    }
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