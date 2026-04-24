#include <bits/stdc++.h>
// #include <bits/extc++.h>
 
// #pragma GCC optimize("Ofast,unroll-loops,O3")
// #pragma GCC target("avx,avx2,fma")
 
using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
 
// template <typename T>
// using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using ordered_multiset = tree <T, null_type, less_equal <T>, rb_tree_tag, tree_order_statistics_node_update>;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128_t;
 
istream& operator>>(istream& is, i128& x) {
    long long a;
    is >> a;
    x = (i128) a;
    return is;
}
ostream& operator<<(ostream& os, i128& x) {
    long long a = (long long) x;
    os << a;
    return os;
}
 
template <typename T>
ostream& operator<<(ostream& is, vector <T>& a) {
    for (uint i = 0; i < a.size(); ++i) is << a[i] << " ";
    return is;
}
 
#ifdef LOCAL
    # define DEBUG(x) cerr << "(" << __LINE__ << ") " << #x << ":  " << x << endl;
#else
    # define DEBUG(x)
#endif
 
const ll inf = 1e18 + 1e16;
const int inf_t = 1e9 + 7;
const ll mod = 1e9 + 7;
const ll MOD = 998244353;
 
#define int long long
 
struct SegmentTree {
    struct Node {
        int x = 0;
        int l = -1, r = -1;
 
        Node() = default;
    };
 
    int n;
    vector <Node> t;
    vector <int> roots;
 
    SegmentTree() = default;
    SegmentTree(int n): n(n) {
        t.push_back(Node());
        roots.push_back(0);
    }
 
    void build(int v, int l, int r) {
        if (r - l == 1) {
            return;
        }
 
        int m = (l + r) / 2;
        t[v].l = t.size();
        t.push_back(Node());
        t[v].r = t.size();
        t.push_back(Node());
        build(t[v].l, l, m);
        build(t[v].r, m, r);
    }
    void build() {
        build(0, 0, n);
    }
 
    int newNode(int v) {
        t.push_back(t[v]);
        return t.size() - 1;
    }
 
    void update(int v, int l, int r, int pos, int x) {
        if (r - l == 1) {
            t[v].x = x;
            return;
        }
 
        int m = (l + r) / 2;
        if (pos < m) {
            t[v].l = newNode(t[v].l);
            update(t[v].l, l, m, pos, x);
        } else {
            t[v].r = newNode(t[v].r);
            update(t[v].r, m, r, pos, x);
        }
 
        t[v].x = t[t[v].l].x + t[t[v].r].x;
    }
    void update(int pos, int x) {
        roots.push_back(newNode(roots.back()));
        update(roots.back(), 0, n, pos, x);
    }
 
    int get(int v, int l, int r, int lq, int rq) {
        if (lq <= l && r <= rq) return t[v].x;
        if (rq <= l || r <= lq) return 0;
 
        int m = (l + r) / 2;
        int a = get(t[v].l, l, m, lq, rq);
        int b = get(t[v].r, m, r, lq, rq);
 
        return a + b;
    }
    int get(int v, int l, int r) {
        return get(roots[v], 0, n, l, r);
    }
};
 
signed main() {
    #ifdef LOCAL
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
 
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) --a[i];
 
    vector <vector <int>> b(100000);
    vector <int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[i] = b[a[i]].size();
        b[a[i]].push_back(i);
    }
 
    SegmentTree t(n);
    t.build();
    vector <int> vers;
    for (int i = 0; i < n; ++i) {
        if (pos[i] >= k) {
            t.update(b[a[i]][pos[i] - k], 0);
        }
        t.update(i, 1);
        vers.push_back(t.roots.size() - 1);
    }
 
    int q;
    cin >> q;
    int last = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = (l + last) % n + 1;
        r = (r + last) % n + 1;
        if (l > r) swap(l, r);
        last = t.get(vers[r - 1], l - 1, r);
        cout << last << "\n";
    }
}