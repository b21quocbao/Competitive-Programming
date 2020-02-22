#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1 * (int)(1e5) + 10;

template <typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

int n, a[N], x[N], b[N];

main()
{
    read (n);
    for (int i = 2; i <= n; i += 2)
    {
        read (x[i]);
        bool ok = 0;
        for (int j = trunc (sqrt (x[i])); j >= 1; -- j)
        if (x[i] % j == 0)
        if (((j + (x[i] / j)) % 2) == 0) 
        {
            a[i] = (x[i] / j + j) / 2;
            b[i] = (x[i] / j - j) / 2;
            if (b[i] <= a[i - 2]) continue;
            ok = 1;
            break;
        }
        if (!ok)
        {
            cout << "No";
            return 0;
        }
    }
    for (int i = 1; i <= n; ++ i)
    {
        if (i & 1)
        {
            x[i] = b[i + 1] * b[i + 1] - a[i - 1] * a[i - 1];
        }
        if (x[i] <= 0 || x[i] > (long long)(1e13))
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++ i)
    cout << x[i] << " ";
}