#include <bits/stdc++.h>


using namespace std;

const bool aNs = 0;

int tt, ntest = 1;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void read(int& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

void write (int a)
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
    cin >> h;
    cin >> m;
    if (m == 0)
    {
        cout << s[h] << " o' clock";
        return;
    }
    if (m == 30)
    {
        cout << "half past " << s[h];
        return;
    }
    if (m == 15)
    {
        cout << "quarter past " << s[h];
        return;
    }
    if (m == 45)
    {
        cout << "quarter to " << s[(h == 12 ? 1 : h + 1)];
        return;
    }
    d1[1] = ""
    cout << d1[m / 10] << d2[m % 10] << " " << "minute" << (m == 1 ? "" : "s") << " ";
    cout << (m < 30 ? "past" : "to") << " " << s[(m < 30 ? h : (h == 12 ? 1 : h + 1))];
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