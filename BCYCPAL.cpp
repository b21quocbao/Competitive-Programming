#include <bits/stdc++.h>

#define fn "test"
#define fn1 "BCYCPAL"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n;

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

int manacher(string s) 
{
    string T;// Transform S to T
    for(int i=0;i<s.size();i++)
        T+="#"+s.substr(i,1);
    T.push_back('#');
    vector<int> P(T.size(),0); // Array to record longest palindrome
    int center=0,boundary=0,maxLen=0,resCenter=0;
    for(int i=1;i<T.size()-1;i++) {
        int iMirror=2*center-i; // calc mirror i = center-(i-center)
        P[i]=(boundary>i)?min(boundary-i,P[iMirror]):0; // shortcut
        while(i-1-P[i]>=0&&i+1+P[i]<=T.size()-1&&T[i+1+P[i]] == T[i-1-P[i]]) // Attempt to expand palindrome centered at i
            P[i]++;
        if(i+P[i]>boundary) { // update center and boundary
            center = i;
            boundary = i+P[i];
        }
        if(P[i]>maxLen && P[i] <= n) { // update result
            maxLen = P[i];
            resCenter = i;
        }    
        if (P[i] > n)
        {
            int r = P[i];
            if ((r - n) % 2 == 0) r = n; else r = n - 1;
            maxLen = max (maxLen, r);
        }
    }
    return maxLen;
}

void enter()
{
    string s;
    getline (cin, s);
    n = s.size();
    s += s;
    int sol = manacher(s);
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