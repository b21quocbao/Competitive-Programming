class ZFunc
{
    public:
    vector<int> z;
    ZFunc (string s)
    {
        z.resize(s.size() + 2);
        int r = 0, l = 0;
        for (int i = 1; i < s.size(); ++ i)
        {
            if (r < i)
            while (s[i + z[i]] == s[z[i]]) ++ z[i];
            else
            {
                z[i] = min (z[i - l], r - i + 1);
                while (s[i + z[i]] == s[z[i]]) ++ z[i];
            }
            if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
        }
    }
};