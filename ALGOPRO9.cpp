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
bool ok[mn];
vector<int> pr;

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
  
// It returns false if n is composite and returns true if n 
// is probably prime.  k is an input parameter that determines 
// accuracy level. Higher value of k indicates more accuracy. 
// lehmer_pi(n) = number of primes <= n.

const int MAX = 2e6 + 5; //equals 2*sqrt(MAXN) in problem
const int M = 7;         //equals smallest x, st. product of first "x" primes > MAX

vector<int> lp, primes, pi;
int phi[MAX+1][M+1], sz[M+1];

void factor_sieve() {
    lp.resize(MAX);
    pi.resize(MAX);
    lp[1] = 1;
    pi[0] = pi[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.emplace_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= lp[i]; ++j) {
            int x = i * primes[j];
            if (x >= MAX) break;
            lp[x] = primes[j];
        }
        pi[i] = primes.size();
    }
}

void init() {
    factor_sieve();
    for(int i = 0; i <= MAX; ++i) {
        phi[i][0] = i;
    }
    sz[0] = 1;
    for(int i = 1; i <= M; ++i) {
        sz[i] = primes[i-1]*sz[i-1];
        for(int j = 1; j <= MAX; ++j) {
            phi[j][i] = phi[j][i-1] - phi[j/primes[i-1]][i-1]; 
        }
    }
}

int sqrt2(long long x) {
    long long r = sqrt(x - 0.1);
    while (r*r <= x) ++r;
    return r - 1;
}

int cbrt3(long long x) {
    long long r = cbrt(x - 0.1);
    while(r*r*r <= x) ++r;
    return r - 1;
}

long long getphi(long long x, int s)
 {
    if(s == 0)  return x;
    if(s <= M) {
        return phi[x%sz[s]][s] + (x/sz[s])*phi[sz[s]][s];
    }
    if(x <= primes[s-1]*primes[s-1]) {
        return pi[x] - s + 1;
    }
    if(x <= primes[s-1]*primes[s-1]*primes[s-1] && x < MAX) {
        int sx = pi[sqrt2(x)];
        long long ans = pi[x] - (sx+s-2)*(sx-s+1)/2;
        for(int i = s+1; i <= sx; ++i) {
            ans += pi[x/primes[i-1]]; 
        }
        return ans;
    }
    return getphi(x, s-1) - getphi(x/primes[s-1], s-1);
}

long long getpi(long long x) 
{
    if(x < MAX)   return pi[x];
    int cx = cbrt3(x), sx = sqrt2(x);
    long long ans = getphi(x, pi[cx]) + pi[cx] - 1;
    for(int i = pi[cx]+1, ed = pi[sx]; i <= ed; ++i) {
        ans -= getpi(x/primes[i-1-1]) - i + 1;
    }
    return ans;
}

long long lehmer_pi(long long x) 
{
    if(x < MAX)   return pi[x];
    int a = (int)lehmer_pi(sqrt2(sqrt2(x)));
    int b = (int)lehmer_pi(sqrt2(x));
    int c = (int)lehmer_pi(cbrt3(x));
    long long sum = getphi(x, a) + (long long)(b + a - 2) * (b - a + 1) / 2;
    for (int i = a + 1; i <= b; i++) {
        long long w = x / primes[i-1];
        sum -= lehmer_pi(w);
        if (i > c) continue;
        long long lim = lehmer_pi(sqrt2(w));
        for (int j = i; j <= lim; j++) { 
            sum -= lehmer_pi(w / primes[j-1]) - (j - 1); 
        }
    }
    return sum;
}

void enter()
{
    int l, r, sol = 0;
    cin >> l >> r;
    if (l == 1) ++ l;
    cout << lehmer_pi (r) - lehmer_pi(l - 1) << "\n";
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
    cin>>ntest;
    init();
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}