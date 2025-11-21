/**
 * Author: Simon Lindholm
 * Date: 2015-09-01
 * License: CC0
 * Description: Computes the pair of points at which two circles intersect.
 * Returns false in case of no intersection.
 * Status: stress-tested
 */
#pragma once

//number of intersection points
int circleLine(vec2d o, double r, line l, pair<vec2d,vec2d> &out) {
  double h2 = r*r - dist2(o,l);
  if (ge(h2, 0)) { // the line touches the circle
    vec2d p = proj(o,l); // point P
    vec2d h = l.v*sqrt(h2)/l.v.len(); // vector parallel to l, of length h
    out = {p-h, p+h};
  }
  return 1 + sign(h2);
}
//number of intersection points
int circleCircle(vec2d o1, double r1, vec2d o2, double r2, pair<vec2d,vec2d> &out) {
  vec2d d=o2-o1; double d2=d.len2();
  if (d2 == 0) {assert(r1 != r2); return 0;} // concentric circles
  double pd = (d2 + r1*r1 - r2*r2)/2; // = |O_1P| * d
  double h2 = r1*r1 - pd*pd/d2; // = h^2
  if (h2 >= 0) {
    vec2d p = o1 + d*pd/d2, h = (d.perp())*sqrt(h2/d2);
    out = {p+h, p-h};
  }
  return 1 + sign(h2);
}
