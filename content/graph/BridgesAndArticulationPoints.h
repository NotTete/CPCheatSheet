/**
 * Author: Emil Lenngren, Simon Lindholm
 * Date: 2011-11-29
 * License: CC0
 * Source: folklore
 * Description: Bridges and Articulation Points
 * Usage: Bridges and Articulation Points
 * Time: O(n+m)
 * Status: stress-tested
 */
#pragma once

vi parent, tin, low; int dfst;
void dfs(int u) {
  low[u] = tin[u] = dfst++;
  int cut = false, children = 0;
  for (auto v : e[u]) {
    if (parent[v] == -1) {
      parent[v] = u, children++;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (tin[u] <= low[v]) cut = true;
      if (tin[u] <  low[v])
        cout << u << " " << v << " Cut Edge\n";
    }else if (v != parent[u])
      low[u] = min(low[u], tin[v]);
  }
  if (parent[u] == u) cut = children > 1;
  if (cut) cout << u << " Cut Vertex\n";
}
tin.assign(n, -1), low.assign(n, -1);
parent.assign(n, -1), dfst = 0;
for (int u = 0; u < n; u++)
  if (parent[u] == -1) parent[u] = u, dfs(u);
