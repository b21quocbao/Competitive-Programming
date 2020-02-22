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

string sol[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

bool lh (int d, int m, int y, int d_, int m_, int y_)
{
    if (y != y_) return (y > y_);
    if (m != m_) return (m > m_);
    return (d > d_);
}

int d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};     

void tru (int& thu, int& day, int& month, int& year)
{
    if (thu == 0) thu = 6;
    else -- thu;
    if (day == 1) 
    {
        if (month == 1)
        {
            -- year;
            month = 12;
        }
        else
        -- month;
        if (((year % 400 == 0) || (year % 4 == 0 && year % 100)) && month == 2)
        day = 29;
        else
        day = d[month];
    }
    else -- day;
}

void cong (int& thu, int& day, int& month, int& year)
{
    if (thu == 6) thu = 0;
    else ++ thu;
    if (day >= d[month] && !(day == 28 && ((year % 400 == 0) || (year % 4 == 0 && year % 100))))
    {
        day = 1;
        if (month == 12) 
        {
            month = 1;
            ++ year;
        }
        else ++ month;
    }
    else ++ day;
}

void enter()
{
    int day = 11, month = 6, year = 2015, day_, month_, year_, thu = 3;
    read (day_); read (month_); read (year_);
    while (!(day == day_ && month == month_ && year == year_))
    {
        if (lh (day, month, year, day_, month_, year_))
        tru (thu, day, month, year); 
        else 
        cong (thu, day, month, year);
    }
    cout << sol[thu];
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