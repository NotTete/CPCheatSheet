/**
 * Author: Dalopir
 * Date: 2025-11-20
 * Description: Dynamic connectivity
 * Time: O(tlog^2n)
 */
#pragma once

using E = pair<int, int>; // DSU
int T, t = 0; VV<E> st;
void _add(E e) { join(e.first, e.second); }
void _remove(E e) { rollback(); }
void add_edge(E v, int l, int r) {
  for (l += T, r += T; l <= r; l /= 2, r /= 2) {
    if (l%2 == 1) st[l].push_back(v), l++;
    if (r%2 == 0) st[r].push_back(v), r--;
  }
}
void _add_all(int t) { for (auto e : st[t]) _add(e); }
void _remove_all(int t) { for (auto e : st[t]) _remove(e); }
void set(int i) {
  int b = 1<<log2(i += T);
  while ((t&b) == (i&b)) b /= 2;
  for (int m = b; m; m /= 2) _remove_all(t), t /= 2;
  for (; b; b /= 2) _add_all(t = i&b ? 2*t+1 : 2*t);
}
void next() { set(t-T+1); }
T = 1<<(log2(t-1)+1), st.resize(2*T), rt.assign(n, -1);
