/**
 * Author: Dalopir
 * Date: 2026-03-14
 * Description: Fully configurable lazy dynamic segment tree [l, r].
 * Use with a bump allocator for better performance.
 * Time: O(\log N).
 * Status: stress-tested a bit, cses PolynomialQueries.
 */
#pragma once

using T = int; using Lazy = int;
const T id = -INF, NO_SET = INF; const Lazy lzid = 0;
T f(T l, T r, int l_sz, int r_sz) { return max(l, r); }
T frep(T v, int sz) { return v; } // f(v, v, v...)
T lz_apply(T v, Lazy lz, int sz) { return v+lz; }
Lazy lz_add(Lazy a, Lazy b, int sz) { return a+b; }
pair<Lazy, Lazy> lz_prop(Lazy lz, int l_sz, int r_sz)
{ return {lz, lz}; } // Propagation [left, right]
struct segment {
  segment *L = 0, *R = 0; int l, r, m, sz;
  T v = id, vset = NO_SET; Lazy lz = lzid;
  segment(int l, int r)
    : l(l), r(r), m(l+(r-l)/2), sz(r-l+1) {}
  segment(vector<T> &x, int l, int r) : segment(l, r) {
    if (l == r) v = x[l];
    else L = new segment(x, l, m),
         R = new segment(x, m+1, r),
         v = f(L->v, R->v, L->sz, R->sz); }
  segment(vector<T> &x) : segment(x, 0, x.size()-1) {}
  T query(int ql, int qr) {
    if (r < ql || qr < l) return id;
    if (ql <= l && r <= qr) return v;
    return push(), f(L->query(ql, qr),
                     R->query(ql, qr), L->sz, R->sz);
  }
  void set(int ql, int qr, T x) {
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr)
      v = frep(x, sz), vset = x, lz = lzid;
    else push(), L->set(ql, qr, x), R->set(ql, qr, x),
         v = f(L->v, R->v, L->sz, R->sz);
  }
  void apply(int ql, int qr, Lazy x) {
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr)
      v = lz_apply(v, x, sz), lz = lz_add(lz, x, sz);
    else {
#define seg_sz(l, r) max(0ll, min(qr, r)-max(ql, l)+1)
      int ln = seg_sz(l, m), rn = seg_sz(m+1, r);
      auto [l, r] = lz_prop(x, ln, rn);
      push(), L->apply(ql, qr, l), R->apply(ql, qr, r),
      v = f(L->v, R->v, L->sz, R->sz);
    }
  }
  void push() {
    if (L == NULL)
      L = new segment(l, m), R = new segment(m+1, r);
    if (vset != NO_SET)
      L->set(l, r, vset), R->set(l, r, vset);
    auto [lz_l, lz_r] = lz_prop(lz, L->sz, R->sz);
    L->apply(l, r, lz_l), R->apply(l, r, lz_r);
    vset = NO_SET, lz = lzid;
  }
};
