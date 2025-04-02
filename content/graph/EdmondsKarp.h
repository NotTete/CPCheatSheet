/**
 * Author: Chen Xing
 * Date: 2009-10-13
 * License: CC0
 * Source: N/A
 * Description: Flow algorithm with guaranteed complexity $O(VE^2)$. To get edge flow values, compare
 * capacities before and after, and take the positive values only.
 * Status: stress-tested
 */
#pragma once

int r = 0;
while (true) {
  queue<int> q; vi par(n, -1), cost(n, INF);
  q.push(s), par[s] = s;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v : e[u]) {
      if (am[u][v] > 0 && par[v] == -1) {
        par[v] = u, cost[v] = min(cost[u], am[u][v]);
        if (v == t) break;
        q.push(v);
      }
    }
  }
  if (par[t] == -1) break;
  int c = t;
  while (par[c] != c) 
    am[par[c]][c] -= cost[t],
    am[c][par[c]] += cost[t], c = par[c];
  r += cost[t];
}
