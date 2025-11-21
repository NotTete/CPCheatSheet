/**
 * Author: Andrew He, chilli
 * Date: 2019-05-07
 * License: CC0
 * Source: folklore
 * Description: Computes the minimum circle that encloses a set of points.
 * Time: expected O(n)
 * Status: stress-tested
 */
#pragma once

// given n points, find the minimum enclosing circle of the points
// expected O(n)
pair<vec2d, double> minimum_enclosing_circle(vector<vec2d> &p) {
  random_shuffle(p.begin(), p.end());
  int n = p.size();
  // circle c(p[0], 0);
  pair<vec2d, uds> c = {p[0],0};
  for (int i = 1; i < n; i++) {
    if (sign(dist(c.first, p[i]) - c.second) > 0) {
      // c = circle(p[i], 0);
      c = {p[i], 0};
      for (int j = 0; j < i; j++) {
        if (sign(dist(c.first, p[j]) - c.second) > 0) {
          // c = circle((p[i] + p[j]) / 2, dist(p[i], p[j]) / 2);
          c = {(p[i] + p[j]) / 2, dist(p[i], p[j]) / 2};
          for (int k = 0; k < j; k++) {
            if (sign(dist(c.first, p[k]) - c.second) > 0) {
              // c = circle(p[i], p[j], p[k]);
              vec2d circum = circumCenter(p[i], p[j], p[k]);
              c = {circum, dist(p[i], circum)};
            }
          }
        }
      }
    }
  }
  return c;
}
