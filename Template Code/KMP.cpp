class Kmp
{
    public:
    vector<int> km;
    Kmp (string s)
    {
        km.resize(s.size() + 2);
        int r = 0;
        for (int i = 2; i < s.size(); ++ i)
        {
            while (r && s[r + 1] != s[i]) r = km[r];
            if (s[r + 1] == s[i]) ++ r;
            km[i] = r;
        }
    } 
};