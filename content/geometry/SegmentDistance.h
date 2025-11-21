/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source:
 * Description:\\
\begin{minipage}{75mm}
Returns the shortest distance between point p and the line segment from point s to e.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-10mm}
\includegraphics[width=\textwidth]{content/geometry/SegmentDistance}
\end{minipage}
 * Usage: 
 * 	Point<double> a, b(2,2), p(1,1);
 * 	bool onSegment = segDist(a,b,p) < 1e-10;
 * Status: tested
 */
#pragma once

double dist(segment s, vec2d p) {
  if (s.a == s.b) return (p-s.a).len();
  line l(s.a, s.b);
  return l.cmpProj(s.a, p) && l.cmpProj(p, s.b) ?
    dist(p, l) : min((p-s.a).len(), (p-s.b).len());
}
double dist(segment s, segment t) {
  vec2d i; if (properInter(s, t, i)) return 0;
  return min({dist(s, t.a), dist(s, t.b), dist(t, s.a), dist(t, s.b)});
}
