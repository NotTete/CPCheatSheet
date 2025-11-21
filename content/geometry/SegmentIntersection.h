/**
 * Author: Victor Lecomte, chilli
 * Date: 2019-04-27
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf
 * Description:\\
\begin{minipage}{75mm}
If a unique intersection point between the line segments going from s1 to e1 and from s2 to e2 exists then it is returned.
If no intersection point exists an empty vector is returned.
If infinitely many exist a vector with 2 elements is returned, containing the endpoints of the common line segment.
The wrong position will be returned if P is Point<ll> and the intersection point does not have integer coordinates.
Products of three coordinates are used in intermediate steps so watch out for overflow if using int or long long.
\end{minipage}
\begin{minipage}{15mm}
\includegraphics[width=\textwidth]{content/geometry/SegmentIntersection}
\end{minipage}
 * Usage:
 * vector<P> inter = segInter(s1,e1,s2,e2);
 * if (sz(inter)==1)
 *   cout << "segments intersect at " << inter[0] << endl;
 * Status: stress-tested, tested on kattis:intersection
 */
#pragma once

bool properInter(segment s, segment t, vec2d &out) {
  uds oa = orient(t.a, t.b, s.a), ob = orient(t.a, t.b, s.b),
    oc = orient(s.a, s.b, t.a),od = orient(s.a, s.b, t.b);
  return lt(oa*ob, 0) && lt(oc*od, 0) ?
    out = (s.a*ob - s.b*oa) / (ob-oa), true : false;
}
set<vec2d> inter(segment s, segment t) {
  vec2d out; if (properInter(s, t, out)) return {out};
  set<vec2d> r;
  if (onSegment(t, s.a)) r.insert(s.a);
  if (onSegment(t, s.b)) r.insert(s.b);
  if (onSegment(s, t.a)) r.insert(t.a);
  if (onSegment(s, t.b)) r.insert(t.b);
  return r;
}
