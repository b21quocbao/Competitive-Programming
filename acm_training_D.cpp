/*
Code by b21
Time: 20:53 Sun 23/02/2020
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
   else if (ifstream("acm_training_D.inp"))
    {
        freopen("acm_training_D.inp", "r", stdin);
        freopen("acm_training_D.out", "w", stdout);
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

int Nid = 0;
int ok[10010][10010];

struct Z
{
    int n;
    Z* x;
    Z* y;
    int id;
    Z () {}
    Z (int N) {
        id = ++ Nid;
        n = N;
        x = NULL;
        y = NULL;
    }
    Z (int N, int ID) {
        id = ID;
        n = N;
        x = NULL;
        y = NULL;
    }
    Z (int N, Z* X, Z* Y) {
        id = ++ Nid;
        n = N;
        x = X;
        y = Y;
    }
};

void process (string s, vector<Z*>& v) {
    for (char c: s) {
        if (c == 'C') 
        {
            // Z k = *v.back();
            v.emplace_back(v.back());
        }
        if (c == 'D') 
        {
            if (v.size())
            v.pop_back();
        }
        if (c == 'L') {
            if (v.back()->x == NULL || v.back()->y == NULL) {
                v.clear();
                return;
            }
            v.back() = v.back()->x;
        }
        if (c == 'P') {
            auto k1 = v.back();
            v.pop_back();
            auto k2 = v.back();
            v.pop_back();
            v.emplace_back(new Z(0, k1, k2));
        }
        if (c == 'R') {
            if (v.back()->x == NULL || v.back()->y == NULL) {
                v.clear();
                return;
            }
            v.back() = v.back()->y;
        }
        if (c == 'S') {
            swap (v.back(), v[v.size() - 2]);
        }
        if (c == 'U') {
            auto k = v.back();
            v.pop_back();
            if (k->x == NULL || k->y == NULL) {
                v.clear();
                return;
            }
            v.emplace_back(k->y);
            v.emplace_back(k->x);
        }
    }
}

bool equa (Z* a, Z* b) {
    if (a->x == NULL && b->x != NULL) return false;
    if (a->x != NULL && b->x == NULL) return false;
    if (a->x == NULL)
    return a->n == b->n;
    if ((a->id < 10000 && b->id < 10000) && ok[a->id][b->id] != - 1) return ok[a->id][b->id];
    bool ok1 = equa(a->x, b->x);
    bool ok2 = equa(a->y, b->y);
    if (a->id < 10000 && b->id < 10000) ok[a->id][b->id] = (ok1 && ok2);
    return (ok1 && ok2);
}

void enter()
{
    string s1, s2;
    vector<Z*> v1, v2;
    memset (ok, - 1, sizeof (ok));
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 1; i <= max (s1.size(), s2.size()) + 1; ++ i)
    {
        v1.emplace_back(new Z(i, 10000));
        v2.emplace_back(new Z(i, 10000));
    }
    process (s1, v1);
    process (s2, v2);
    if (v1.size() == v2.size()) {
        for (int i = v1.size() - 1; i >= 0; -- i)
        {
            if (!equa(v1[i], v2[i])) {
                cout << "False";
                return;
            }
        }
        cout << "True";
    }
    else cout << "False";
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