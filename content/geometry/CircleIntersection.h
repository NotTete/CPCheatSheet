/**
 * Author: Simon Lindholm
 * Date: 2015-09-01
 * License: CC0
 * Description: Computes the pair of points at which two circles intersect.
 * Returns false in case of no intersection.
 * Status: stress-tested
 */
#pragma once

int circleLine(vec2d o, double r, line l, pair<vec2d,vec2d> &out) {
  double h2 = r*r - dist2(o,l);
  if (ge(h2, 0)) {
    vec2d p = proj(o,l);
    vec2d h = l.v * sqrt(max(0., h2)) / l.v.len();
    out = {p-h, p+h};
  }
  return 1 + sign(h2);
}
int circleCircle(vec2d o1, double r1, vec2d o2, double r2, pair<vec2d,vec2d> &out) {
  vec2d d = o2-o1; double d2 = d.len2();
  if (eq(d2, 0)) { assert(!eq(r1, r2)); return 0; }
  double pd = (d2 + r1*r1 - r2*r2)/2;
  double h2 = r1*r1 - pd*pd/d2;
  if (ge(h2, 0)) {
    vec2d p = o1 + d*pd/d2, h = d.perp() * sqrt(max(0., h2/d2));
    out = {p+h, p-h};
  }
  return 1 + sign(h2);
}
