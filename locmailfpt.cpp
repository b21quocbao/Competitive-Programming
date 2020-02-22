/*
Code by b21
Time: 16:10 Tue 17/12/2019
*/

#include <bits/stdc++.h>

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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("locmailfpt.inp"))
    {
        freopen("locmailfpt.inp", "r", stdin);
        freopen("locmailfpt.out", "w", stdout);
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

int ban = 0;

string ba[5] = {"Ban Chuyên môn", "Ban Đối Ngoại", "Ban Nội Dung", "Ban Truyền Thông", "Ban Văn Hoá"};

void enter()
{
    for (int i = 0; i < 98; ++ i)
    {
        string s;
        getline (cin, s);
        if (s == "") 
        {
            ++ ban;
        }
        else
        {
            for (int i = 0; i + 3 < s.size(); ++ i)
            if (s.substr (i, 4) == "he15")
            {
                s = s.substr(i, 8);
                break;
            }
            if (s.size() != 8) s = "";
        }
        if (s != "")
        cout << "Trượt" << "\n";
    }
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