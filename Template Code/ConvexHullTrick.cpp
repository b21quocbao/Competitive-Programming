template<typename T>
class convexHullTrick {
    // 0: y = min (a * x + b)
    // 1: y = max (a * x + b)
    //Remember sort a in ascending order
    public:
    bool ma;
    convexHull(bool Ma) {
        ma = Ma;
    }
    struct Z
    {
        T a, b;
        double x;
        Z () {}
        Z (T aa, T bb, double xx) {
            a = aa;
            b = bb;
            x = xx;
        }
        bool operator < (const Z& a) const {
            return x < a.x;
        }
        bool operator > (const Z& a) const {
            return x > a.x;
        }
    };
    vector<Z> v;

    void ud (T a, T b) {
        double x = 1e18;
        if (ma) x = - x;
        while (v.size())
        {
            if (v.back().a == a) {
                v.back().b = min (v.back().b, b);
                return;
            }
            assert (v.back().a < a);
            x = 1. * (v.back().b - b) / (a - v.back().a);
            if ((x >= v.back().x && !ma) || (x <= v.back().x && ma)) v.pop_back();
            else break;    
        }
        v.emplace_back(a, b, x);
    }

    T fin (T x) {
        auto i = lower_bound(v.begin(), v.end(), Z (0, 0, x));
        if (!ma)
        i = lower_bound(v.begin(), v.end(), Z (0, 0, x), greater<Z>());
        -- i;
        return i->a * x + i->b;
    }
};