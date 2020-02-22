/*
Code by b21
Time: 09:16 Sun 13/10/2019
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
   else if (ifstream("VNPC19C.inp"))
    {
        freopen("VNPC19C.inp", "r", stdin);
        freopen("VNPC19C.out", "w", stdout);
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

int A[6];
double a, b, c, d;
vector<double> Result;

double h(double x)
    { return a*x*x*x + b*x*x + c*x + d; }
int sign(double x)
    { if (fabs(x)<=1e-9) return 0; return x>0 ? 1 : -1; }
void decide(double x)
    { Result.push_back(x); }

bool solve(double a, double b, double c, double &x1, double &x2) {
    if (sign(a)==0) {
        if (sign(b)==0) return false;
        x1=x2=-c/b; return true;
    }
    double d = b*b-4*a*c;
    if (sign(d)==0) {
        x1 = x2 = -b/(2*a);
        return true;
    } else if (sign(d)>0) {
        x1 = (-b-sqrt(d))/(2*a);
        x2 = (-b+sqrt(d))/(2*a);
        if (x1>x2) swap(x1, x2);
        return true;
    }
    return false;   
}

void search1(double ll, double rr) {
    if (isinf(ll)) {
        ll=rr-100;
        while (sign(h(ll))>0) ll-=(rr-ll);
    }
    if (isinf(rr)) {
        rr=ll+100;
        while (sign(h(rr))<0) rr+=(rr-ll);
    }
    //printf("search1(%Lg, %Lg)\n", ll, rr);
    if (sign(h(ll))==0) return decide(ll);
    if (sign(h(rr))==0) return decide(rr);
    if (sign(h(ll))>0 || sign(h(rr))<0) return;
   
    double mm=(ll+rr)/2;
    for (int i=1; i<=100; i++) {
        h(mm)>0 ? rr=mm : ll=mm;
        mm=(ll+rr)/2;
    }
    return decide(mm);
}

void search2(double ll, double rr) {
    //printf("search2(%g, %g)\n", ll, rr);
    if (sign(h(ll))==0) return decide(ll);
    if (sign(h(rr))==0) return decide(rr);
    if (sign(h(ll))<0 || sign(h(rr))>0) return;
   
    double mm=(ll+rr)/2;
    for (int i=1; i<=100; i++) {
        h(mm)<0 ? rr=mm : ll=mm;
        mm=(ll+rr)/2;
    }
    return decide(mm);
}

void enter()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cin >> a >> b >> c >> d;
        if (sign(a)==0) {
            double x1, x2;
            if (solve(b, c, d, x1, x2))
            { decide(x1); decide(x2); }
        } else {
            if (a<0) { a=-a, b=-b, c=-c, d=-d; }
            double x1, x2;
            if (solve(3*a, 2*b, c, x1, x2)) {
                search1(-1.0/0.0, x1);
                search2(x1, x2);
                search1(x2, +1.0/0.0);
            } else {
                search1(-1.0/0.0, 0);
                search1(0, +1.0/0.0);
            }
        }
        sort(Result.begin(), Result.end());
        Result.erase(unique(Result.begin(), Result.end()), Result.end());
        cout.precision(6);
        long long mi = LLONG_MAX;
        for (double x: Result)
        if (abs (x - round (x)) < 1e-8)
        mi = min (mi, (long long)(round (x)));
        cout << mi;
        Result.clear();
        return;
    }
    
    for (int i = 0; i <= n; ++ i)
    cin >> A[i];
    if (n == 1)
    {
        cout << - A[1] / A[0];
        return;
    }   
    if (n == 2)
    {
        int A1 = A[0], B = A[1], C = A[2];
        int d = B * B - 4 * A1 * C;
        cout << min ((- B - (int)(round (sqrt (d)))) / (2 * A1), (- B + (int)(round (sqrt (d)))) / (2 * A1));
        return;
    }
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

main()
{
    docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}