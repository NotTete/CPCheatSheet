/**
 * Author: Dalopir
 * Date: 2025-11-20
 * Description: Confio en Tete
 * Time: O()
 */
#pragma once

vector<int> de_bruijn(int n, int k) {
  int N = pow(k, n-1); vi ui(N, 0);
  vector<int> res; res.reserve(N*k+n-1);
  stack<pii> s; s.push({0, -1});
  while (!s.empty()) {
    auto& [u, i] = s.top();
    if (i != -1) res.push_back(i);
    i = ui[u]++;
    if (i < k) s.push({(u*k+i)%N, -1});
    else s.pop();
  };
  for (int i = 0; i < n-1; i++) res.push_back(0);
  reverse(res.begin(), res.end()); return res;
}
