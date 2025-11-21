/**
 * Author: Stjepan Glavina, chilli
 * Date: 2019-05-05
 * License: Unlicense
 * Source: https://github.com/stjepang/snippets/blob/master/convex_hull.cpp
 * Description:
\\\begin{minipage}{75mm}
Returns a vector of the points of the convex hull in counter-clockwise order.
Points on the edge of the hull between two other points are not considered part of the hull.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-6mm}
\includegraphics[width=\textwidth]{content/geometry/ConvexHull}
\vspace{-6mm}
\end{minipage}
 * Time: O(n \log n)
 * Status: stress-tested, tested with kattis:convexhull
*/
#pragma once

vector<vec2d> convex_hull(vector<vec2d> &p) {
  if (p.size() <= 1) return p;
  vector<vec2d> v = p, up, dn;
  sort(v.begin(), v.end());
  for (auto& p : v) {
    while (dn.size() > 1 && orientation(dn[dn.size() - 2], dn.back(), p) < 0)
      dn.pop_back();

    while (up.size() > 1 && orientation(up[up.size() - 2], up.back(), p) > 0)
      up.pop_back();
    up.push_back(p); dn.push_back(p);
  }
  v = dn;
  if (v.size() > 1) v.pop_back();
  reverse(up.begin(), up.end());
  up.pop_back();
  for (auto& p : up) v.push_back(p);
  if (v.size() == 2 && v[0] == v[1]) v.pop_back();
  return v;
}
