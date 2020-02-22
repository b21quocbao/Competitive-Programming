template <typename T>
class BIT 
{
    public:
    const T minT = 0;
    T MAX (const T& a, const T& b)
    {
        return a + b;
    }
    vector<T> bi;
    BIT (int n)
    {
        bi.resize(n + 2);
    }
    void udl (int u, T w)
    {
        for (; u < bi.size(); u += u & - u)
        bi[u] = MAX (bi[u], w);
    }
    int qun (int u)
    {
        T s = minT;
        for (; u >= 1; u -= u & - u)
        s = MAX (s, bi[u]);
        return s;
    }
    void udn (int u, T w)
    {
        for (; u >= 1; u -= u & - u)
        bi[u] = MAX (bi[u], w);
    }
    int qul (int u)
    {
        T s = minT;
        for (; u < bi.size(); u += u & - u)
        s = MAX (s, bi[u]);
        return s;
    }
};