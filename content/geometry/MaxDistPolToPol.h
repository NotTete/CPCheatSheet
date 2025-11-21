/**
 * Author: N41h_dr3s
 * Description:
 * Date: 21/11/25 6:00 AM cabron
 */
#pragma once

// ROTATING CALIPERS (no es el calipers pero bueno, algo es algo)
// maximum distance from a convex polygon to another convex polygon
double maximum_dist_from_polygon_to_polygon(vector<vec2d> &u, vector<vec2d> &v){ //O(n)
  int n = (int)u.size(), m = (int)v.size();
  uds ans = 0;
  if (n < 3 || m < 3) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) ans = max(ans, dist2(u[i], v[j]));
    }
    return sqrt(ans);
  }
  if (gt(u[0].x, v[0].x)) swap(n, m), swap(u, v);
  int i = 0, j = 0, step = n + m + 10;
  while (j + 1 < m && v[j].x < v[j + 1].x) j++ ;
  while (step--) {
    if (ge(cross(u[(i + 1)%n] - u[i], v[(j + 1)%m] - v[j]), 0)) j = (j + 1) % m; // CALIPER
    else i = (i + 1) % n;
    ans = max(ans, dist2(u[i], v[j]));
  }
  return sqrt(ans);
}
