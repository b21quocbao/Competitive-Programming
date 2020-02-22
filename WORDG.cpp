#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 2;
const int MAXM = 50 + 2;
const int MAXL = 10 + 2;

int n, m;
string pattern;
string a[MAXN];
int prefix[MAXN][MAXM], suffix[MAXN][MAXM];
bool ok[2][MAXN][MAXL][MAXN];

struct state {
    int side; //0 : left, 1 : right
    int str_id, residual;
    int l_match, r_match;
    int len;

    state() {}
    state(int _side, int _str_id, int _residual, int _l_match, int _r_match, int _len) {
        side = _side;
        str_id = _str_id; residual = _residual;
        l_match = _l_match; r_match = _r_match;
        len = _len;
    }
};
struct state_cmp {
    bool operator()(const state &a, const state &b) const {
        return a.len > b.len;
    }
};

int f[2][MAXN][MAXL][MAXM][MAXM];

void read() {
	cin >> pattern;
    m = pattern.size();    
    cin >> n;
    for(int i = 1; i <= n; ++i)
    cin >> a[i];
}

void init() {
    
    for(int i = 1; i <= n; ++i)
    for(int j = 0; j < m; ++j) 
	{
        int i1 = 0, cnt = 0;
        for(int k = j; k < m; ++k) 
        {
            while ((i1 < a[i].size()) && (a[i][i1] != pattern[k])) i1++;
            if (i1 == a[i].size()) break;
            cnt++; i1++;
        }
        prefix[i][j] = cnt;
        i1 = a[i].size() - 1; cnt = 0;
        for(int k = j; k >= 0; --k) 
        {
            while ((i1 >= 0) && (a[i][i1] != pattern[k])) i1--;
            if (i1 < 0) break;
            cnt++; i1--;
        }
        suffix[i][j] = cnt;
    }
    // for (int j = 0; j < m; ++ j)
    // for (int i = 1; i <= n; ++ i)
    // cout << i - 1 << " " << j << " " << prefix[i][j] << "\n";
    // for (int j = m - 1; j >= 0; -- j)
    // for (int i = 1; i <= n; ++ i)
    // cout << i - 1 << " " << j << " " << suffix[i][j] << "\n";
    for(int i = 1; i <= n; ++i)
    for(int r = 0; r <= a[i].size(); ++ r)
    for(int j = 1; j <= n; ++j) 
    {
        int l = min(r, (int)a[j].size());
        string s1 = a[i].substr(a[i].size() - r, l), s2 = a[j].substr(a[j].size() - l, l);
        reverse(s2.begin(), s2.end());
        ok[0][i][r][j] = (s1 == s2);
        s1 = a[i].substr(r - l, l); s2 = a[j].substr(0, l);
        reverse(s2.begin(), s2.end());
        ok[1][i][r][j] = (s1 == s2);
        // cout << i << " " << r << " " << j << " ";
        // cout << ok[0][i][r][j] << " " << ok[1][i][r][j] << "\n";
    }
}

char get_char(int side, int str_id, int residual) {
    char c = ' ';
    if (residual == 0) c = (side == 0) ? a[str_id].back() : a[str_id][0];
    else if (residual == a[str_id].size()) c = (side == 0) ? a[str_id][0] : a[str_id].back();
    else if (side == 0) {
        if (a[str_id][ a[str_id].size() - residual ] == a[str_id][ a[str_id].size() - residual - 1 ])
            c = a[str_id][ a[str_id].size() - residual ];
    }
    else {
        if (a[str_id][ residual - 1 ] == a[str_id][ residual ])
            c = a[str_id][ residual];
    }
    return c;
}

bool symmetry(string &s, int l, int r) {
    for(int i = l; i <= r; ++i)
        if (s[i] != s[r - (i - l)]) return false;
    return true;
}

bool check_state(int side, int str_id, int residual, int l_match, int r_match) {
    if (l_match + r_match < m) return false;
    if (residual == a[str_id].size()) 
    {
        if (!symmetry(a[str_id], 0, a[str_id].size() - 1)) return false;
    }
    else if (residual > 0) 
    {
        char c = get_char(side, str_id, residual);
        if (c == ' ') return false;
        if (side == 0) 
        {
            if (!symmetry(a[str_id], a[str_id].size() - residual, a[str_id].size() - 1)) return false;
        }
        else 
        {
            if (!symmetry(a[str_id], 0, residual - 1)) return false;
        }
    }
    return true;
}

void solve() {
    for (int j = 0; j < 2; ++ j)
    for (int i = 1; i <= n; ++ i)
    for (int k = 0; k <= a[i].size(); ++ k)
    cout << get_char (j, i, k) << "\n";
    priority_queue< state, vector<state>, state_cmp> q;
    for(int i = 1; i <= n; ++i) {
        f[0][i][ a[i].size() ][ prefix[i][0] ][0] = a[i].size();
        q.push(state(0, i, a[i].size(), prefix[i][0], 0, a[i].size()));
    }
    while (q.size()) {
        state top = q.top(); q.pop();
        int side = top.side, str_id = top.str_id, residual = top.residual, l_match = top.l_match, r_match = top.r_match;
        int len = top.len;
        if (f[side][str_id][residual][l_match][r_match] != len) continue;
        if (check_state(side, str_id, residual, l_match, r_match)) {
            cout << len << "\n";
            return;
        }
        char c = get_char(side, str_id, residual);
        if (c == ' ') continue;
        for(int i = 1; i <= n; ++i) {
            if ((!side) && ( (a[i].back() != c) || (!ok[side][str_id][residual][i]) ) ) continue;
            if ((side) && ( (a[i][0] != c) || (!ok[side][str_id][residual][i]) ) ) continue;
            int nxt_side = (a[i].size() <= residual) ? side : 1 - side;
            int nxt_str_id = (nxt_side == side) ? str_id : i;
            int nxt_residual = abs(residual - (int)(a[i].size()));
            int nxt_l_match = l_match + ((side) ? prefix[i][l_match] : 0);
            int nxt_r_match = r_match + ((!side) ? ((r_match < m) ? suffix[i][m - 1 - r_match] : 0) : 0);
            if ((f[nxt_side][nxt_str_id][nxt_residual][nxt_l_match][nxt_r_match] == 0) || (f[nxt_side][nxt_str_id][nxt_residual][nxt_l_match][nxt_r_match] > len + a[i].size()) ) {
                f[nxt_side][nxt_str_id][nxt_residual][nxt_l_match][nxt_r_match] = len + a[i].size();
                q.push(state(nxt_side, nxt_str_id, nxt_residual, nxt_l_match, nxt_r_match, len + a[i].size()));
            }
        }
    }
    cout << "-1\n";
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);

    read();
    init();
    solve();
}
