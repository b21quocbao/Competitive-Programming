class Hash
{
    public:
    vector<int> ha;
    vector<int> po;
    const int mod = (int)(1e9) + 7;
    Hash (string s, int hs = 31)
    {
        int n = s.size();
        po.resize(n + 1);
        ha.resize(n);
        for (int i = 0; i < n; ++ i)
        ha[i] = (1ll * (!i ? 0 : ha[i - 1]) * hs + s[i] - 'a') % mod;
        po[0] = 1;
        for (int i = 1; i <= n; ++ i)
        po[i] = (1ll * po[i - 1] * hs) % mod;
    }
    int GetHash (int i, int j)
    {
        int x = (ha[j] - 1ll * (!i ? 0 : ha[i - 1]) * po[j - i + 1]) % mod;
        return (x < 0 ? x + mod : x);
    }
    int HashValue ()
    {
        return ha.back();
    }
};

template<class T>
class HashTS
{
    public:
    vector<T> ha;
    vector<T> po;
    HashTS (string s, int hs = 31)
    {
        int n = s.size();
        ha.resize(n);
        po.resize(n + 1);
        for (int i = 0; i < n; ++ i)
        ha[i] = (!i ? 0 : ha[i - 1]) * hs + s[i] - 'a';
        po[0] = 1;
        for (int i = 1; i <= n; ++ i)
        po[i] = po[i - 1] * hs;
    }
    T GetHash (int i, int j)
    {
        return ha[j] - (!i ? 0 : ha[i - 1]) * po[j - i + 1];
    }
    T HashValue ()
    {
        return ha.back();
    }
};