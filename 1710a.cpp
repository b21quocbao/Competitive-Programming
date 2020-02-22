/*
Code by b21
Time: 20:12 Thu 17/10/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
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
   else if (ifstream("1710a.inp"))
    {
        freopen("1710a.inp", "r", stdin);
        freopen("1710a.out", "w", stdout);
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

char op[4] = {'+', '-', '*', '/'};

struct Bignum
{
    int x;
    Bignum operator + (const Bignum& a)
    {
        auto b = *this;
        if (x == INT_MIN || a.x == INT_MIN) 
        {
            b.x = INT_MIN;
            return b;
        }
        if (x != INT_MIN)
        b.x += a.x;
        return (b);
    }
    Bignum operator - (const Bignum& a)
    {
        auto b = *this;
        if (x == INT_MIN || a.x == INT_MIN) 
        {
            b.x = INT_MIN;
            return b;
        }
        if (x != INT_MIN)
        b.x -= a.x;
        return (b);
    }
    Bignum operator * (const Bignum& a)
    {
        auto b = *this;
        if (x == INT_MIN || a.x == INT_MIN) 
        {
            b.x = INT_MIN;
            return b;
        }
        if (x != INT_MIN)
        b.x *= a.x;
        return (b);
    }
    Bignum operator / (const Bignum& a)
    {
        auto b = *this;
        if (x == INT_MIN || a.x == INT_MIN) 
        {
            b.x = INT_MIN;
            return b;
        }
        if (b.x != INT_MIN)
        {
            if (a.x && b.x % a.x == 0)
            b.x /= a.x;
            else
            b.x = INT_MIN;
        }
        return (b);
    }
};

int id[4] = {0, 1, 2, 3};
int V[4];

void enter()
{
    int A, B, C, D;
    for (int i = 0; i < 4; ++ i)
    {
        cin >> V[i];
        id[i] = i;
    }
    if (V[0] == V[1] && V[0] == V[2] && V[0] == V[3] && V[0] == 0) exit (0);
    Bignum a, b, c, d;
    vector<Bignum> v;
    do
    {
        a.x = V[id[0]];
        b.x = V[id[1]];
        c.x = V[id[2]];
        d.x = V[id[3]];
        v.emplace_back(a + b + c + d);
    v.emplace_back((a + b) + (c + d));
    v.emplace_back((a + b) + c + d );
    v.emplace_back((a + b + c) + d );
    v.emplace_back((a + b + c) + d );
    v.emplace_back(a + (b + c) + d );
    v.emplace_back(a + (b + c + d) );
    v.emplace_back(a + b + (c + d) );
    v.emplace_back(a + b + c - d);
    v.emplace_back((a + b) + (c - d));
    v.emplace_back((a + b) + c - d );
    v.emplace_back((a + b + c) - d );
    v.emplace_back((a + b + c) - d );
    v.emplace_back(a + (b + c) - d );
    v.emplace_back(a + (b + c - d) );
    v.emplace_back(a + b + (c - d) );
    v.emplace_back(a + b + c * d);
    v.emplace_back((a + b) + (c * d));
    v.emplace_back((a + b) + c * d );
    v.emplace_back((a + b + c) * d );
    v.emplace_back((a + b + c) * d );
    v.emplace_back(a + (b + c) * d );
    v.emplace_back(a + (b + c * d) );
    v.emplace_back(a + b + (c * d) );
    v.emplace_back(a + b + c / d);
    v.emplace_back((a + b) + (c / d));
    v.emplace_back((a + b) + c / d );
    v.emplace_back((a + b + c) / d );
    v.emplace_back((a + b + c) / d );
    v.emplace_back(a + (b + c) / d );
    v.emplace_back(a + (b + c / d) );
    v.emplace_back(a + b + (c / d) );
    v.emplace_back(a + b - c + d);
    v.emplace_back((a + b) - (c + d));
    v.emplace_back((a + b) - c + d );
    v.emplace_back((a + b - c) + d );
    v.emplace_back((a + b - c) + d );
    v.emplace_back(a + (b - c) + d );
    v.emplace_back(a + (b - c + d) );
    v.emplace_back(a + b - (c + d) );
    v.emplace_back(a + b - c - d);
    v.emplace_back((a + b) - (c - d));
    v.emplace_back((a + b) - c - d );
    v.emplace_back((a + b - c) - d );
    v.emplace_back((a + b - c) - d );
    v.emplace_back(a + (b - c) - d );
    v.emplace_back(a + (b - c - d) );
    v.emplace_back(a + b - (c - d) );
    v.emplace_back(a + b - c * d);
    v.emplace_back((a + b) - (c * d));
    v.emplace_back((a + b) - c * d );
    v.emplace_back((a + b - c) * d );
    v.emplace_back((a + b - c) * d );
    v.emplace_back(a + (b - c) * d );
    v.emplace_back(a + (b - c * d) );
    v.emplace_back(a + b - (c * d) );
    v.emplace_back(a + b - c / d);
    v.emplace_back((a + b) - (c / d));
    v.emplace_back((a + b) - c / d );
    v.emplace_back((a + b - c) / d );
    v.emplace_back((a + b - c) / d );
    v.emplace_back(a + (b - c) / d );
    v.emplace_back(a + (b - c / d) );
    v.emplace_back(a + b - (c / d) );
    v.emplace_back(a + b * c + d);
    v.emplace_back((a + b) * (c + d));
    v.emplace_back((a + b) * c + d );
    v.emplace_back((a + b * c) + d );
    v.emplace_back((a + b * c) + d );
    v.emplace_back(a + (b * c) + d );
    v.emplace_back(a + (b * c + d) );
    v.emplace_back(a + b * (c + d) );
    v.emplace_back(a + b * c - d);
    v.emplace_back((a + b) * (c - d));
    v.emplace_back((a + b) * c - d );
    v.emplace_back((a + b * c) - d );
    v.emplace_back((a + b * c) - d );
    v.emplace_back(a + (b * c) - d );
    v.emplace_back(a + (b * c - d) );
    v.emplace_back(a + b * (c - d) );
    v.emplace_back(a + b * c * d);
    v.emplace_back((a + b) * (c * d));
    v.emplace_back((a + b) * c * d );
    v.emplace_back((a + b * c) * d );
    v.emplace_back((a + b * c) * d );
    v.emplace_back(a + (b * c) * d );
    v.emplace_back(a + (b * c * d) );
    v.emplace_back(a + b * (c * d) );
    v.emplace_back(a + b * c / d);
    v.emplace_back((a + b) * (c / d));
    v.emplace_back((a + b) * c / d );
    v.emplace_back((a + b * c) / d );
    v.emplace_back((a + b * c) / d );
    v.emplace_back(a + (b * c) / d );
    v.emplace_back(a + (b * c / d) );
    v.emplace_back(a + b * (c / d) );
    v.emplace_back(a + b / c + d);
    v.emplace_back((a + b) / (c + d));
    v.emplace_back((a + b) / c + d );
    v.emplace_back((a + b / c) + d );
    v.emplace_back((a + b / c) + d );
    v.emplace_back(a + (b / c) + d );
    v.emplace_back(a + (b / c + d) );
    v.emplace_back(a + b / (c + d) );
    v.emplace_back(a + b / c - d);
    v.emplace_back((a + b) / (c - d));
    v.emplace_back((a + b) / c - d );
    v.emplace_back((a + b / c) - d );
    v.emplace_back((a + b / c) - d );
    v.emplace_back(a + (b / c) - d );
    v.emplace_back(a + (b / c - d) );
    v.emplace_back(a + b / (c - d) );
    v.emplace_back(a + b / c * d);
    v.emplace_back((a + b) / (c * d));
    v.emplace_back((a + b) / c * d );
    v.emplace_back((a + b / c) * d );
    v.emplace_back((a + b / c) * d );
    v.emplace_back(a + (b / c) * d );
    v.emplace_back(a + (b / c * d) );
    v.emplace_back(a + b / (c * d) );
    v.emplace_back(a + b / c / d);
    v.emplace_back((a + b) / (c / d));
    v.emplace_back((a + b) / c / d );
    v.emplace_back((a + b / c) / d );
    v.emplace_back((a + b / c) / d );
    v.emplace_back(a + (b / c) / d );
    v.emplace_back(a + (b / c / d) );
    v.emplace_back(a + b / (c / d) );
    v.emplace_back(a - b + c + d);
    v.emplace_back((a - b) + (c + d));
    v.emplace_back((a - b) + c + d );
    v.emplace_back((a - b + c) + d );
    v.emplace_back((a - b + c) + d );
    v.emplace_back(a - (b + c) + d );
    v.emplace_back(a - (b + c + d) );
    v.emplace_back(a - b + (c + d) );
    v.emplace_back(a - b + c - d);
    v.emplace_back((a - b) + (c - d));
    v.emplace_back((a - b) + c - d );
    v.emplace_back((a - b + c) - d );
    v.emplace_back((a - b + c) - d );
    v.emplace_back(a - (b + c) - d );
    v.emplace_back(a - (b + c - d) );
    v.emplace_back(a - b + (c - d) );
    v.emplace_back(a - b + c * d);
    v.emplace_back((a - b) + (c * d));
    v.emplace_back((a - b) + c * d );
    v.emplace_back((a - b + c) * d );
    v.emplace_back((a - b + c) * d );
    v.emplace_back(a - (b + c) * d );
    v.emplace_back(a - (b + c * d) );
    v.emplace_back(a - b + (c * d) );
    v.emplace_back(a - b + c / d);
    v.emplace_back((a - b) + (c / d));
    v.emplace_back((a - b) + c / d );
    v.emplace_back((a - b + c) / d );
    v.emplace_back((a - b + c) / d );
    v.emplace_back(a - (b + c) / d );
    v.emplace_back(a - (b + c / d) );
    v.emplace_back(a - b + (c / d) );
    v.emplace_back(a - b - c + d);
    v.emplace_back((a - b) - (c + d));
    v.emplace_back((a - b) - c + d );
    v.emplace_back((a - b - c) + d );
    v.emplace_back((a - b - c) + d );
    v.emplace_back(a - (b - c) + d );
    v.emplace_back(a - (b - c + d) );
    v.emplace_back(a - b - (c + d) );
    v.emplace_back(a - b - c - d);
    v.emplace_back((a - b) - (c - d));
    v.emplace_back((a - b) - c - d );
    v.emplace_back((a - b - c) - d );
    v.emplace_back((a - b - c) - d );
    v.emplace_back(a - (b - c) - d );
    v.emplace_back(a - (b - c - d) );
    v.emplace_back(a - b - (c - d) );
    v.emplace_back(a - b - c * d);
    v.emplace_back((a - b) - (c * d));
    v.emplace_back((a - b) - c * d );
    v.emplace_back((a - b - c) * d );
    v.emplace_back((a - b - c) * d );
    v.emplace_back(a - (b - c) * d );
    v.emplace_back(a - (b - c * d) );
    v.emplace_back(a - b - (c * d) );
    v.emplace_back(a - b - c / d);
    v.emplace_back((a - b) - (c / d));
    v.emplace_back((a - b) - c / d );
    v.emplace_back((a - b - c) / d );
    v.emplace_back((a - b - c) / d );
    v.emplace_back(a - (b - c) / d );
    v.emplace_back(a - (b - c / d) );
    v.emplace_back(a - b - (c / d) );
    v.emplace_back(a - b * c + d);
    v.emplace_back((a - b) * (c + d));
    v.emplace_back((a - b) * c + d );
    v.emplace_back((a - b * c) + d );
    v.emplace_back((a - b * c) + d );
    v.emplace_back(a - (b * c) + d );
    v.emplace_back(a - (b * c + d) );
    v.emplace_back(a - b * (c + d) );
    v.emplace_back(a - b * c - d);
    v.emplace_back((a - b) * (c - d));
    v.emplace_back((a - b) * c - d );
    v.emplace_back((a - b * c) - d );
    v.emplace_back((a - b * c) - d );
    v.emplace_back(a - (b * c) - d );
    v.emplace_back(a - (b * c - d) );
    v.emplace_back(a - b * (c - d) );
    v.emplace_back(a - b * c * d);
    v.emplace_back((a - b) * (c * d));
    v.emplace_back((a - b) * c * d );
    v.emplace_back((a - b * c) * d );
    v.emplace_back((a - b * c) * d );
    v.emplace_back(a - (b * c) * d );
    v.emplace_back(a - (b * c * d) );
    v.emplace_back(a - b * (c * d) );
    v.emplace_back(a - b * c / d);
    v.emplace_back((a - b) * (c / d));
    v.emplace_back((a - b) * c / d );
    v.emplace_back((a - b * c) / d );
    v.emplace_back((a - b * c) / d );
    v.emplace_back(a - (b * c) / d );
    v.emplace_back(a - (b * c / d) );
    v.emplace_back(a - b * (c / d) );
    v.emplace_back(a - b / c + d);
    v.emplace_back((a - b) / (c + d));
    v.emplace_back((a - b) / c + d );
    v.emplace_back((a - b / c) + d );
    v.emplace_back((a - b / c) + d );
    v.emplace_back(a - (b / c) + d );
    v.emplace_back(a - (b / c + d) );
    v.emplace_back(a - b / (c + d) );
    v.emplace_back(a - b / c - d);
    v.emplace_back((a - b) / (c - d));
    v.emplace_back((a - b) / c - d );
    v.emplace_back((a - b / c) - d );
    v.emplace_back((a - b / c) - d );
    v.emplace_back(a - (b / c) - d );
    v.emplace_back(a - (b / c - d) );
    v.emplace_back(a - b / (c - d) );
    v.emplace_back(a - b / c * d);
    v.emplace_back((a - b) / (c * d));
    v.emplace_back((a - b) / c * d );
    v.emplace_back((a - b / c) * d );
    v.emplace_back((a - b / c) * d );
    v.emplace_back(a - (b / c) * d );
    v.emplace_back(a - (b / c * d) );
    v.emplace_back(a - b / (c * d) );
    v.emplace_back(a - b / c / d);
    v.emplace_back((a - b) / (c / d));
    v.emplace_back((a - b) / c / d );
    v.emplace_back((a - b / c) / d );
    v.emplace_back((a - b / c) / d );
    v.emplace_back(a - (b / c) / d );
    v.emplace_back(a - (b / c / d) );
    v.emplace_back(a - b / (c / d) );
    v.emplace_back(a * b + c + d);
    v.emplace_back((a * b) + (c + d));
    v.emplace_back((a * b) + c + d );
    v.emplace_back((a * b + c) + d );
    v.emplace_back((a * b + c) + d );
    v.emplace_back(a * (b + c) + d );
    v.emplace_back(a * (b + c + d) );
    v.emplace_back(a * b + (c + d) );
    v.emplace_back(a * b + c - d);
    v.emplace_back((a * b) + (c - d));
    v.emplace_back((a * b) + c - d );
    v.emplace_back((a * b + c) - d );
    v.emplace_back((a * b + c) - d );
    v.emplace_back(a * (b + c) - d );
    v.emplace_back(a * (b + c - d) );
    v.emplace_back(a * b + (c - d) );
    v.emplace_back(a * b + c * d);
    v.emplace_back((a * b) + (c * d));
    v.emplace_back((a * b) + c * d );
    v.emplace_back((a * b + c) * d );
    v.emplace_back((a * b + c) * d );
    v.emplace_back(a * (b + c) * d );
    v.emplace_back(a * (b + c * d) );
    v.emplace_back(a * b + (c * d) );
    v.emplace_back(a * b + c / d);
    v.emplace_back((a * b) + (c / d));
    v.emplace_back((a * b) + c / d );
    v.emplace_back((a * b + c) / d );
    v.emplace_back((a * b + c) / d );
    v.emplace_back(a * (b + c) / d );
    v.emplace_back(a * (b + c / d) );
    v.emplace_back(a * b + (c / d) );
    v.emplace_back(a * b - c + d);
    v.emplace_back((a * b) - (c + d));
    v.emplace_back((a * b) - c + d );
    v.emplace_back((a * b - c) + d );
    v.emplace_back((a * b - c) + d );
    v.emplace_back(a * (b - c) + d );
    v.emplace_back(a * (b - c + d) );
    v.emplace_back(a * b - (c + d) );
    v.emplace_back(a * b - c - d);
    v.emplace_back((a * b) - (c - d));
    v.emplace_back((a * b) - c - d );
    v.emplace_back((a * b - c) - d );
    v.emplace_back((a * b - c) - d );
    v.emplace_back(a * (b - c) - d );
    v.emplace_back(a * (b - c - d) );
    v.emplace_back(a * b - (c - d) );
    v.emplace_back(a * b - c * d);
    v.emplace_back((a * b) - (c * d));
    v.emplace_back((a * b) - c * d );
    v.emplace_back((a * b - c) * d );
    v.emplace_back((a * b - c) * d );
    v.emplace_back(a * (b - c) * d );
    v.emplace_back(a * (b - c * d) );
    v.emplace_back(a * b - (c * d) );
    v.emplace_back(a * b - c / d);
    v.emplace_back((a * b) - (c / d));
    v.emplace_back((a * b) - c / d );
    v.emplace_back((a * b - c) / d );
    v.emplace_back((a * b - c) / d );
    v.emplace_back(a * (b - c) / d );
    v.emplace_back(a * (b - c / d) );
    v.emplace_back(a * b - (c / d) );
    v.emplace_back(a * b * c + d);
    v.emplace_back((a * b) * (c + d));
    v.emplace_back((a * b) * c + d );
    v.emplace_back((a * b * c) + d );
    v.emplace_back((a * b * c) + d );
    v.emplace_back(a * (b * c) + d );
    v.emplace_back(a * (b * c + d) );
    v.emplace_back(a * b * (c + d) );
    v.emplace_back(a * b * c - d);
    v.emplace_back((a * b) * (c - d));
    v.emplace_back((a * b) * c - d );
    v.emplace_back((a * b * c) - d );
    v.emplace_back((a * b * c) - d );
    v.emplace_back(a * (b * c) - d );
    v.emplace_back(a * (b * c - d) );
    v.emplace_back(a * b * (c - d) );
    v.emplace_back(a * b * c * d);
    v.emplace_back((a * b) * (c * d));
    v.emplace_back((a * b) * c * d );
    v.emplace_back((a * b * c) * d );
    v.emplace_back((a * b * c) * d );
    v.emplace_back(a * (b * c) * d );
    v.emplace_back(a * (b * c * d) );
    v.emplace_back(a * b * (c * d) );
    v.emplace_back(a * b * c / d);
    v.emplace_back((a * b) * (c / d));
    v.emplace_back((a * b) * c / d );
    v.emplace_back((a * b * c) / d );
    v.emplace_back((a * b * c) / d );
    v.emplace_back(a * (b * c) / d );
    v.emplace_back(a * (b * c / d) );
    v.emplace_back(a * b * (c / d) );
    v.emplace_back(a * b / c + d);
    v.emplace_back((a * b) / (c + d));
    v.emplace_back((a * b) / c + d );
    v.emplace_back((a * b / c) + d );
    v.emplace_back((a * b / c) + d );
    v.emplace_back(a * (b / c) + d );
    v.emplace_back(a * (b / c + d) );
    v.emplace_back(a * b / (c + d) );
    v.emplace_back(a * b / c - d);
    v.emplace_back((a * b) / (c - d));
    v.emplace_back((a * b) / c - d );
    v.emplace_back((a * b / c) - d );
    v.emplace_back((a * b / c) - d );
    v.emplace_back(a * (b / c) - d );
    v.emplace_back(a * (b / c - d) );
    v.emplace_back(a * b / (c - d) );
    v.emplace_back(a * b / c * d);
    v.emplace_back((a * b) / (c * d));
    v.emplace_back((a * b) / c * d );
    v.emplace_back((a * b / c) * d );
    v.emplace_back((a * b / c) * d );
    v.emplace_back(a * (b / c) * d );
    v.emplace_back(a * (b / c * d) );
    v.emplace_back(a * b / (c * d) );
    v.emplace_back(a * b / c / d);
    v.emplace_back((a * b) / (c / d));
    v.emplace_back((a * b) / c / d );
    v.emplace_back((a * b / c) / d );
    v.emplace_back((a * b / c) / d );
    v.emplace_back(a * (b / c) / d );
    v.emplace_back(a * (b / c / d) );
    v.emplace_back(a * b / (c / d) );
    v.emplace_back(a / b + c + d);
    v.emplace_back((a / b) + (c + d));
    v.emplace_back((a / b) + c + d );
    v.emplace_back((a / b + c) + d );
    v.emplace_back((a / b + c) + d );
    v.emplace_back(a / (b + c) + d );
    v.emplace_back(a / (b + c + d) );
    v.emplace_back(a / b + (c + d) );
    v.emplace_back(a / b + c - d);
    v.emplace_back((a / b) + (c - d));
    v.emplace_back((a / b) + c - d );
    v.emplace_back((a / b + c) - d );
    v.emplace_back((a / b + c) - d );
    v.emplace_back(a / (b + c) - d );
    v.emplace_back(a / (b + c - d) );
    v.emplace_back(a / b + (c - d) );
    v.emplace_back(a / b + c * d);
    v.emplace_back((a / b) + (c * d));
    v.emplace_back((a / b) + c * d );
    v.emplace_back((a / b + c) * d );
    v.emplace_back((a / b + c) * d );
    v.emplace_back(a / (b + c) * d );
    v.emplace_back(a / (b + c * d) );
    v.emplace_back(a / b + (c * d) );
    v.emplace_back(a / b + c / d);
    v.emplace_back((a / b) + (c / d));
    v.emplace_back((a / b) + c / d );
    v.emplace_back((a / b + c) / d );
    v.emplace_back((a / b + c) / d );
    v.emplace_back(a / (b + c) / d );
    v.emplace_back(a / (b + c / d) );
    v.emplace_back(a / b + (c / d) );
    v.emplace_back(a / b - c + d);
    v.emplace_back((a / b) - (c + d));
    v.emplace_back((a / b) - c + d );
    v.emplace_back((a / b - c) + d );
    v.emplace_back((a / b - c) + d );
    v.emplace_back(a / (b - c) + d );
    v.emplace_back(a / (b - c + d) );
    v.emplace_back(a / b - (c + d) );
    v.emplace_back(a / b - c - d);
    v.emplace_back((a / b) - (c - d));
    v.emplace_back((a / b) - c - d );
    v.emplace_back((a / b - c) - d );
    v.emplace_back((a / b - c) - d );
    v.emplace_back(a / (b - c) - d );
    v.emplace_back(a / (b - c - d) );
    v.emplace_back(a / b - (c - d) );
    v.emplace_back(a / b - c * d);
    v.emplace_back((a / b) - (c * d));
    v.emplace_back((a / b) - c * d );
    v.emplace_back((a / b - c) * d );
    v.emplace_back((a / b - c) * d );
    v.emplace_back(a / (b - c) * d );
    v.emplace_back(a / (b - c * d) );
    v.emplace_back(a / b - (c * d) );
    v.emplace_back(a / b - c / d);
    v.emplace_back((a / b) - (c / d));
    v.emplace_back((a / b) - c / d );
    v.emplace_back((a / b - c) / d );
    v.emplace_back((a / b - c) / d );
    v.emplace_back(a / (b - c) / d );
    v.emplace_back(a / (b - c / d) );
    v.emplace_back(a / b - (c / d) );
    v.emplace_back(a / b * c + d);
    v.emplace_back((a / b) * (c + d));
    v.emplace_back((a / b) * c + d );
    v.emplace_back((a / b * c) + d );
    v.emplace_back((a / b * c) + d );
    v.emplace_back(a / (b * c) + d );
    v.emplace_back(a / (b * c + d) );
    v.emplace_back(a / b * (c + d) );
    v.emplace_back(a / b * c - d);
    v.emplace_back((a / b) * (c - d));
    v.emplace_back((a / b) * c - d );
    v.emplace_back((a / b * c) - d );
    v.emplace_back((a / b * c) - d );
    v.emplace_back(a / (b * c) - d );
    v.emplace_back(a / (b * c - d) );
    v.emplace_back(a / b * (c - d) );
    v.emplace_back(a / b * c * d);
    v.emplace_back((a / b) * (c * d));
    v.emplace_back((a / b) * c * d );
    v.emplace_back((a / b * c) * d );
    v.emplace_back((a / b * c) * d );
    v.emplace_back(a / (b * c) * d );
    v.emplace_back(a / (b * c * d) );
    v.emplace_back(a / b * (c * d) );
    v.emplace_back(a / b * c / d);
    v.emplace_back((a / b) * (c / d));
    v.emplace_back((a / b) * c / d );
    v.emplace_back((a / b * c) / d );
    v.emplace_back((a / b * c) / d );
    v.emplace_back(a / (b * c) / d );
    v.emplace_back(a / (b * c / d) );
    v.emplace_back(a / b * (c / d) );
    v.emplace_back(a / b / c + d);
    v.emplace_back((a / b) / (c + d));
    v.emplace_back((a / b) / c + d );
    v.emplace_back((a / b / c) + d );
    v.emplace_back((a / b / c) + d );
    v.emplace_back(a / (b / c) + d );
    v.emplace_back(a / (b / c + d) );
    v.emplace_back(a / b / (c + d) );
    v.emplace_back(a / b / c - d);
    v.emplace_back((a / b) / (c - d));
    v.emplace_back((a / b) / c - d );
    v.emplace_back((a / b / c) - d );
    v.emplace_back((a / b / c) - d );
    v.emplace_back(a / (b / c) - d );
    v.emplace_back(a / (b / c - d) );
    v.emplace_back(a / b / (c - d) );
    v.emplace_back(a / b / c * d);
    v.emplace_back((a / b) / (c * d));
    v.emplace_back((a / b) / c * d );
    v.emplace_back((a / b / c) * d );
    v.emplace_back((a / b / c) * d );
    v.emplace_back(a / (b / c) * d );
    v.emplace_back(a / (b / c * d) );
    v.emplace_back(a / b / (c * d) );
    v.emplace_back(a / b / c / d);
    v.emplace_back((a / b) / (c / d));
    v.emplace_back((a / b) / c / d );
    v.emplace_back((a / b / c) / d );
    v.emplace_back((a / b / c) / d );
    v.emplace_back(a / (b / c) / d );
    v.emplace_back(a / (b / c / d) );
    v.emplace_back(a / b / (c / d) );
    } while (next_permutation(id, id + 4));
    vector<int> g;
    for (auto i : v) if (i.x != INT_MIN)g.emplace_back(i.x);
    sort (g.begin(), g.end());
    g.resize(unique(g.begin(), g.end()) - g.begin());
    int I = 0, ma = 1, cn = 1;
    // cerr << g[0];
    for (int i = 1; i < g.size(); ++ i)
    {
        if (g[i] == g[i - 1] + 1) ++ cn;
        else cn = 1;
        if (cn >= ma)
        {
            ma = cn;
            I = i;
        }
    }
    cout << "Case " << tt << ": " << g[I - ma + 1] << " to " << g[I] << "\n";
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