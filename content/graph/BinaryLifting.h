/**
 * Author: Johan Sannemo
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Calculate power of two jumps in a tree,
 * to support fast upward jumps and LCAs.
 * Assumes the root node points to itself.
 * Time: construction $O(N \log N)$, queries $O(\log N)$
 * Status: Tested at Petrozavodsk, also stress-tested via LCA.cpp
 */
#pragma once

int ln = log2(n)+2;
for (int u = 0; u < n; u++) up[u][0] = parent[u];
for (int i = 1; i < ln; i++)
    for (int u = 0; u < n; u++)
        up[u][i] = up[up[u][i-1]][i-1];

if (depth[u] < depth[v]) swap(u, v);
for (int i = ln-1; depth[u] > depth[v]; i--)
    if (depth[up[u][i]] >= depth[v])
        u = up[u][i];
if (u == v) return;
for (int i = ln-1; i >= 0; i--)
    if (up[u][i] != up[v][i])
        u = up[u][i], v = up[v][i];
u = up[u][0], v = up[v][0];
