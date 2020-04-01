#define ll long long

const int N = 1e5 + 10;

int a[N];

struct seg {
    int lft, rgh;
    ll val, tag;
} tree[N << 2];

inline int lc(int node) { return node << 1; }
inline int rc(int node) { return node << 1 | 1; }

inline void pushup(int node) {
    tree[node].val = tree[lc(node)].val + tree[rc(node)].val;
}

inline void pushdown(int node) {
    ll &v = tree[node].tag;
    if (v) {
        tree[lc(node)].tag += v;
        tree[rc(node)].tag += v;
        tree[lc(node)].val += (tree[lc(node)].rgh - tree[lc(node)].lft + 1) * v;
        tree[rc(node)].val += (tree[rc(node)].rgh - tree[rc(node)].lft + 1) * v;
        v = 0;
    }
}

void build(int node, int lft, int rgh) {
    tree[node].lft = lft;
    tree[node].rgh = rgh;
    tree[node].tag = 0;
    if (lft == rgh) {
        tree[node].val = a[lft];
        return;
    }
    int mid = (lft + rgh) >> 1;
    build(lc(node), lft, mid);
    build(rc(node), mid + 1, rgh);
    pushup(node);
}

void update(int node, int lft, int rgh, ll val) {
    if (lft <= tree[node].lft && tree[node].rgh <= rgh) {
        tree[node].val += val * (tree[node].rgh - tree[node].lft + 1);
        tree[node].tag += val;
        return;
    }
    pushdown(node);
    int mid = (tree[node].lft + tree[node].rgh) >> 1;
    if (lft <= mid) update(lc(node), lft, rgh, val);
    if (mid < rgh) update(rc(node), lft, rgh, val);
    pushup(node);
}

ll query(int node, int lft, int rgh) {
    if (lft <= tree[node].lft && tree[node].rgh <= rgh) 
        return tree[node].val;
    pushdown(node);
    int mid = (tree[node].lft + tree[node].rgh) >> 1;
    ll res = 0;
    if (lft <= mid) res = query(lc(node), lft, rgh);
    if (mid < rgh) res += query(rc(node), lft, rgh);
    return res;
}

build(1, 1, n); // 对数组a建加法线段树
update(1, l, r, v); // 对a[l]至a[r]包括两边的所有元素加上v
query(1, l, r); // 查询a[l]至a[r]的元素之和 
