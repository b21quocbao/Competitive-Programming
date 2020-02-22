class SuffixArray
{
    public:
    string s;
    int n;
    vector<int> id, idm, cn, pos, posm, lcp;
    SuffixArray (string S)
    {
        s = S;
        s.push_back('/');
        n = s.size();
        id.resize(n + 2);
        idm.resize(n + 2);
        cn.resize(max (n, 256) + 2);
        pos.resize(n + 2);
        posm.resize(n + 2);
        lcp.resize(n + 2);
    }
    int mo (int k)
    {
        if (k >= n) k -= n;
        if (k < 0) k += n;
        return k;
    }
    void process()
    {
        for (int i = 0; i < n; ++ i)
        {
            ++ cn[pos[i] = (int)s[i]];
            id[i] = idm[i] = i;
        }
        for (int i = 1; i < 256; ++ i)
        cn[i] += cn[i - 1];
        for (int k = 0;; !k ? ++ k : k <<= 1)
        {
            for (int i = n - 1; i >= 0; -- i)
            id[-- cn[pos[idm[i]]]] = idm[i];
            int r = 0;
            cn[0] = 0;
            int K = (!k ? k + 1 : k << 1);
            for (int i = 0; i < n; ++ i)
            {
                if (i && (pos[id[i]] != pos[id[i - 1]] || pos[mo (id[i] + k)] != pos[mo (id[i - 1] + k)])) 
                {
                    cn[r + 1] = cn[r];
                    ++ r;
                }
                posm[id[i]] = r;
                ++ cn[r];
                idm[i] = mo (id[i] - K);
            }
            pos = posm;
            if (r == n - 1) break;
        }
        for (int i = 0, r = 0; i < n - 1; ++ i)
        if (pos[i] != n - 1)
        {
            if (r) -- r;
            while (s[i + r] == s[id[pos[i] + 1] + r]) 
            ++ r;
            lcp[pos[i]] = r;
        }
        -- n;
        for (int i = 0; i < n; ++ i)
        {
            id[i] = id[i + 1];
            lcp[i] = lcp[i + 1];
        }
        s.pop_back();
    }
};