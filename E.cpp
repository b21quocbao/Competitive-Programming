/*
Code by b21
Time: 18:43 Mon 24/02/2020
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 4 * (int)(1e4) + 10;
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
   else if (ifstream("E.inp"))
    {
        freopen("E.inp", "r", stdin);
        freopen("E.out", "w", stdout);
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

struct Z
{
    char c;
    vector<int> e, l;
    int t;
    Z () {
        c = ' ';
        t = - 1;
    }
};

int n;
string vtor;
vector<int> vand;
Z v[mn];
int In [mn], Out[mn];
map<char, int> p;
int h[mn];
int root;
int trIn[mn], trOut[mn];
int f[mn], f1[mn];

bool isal(char c) {
    return (isalpha(c) || c == '.');
}

bool isal1(char c) {
    return (isalpha(c) || c == '.' || c == ' ');

}

void oand(char c) {
    v[n].c = c;
    v[n].t = n;
    vand.emplace_back(n);
    ++ n;
}

void AddE (int x, int y) {
    v[x].e.emplace_back(y);
    v[y].l.emplace_back(x);
}

void process (char c) {
    if (c == '|') {
        int x = vand.back(); vand.pop_back(); AddE(n, x);
        int y = vand.back(); vand.pop_back(); AddE(n, y);
        vand.emplace_back(n++);
        v[n - 1].t = n;
        AddE(v[x].t, n);
        AddE(v[y].t, n);
        ++ n;
    } 
    if (c == '*') {
        int x = vand.back();
        if (x == v[x].t && v[x].c == ' ') return;
        
        if (isal(v[v[x].t].c)) {
            AddE(v[x].t, n);
            v[x].t = n;
            ++ n;
        }
        AddE(n, x);
        v[n].t = v[x].t;
        for (int y : v[x].l)
        AddE(y, v[x].t);
        AddE(v[x].t, x);
        vand.pop_back();
        vand.emplace_back(n ++);
    }
    if (c == '^') {
        int y = vand.back();
        vand.pop_back();
        int x = vand.back();
        vand.pop_back();
        AddE(v[x].t, y);
        v[x].t = v[y].t;
        vand.emplace_back(x);
    }
}



void otor (char c) {
    if (c == ')')
    {
        while (vtor.back() != '(')
        {
            process (vtor.back());
            vtor.pop_back();
        }
        vtor.pop_back();
        return;
    }
    if (c == '(') {
        vtor.push_back(c);
        return;
    }
    while (vtor.back() != '(' && p[vtor.back()] >= p[c]) {
        process(vtor.back());
        vtor.pop_back();
    }
    vtor.push_back(c);
}  


void CalH (int u) {
    for (int V : v[u].e)
    if (!h[V])
    {
        h[V] = h[u] + 1;
        CalH(V);
    }
}

void Filter (string& s) {
    string s1 = "";
    for (char c : s)
    if (isal(c) || c == '(' || c == ')' || c == '*' || c == '|')
    {
        if (c == ')' && s1.back() == '(') {
            s1.pop_back();
            s1.push_back(' ');
            continue;
        }
        if (s1.back() == '(' && (c == '*' || c == '|')) {
            s1.push_back(' ');
            s1.push_back(c);
            continue;
        }
        if (s1.back() == '*' && c == '*') continue;
        if (s1.back() == '|' && c == '*') continue;
        if (s1.back() == '|' && (c == ')' || c == '|')) {
            s1.push_back(' ');
            s1.push_back(c);
            continue;
        }
        s1.push_back(c);
    }
    s = s1;
}

void Filter1 (string& s) {
    string s1 = "";
    for (char c : s)
    if (isalpha(c))
    s1.push_back(c);
    s = s1;
}

int calIn(int u) {
    if (In[u] != - 1) return In[u];
    if (u == root) return In[u] = isal(v[u].c);
    for (int k : v[u].l)
    {
        int r = calIn(k) + isal(v[u].c);
        if (r >= In[u]) continue;
        In[u] = r;
        trIn[u] = k;
    }
    return In[u];
}

int calOut(int u) {
    if (Out[u] != - 1) return Out[u];
    if (u == v[root].t) return Out[u] = isal(v[u].c);
    for (int k : v[u].e)
    {
        int r = calOut(k) + isal(v[u].c);
        if (r >= In[u]) continue;
        Out[u] = r;
        trOut[u] = k;
    }
    return Out[u];
}

void Cal (int u) {
    
}


void enter()
{
    p['|'] = 1;
    p['^'] = 2;
    p['*'] = 3;
    string E, S;
    getline(cin, E);
    E = "(" + E + ')';
    Filter(E);
    E = "( " + E + ")";
    getline(cin, S);
    Filter1(S);
    S = '#' + S;
    char c1 = '1';
    for (int i = 0; i < E.size(); ++ i) {
        char c = E[i];
        if ((isal1(c1) && isal1(c)) || 
            (isal1(c1) && c == '(') ||
            (c1 == ')' && isal1(c)) ||
            (c1 == ')' && c == '(') ||
            (c1 == '*' && isal1(c)) ||
            (c1 == '*' && c == '('))
        otor('^');
        if (isal1(c))
        oand(c);
        else 
        otor(c);
        c1 = c;
    }
    root = vand.back();
    fill_n(In, n, - 1);
    fill_n(Out, n, - 1);
    vector<int> id1(n), id2(n);
    for (int i = 0; i < n; ++ i)
    {
        id1[i] = i;
        id2[i] = i;
        calIn(i);
        calOut(i);
    }
    vector<int> f(n), f1(n);
    sort (id1.begin(), id1.end(), [](int i, int j)
         {
             return In[i] < In[j];
         });
    sort (id2.begin(), id2.end(), [](int i, int j)
         {
             return Out[i] < Out[j];
         });
    for (int t = 0; t < min (1000, n); ++ t)
    {
        queue<int> qu;
        qu.emplace(id1[t]);
        while (qu.size()) {
            
        }
    }
    cout << "NO";
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