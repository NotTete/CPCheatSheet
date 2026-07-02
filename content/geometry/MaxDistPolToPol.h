/**
 * Author: N41h_dr3s
 * Description:
 * Date: 21/11/25 6:00 AM cabron
 */
#pragma once

double maximum_dist_from_polygon_to_polygon(vector<vec2d> &u, vector<vec2d> &v){ //O(n)
  int n = (int)u.size(), m = (int)v.size();
  uds ans = 0;
  if (n < 3 || m < 3) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) ans = max(ans, dist2(u[i], v[j]));
    return sqrt(max((uds)0, ans));
  }
  bool swapped = gt(u[0].x, v[0].x);
  if (swapped) swap(n, m), swap(u, v);
  int i = 0, j = 0, step = n + m + 10;
  while (step--) {
    if (ge(cross(u[(i + 1)%n] - u[i], v[(j + 1)%m] - v[j]), 0)) j = (j + 1) % m;
    else i = (i + 1) % n;
    ans = max(ans, dist2(u[i], v[j]));
  }
  if (swapped) swap(n, m), swap(u, v);
  return sqrt(max((uds)0, ans));
}
