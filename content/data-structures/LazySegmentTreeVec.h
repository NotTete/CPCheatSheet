/**
 * Author: Dalopir
 * Date: 2025-11-20
 * Description: SegmentTree with lazy propagation
 * Time: O(1)
 */
#pragma once

using T = int;
const T fid = 0;
T f(T a, T b) { return a+b; }
T frep(T a, int cnt) { return a*cnt; }
const T gid = 0;
T g(T a, T b) { return b == 0 ? a : 1-a; }
// d(g(a, b, ...), x, c): Distribute g over f
// Ex: max(a+x, b+x, ...) = max(a, b, ...)+x
// Ex: sum(a+x, b+x, ...) = sum(a, b, ...)+x*c
T d(T v, T x, int cnt) { return x == 0 ? v : cnt-v; }
struct segment_tree {
    int n; vector<T> st, lz, lzs;

    void build(int i, int l, int r, const vector<T> &v) {
        if (l == r) { st[i] = v[l]; return; }
        int m = (l+r)/2;
        build(2*i, l, m, v), build(2*i+1, m+1, r, v);
        st[i] = f(st[2*i], st[2*i+1]);
    }
    segment_tree(const vector<T> &v) : n(v.size()), st(4*n), lz(4*n, gid), lzs(4*n, INF) { build(1, 0, n-1, v); }

    void _set(int i, int l, int r, T x) { st[i] = frep(x, r-l+1), lzs[i] = x, lz[i] = gid; }
    void _apply(int i, int l, int r, T x) { st[i] = d(st[i], x, r-l+1), lz[i] = g(lz[i], x); }
    inline void push(int i, int l, int r) {
        int m = (l+r)/2;
        if (lzs[i] != INF) _set(2*i, l, m, lzs[i]), _set(2*i+1, m+1, r, lzs[i]);
        _apply(2*i, l, m, lz[i]), _apply(2*i+1, m+1, r, lz[i]);
        lzs[i] = INF, lz[i] = gid;
    }
    T query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return st[i];
        if (r < ql || qr < l) return fid;
        int m = (l+r)/2; push(i, l, r);
        return f(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
    }
    void set(int i, int l, int r, int ql, int qr, T x) {
        if (ql <= l && r <= qr) { _set(i, l, r, x); return; }
        if (r < ql || qr < l) return;
        int m = (l+r)/2; push(i, l, r);
        set(2*i, l, m, ql, qr, x), set(2*i+1, m+1, r, ql, qr, x);
        st[i] = f(st[2*i], st[2*i+1]);
    }
    void apply(int i, int l, int r, int ql, int qr, T x) {
        if (ql <= l && r <= qr) { _apply(i, l, r, x); return; }
        if (r < ql || qr < l) return;
        int m = (l+r)/2; push(i, l, r);
        apply(2*i, l, m, ql, qr, x), apply(2*i+1, m+1, r, ql, qr, x);
        st[i] = f(st[2*i], st[2*i+1]);
    }

    T query(int l, int r) { return query(1, 0, n-1, l, r); }
    void set(int l, int r, T x) { set(1, 0, n-1, l, r, x); }
    void apply(int l, int r, T x) { apply(1, 0, n-1, l, r, x); }
    T get(int i) { return query(i, i); }
    void apply(int i, T x) { apply(i, i, x); }
    void set(int i, T x) { set(i, i, x); }
};
