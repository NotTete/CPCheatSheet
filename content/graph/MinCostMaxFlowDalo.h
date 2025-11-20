/**
 * Author: Stanford
 * Date: Unknown
 * Source: Stanford Notebook
 * Description: Min-cost max-flow.
 *  If costs can be negative, call setpi before maxflow, but note that negative cost cycles are not supported.
 *  To obtain the actual flow, look at positive values only.
 * Status: Tested on kattis:mincostmaxflow, stress-tested against another implementation
 * Time: $O(F E \log(V))$ where F is max flow. $O(VE)$ for setpi.
 */
#pragma once

// #include <bits/extc++.h> /// include-line, keep-include

int mf = 0, mc = 0;
while (true) {
  queue<int> q; vi dist(n, INF), parent(n, -1), f(n, INF), inq(n, false), cnt(n, 0);
  dist[s] = 0, parent[s] = s, f[s] = INF, inq[s] = true, q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop(); inq[u] = false;
    for (auto v : e[u]) {
      if (am[u][v] == 0) continue;
      int vw = dist[u]+amw[u][v];
      if (vw < dist[v]) {
        dist[v] = vw, parent[v] = u, f[v] = min(f[u], am[u][v]);
        if (cnt[v]++ == n) throw runtime_error("Negative cycle");
        if (!inq[v]) inq[v] = true, q.push(v);
      }
    }
  }
  if (dist[t] == INF) break;

  int u = parent[t], v = t;
  while (u != v)
    am[u][v] -= f[t], am[v][u] += f[t], v = u, u = parent[u];
  mf += f[t], mc += dist[t]*f[t];
}
