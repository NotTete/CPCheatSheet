/**
 * Author: N41h_dr3s
 * Description:
 * Date: 21/11/25 6:00 AM cabron
 */
#pragma once

// true if P at least as high as A 
bool above(vec2d a, vec2d p) {return ge(p.y, a.y);}
// check if [PQ] crosses ray from A
bool crossesRay(vec2d a, vec2d p, vec2d q) {
  return gt((above(a,q) - above(a,p)) * orient(a,p,q), 0);
}
// if strict, returns false when A is on the boundary
bool inPolygon(vector<vec2d> p, vec2d a, bool strict = true) {
  int numCrossings = 0;
  for (int i = 0, n = p.size(); i < n; i++) {
    segment s(p[i], p[(i+1)%n]);
    if (onSegment(s, a)) return !strict;
    numCrossings += crossesRay(a, p[i], p[(i+1)%n]);
  }
  return numCrossings & 1; // inside if odd number of crossings
}
