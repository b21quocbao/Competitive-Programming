class Manarcher
{
    public:
    string S;
    vector<int> f;
    Manarcher (string s)
    {
        S.resize (2 * (int)s.size() + 1, '.');
        for (int i = 1; i < S.size(); i += 2)
        S[i] = s[i >> 1];
        f.resize(S.size() + 5);
    }
    int Sol()
    {
        int l, r = - 1, sol = 0;
        for (int i = 0; i < S.size(); ++ i)
        {
            if (i >= r)
            while (S[i + f[i]] == S[i - f[i]]) ++ f[i];
            else
            {
                f[i] = min (r - i, f[l + r - i]) + 1;
                while (S[i + f[i]] == S[i - f[i]]) ++ f[i];
            }
            -- f[i];
            if (i + f[i] > r) l = i - f[i], r = i + f[i];
            sol = max (sol, f[i]);
        }
        return sol;
    }
};