#include <bits/stdc++.h>

using namespace std;

bitset<160010> b[30];
int n;

int main()
{
    vector<int> v;
    v.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    unordered_map<int, int> mu;
    vector<int> e;
    for (int i = 0; i < n; ++ i)
    {
        string s;
        int k = 0, r = 0;
        cin >> s;
        bool ok = 0;
        vector<int> v;
        for (char c : s)
        {
            if (isdigit (c))
            {
                r = r * 10 + (c - '0');
                ok = 1;
            }
            else if (ok)
            {
                ok = 0;
                v.emplace_back(r);
                r = 0;
            }
            if (isalpha(c)) k = (c - 'A');
        }
        if (ok) v.emplace_back(r);
        for (int x = v[0]; x <= v[1]; x += v[2])
        {
            if (mu.find (x) == mu.end()) 
            {
                mu[x] = mu.size() - 1;
                e.emplace_back(x);
            }
            b[k][mu[x]] = 1;
        }
    }
    string s;
    cin >> s;
    s = '(' + s;
    s = s + ')';
    vector<char> v;
    vector<bitset<160010>> v1; 
    for (char c : s)
    {
        v.emplace_back (c);
        if (isalpha (c)) v1.emplace_back (b[c - 'A']);
        while (1)
        {
            bool ok = 0;
            if (v.back() == ')')
            {
                bitset<160010> r;
                while (1)
                {
                    ok = 1;
                    char c = v.back();
                    v.pop_back();
                    if (c == '(') break;
                    if (isalpha (c))
                    {
                        r |= v1.back();
                        v1.pop_back();
                    }
                }
                v.emplace_back('A');
                v1.emplace_back(r);
            }
            if (v.size() >= 3)
            if (v[v.size() - 2] == '*')
            if (isalpha (v.back()) && isalpha (v[v.size() - 3]))
            {
                ok = 1;
                v.pop_back();
                v.pop_back();
                v.pop_back();
                auto c = v1.back(); v1.pop_back();
                auto c1 = v1.back(); v1.pop_back();
                v1.emplace_back(c & c1);
                v.emplace_back('A');
            }   
            if (!ok) break;
        }
    }
    auto r = v1.back();
    vector<int> t;
    for (int i = 0; i < 160010; ++ i)
    if (r[i])
    t.emplace_back (e[i]);
    sort (t.begin(), t.end());
    cout << t.size() << "\n";
    for (int i : t)
    cout << i << " ";
}