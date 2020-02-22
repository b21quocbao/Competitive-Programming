template <class T>
class Dijkstra
{
    #define ii pair<T, int>
    public:
        int n;
        vector<int> tr;
        vector<T> d;
        vector<vector<ii> > e;
        priority_queue<ii, vector<ii>, greater<ii> > qu;
        void AddEdge (int u, int v, T c, bool Directed = 0)
        {
            e[u].emplace_back(c, v);
            if (!Directed)
            e[v].emplace_back(c, u);
        }
        
        void Init (int u)
        {
            while (qu.size()) qu.pop();
            qu.emplace (0, u);
            fill (d.begin(), d.end(), - 1);
            fill (tr.begin(), tr.end(), 0);
            d[u] = 0;
        }
        void process (int u, int v)
        {
            while (qu.size())
            {
                int x = qu.top().first, u = qu.top().second;
                qu.pop();
                if (x != d[u]) continue;
                if (u == v) return;
                for (auto v : e[u])
                if (d[v.second] == - 1 || d[v.second] > d[u] + v.first)
                {
                    tr[v.second] = u;
                    d[v.second] = d[u] + v.first;
                    qu.emplace (d[v.second], v.second);
                }
            }
        }

        Dijkstra (int N) : n (N)
        {
            tr.resize (n + 2);
            d.resize (n + 2);
            e.resize(n + 2);
        }

        int Sol(int u, int v)
        {
            Init(u);
            process(u, v);
            return d[v];
        }

        vector<int> Trace (int u, int v)
        {
            Init(u);
            process(u, v);  
            vector<int> V;
            while (v)
            {
                V.emplace_back(v);
                v = tr[v];
            }
            reverse (V.begin(), V.end());
            return V;
        }  
};