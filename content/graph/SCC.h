/**
 * Author: Lukas Polacek
 * Date: 2009-10-28
 * License: CC0
 * Source: Czech graph algorithms book, by Demel. (Tarjan's algorithm)
 * Description: Finds strongly connected components in a
 * directed graph. If vertices $u, v$ belong to the same component,
 * we can reach $u$ from $v$ and vice versa.
 * Usage: scc(graph, [\&](vi\& v) { ... }) visits all components
 * in reverse topological order. comp[i] holds the component
 * index of a node (a component only has edges to components with
 * lower index). ncomps will contain the number of components.
 * Time: O(E + V)
 * Status: Bruteforce-tested for N <= 5
 */
#pragma once

vector<int> low, tin, sccst, scc;
int dfst = 0, scci = 0;
void dfs(int u) {
  low[u] = tin[u] = dfst++;
  sccst.push_back(u);
  for (auto v : e[u]) {
    if (tin[v] == -1) dfs(v);
    if (scc[v] == -1) low[u] = min(low[u], low[v]);
  }
  if (low[u] == tin[u]) {
    int v; do {
      scc[v = sccst.back()] = scci; sccst.pop_back();
    } while (v != u); scci++;
  }
}
