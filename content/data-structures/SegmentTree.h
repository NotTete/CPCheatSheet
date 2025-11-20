/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right.
 * Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

using T = int;
const T id = 0;
T f(T a, T b) { return a+b; }
struct segment_tree {
  int n; vector<T> st;
  segment_tree(int n) : n(n), st(2*n, id) {}
  T query(int l, int r) { // query [l, r)
    T rl = id, rr = id;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l%2 == 1) rl = f(rl, st[l++]);
      if (r%2 == 1) rr = f(st[--r], rr);
    }
    return f(rl, rr);
  }
  void set(int i, T x) {
    for (st[i += n] = x; i /= 2;)
      st[i] = f(st[i*2], st[i*2+1]);
  }
};
