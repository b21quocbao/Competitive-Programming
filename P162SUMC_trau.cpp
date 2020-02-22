#include <bits/stdc++.h>

#define fn1 ""

using namespace std;

const int mn = 1 * int(1e3) + 10;
const int mod = 1 * int(1e9) + 7;
const int mm = 1 * int(1e5) + 10;

int tt, ntest = 1;
int n, m;
long long f[mn][mn];
string s;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

template <typename T> inline T read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
inline void write(T a)
{
    int i = 0;
    char S[20];
    if (a == 0) {putchar('0'); return;}
    while(a > 0)
    {
        S[i++] = a % 10 + '0';
        a /= 10;
    }
    --i;
    while(i >= 0) putchar(S[i--]);
}

void enter()
{
    cin >> n >> m;
    cin >> s;
}

bool is_palin (string s)
{
    string s1 = s;
    reverse(s.begin(), s.end());
    bool ok = false;
    for (int i = 0; i < s.size() - 1; ++ i)
	if (s[i] != s[i + 1]) ok = true;
    return (s1 == s && ok);
}

void solve()
{
	if (m == 1)
	{
		cout << 0;
		exit(0);
	}
	long long sol = 0;
	set<string> mu;
	for (int i = 0; i < s.size(); ++ i)
	{
		string s1 = s.substr (0, i) + s.substr(i + 1, s.size() + 2);
        for (int j = 0; j < s.size(); ++ j)
		for (int k = 0; k < m; ++ k)
		{
			auto it = s1.insert (s1.begin() + j, (char)('a' + k));
			if (s1 != s)
            {
                // if (mu.find (s1) != mu.end())
                // cerr << s1 << "\n";
                // else 
                // cerr << s1 << "**\n";
                mu.insert (s1);
            }
            s1.erase (it);
		}
	}
	cout << mu.size();
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

