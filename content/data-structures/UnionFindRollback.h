/**
 * Author: Lukas Polacek, Simon Lindholm
 * Date: 2019-12-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure with undo.
 * If undo is not needed, skip st, time() and rollback().
 * Usage: int t = uf.time(); ...; uf.rollback(t);
 * Time: $O(\log(N))$
 * Status: tested as part of DirectedMST.h
 */
#pragma once


vi rt; vpii rb;
int root(int u) { return rt[u] < 0 ? u : r[u] = root(rt[u]); }
void join(int u, int v) {
    u = root(u), v = root(v);
    if (-rt[u] > -rt[v]) swap(u, v);
    if (u == v) return;
    rb.push_back({u, rt[u]});
    rt[v] += rt[u], rt[u] = v;
}
void rollback() { // Remove Path Compression
    auto [u, sz] = rb.back(); rb.pop_back();
    if (rt[u] < 0) return;
    rt[rt[u]] -= sz; rt[u] = sz;
}
