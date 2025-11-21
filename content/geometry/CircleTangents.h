/**
 * Author: Victor Lecomte, chilli
 * Date: 2019-10-31
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf
 * Description: Finds the external tangents of two circles, or internal if r2 is negated.
 * Can return 0, 1, or 2 tangents -- 0 if one circle contains the other (or overlaps it, in the internal case, or if the circles are the same);
 * 1 if the circles are tangent to each other (in which case .first = .second and the tangent line is perpendicular to the line between the centers).
 * .first and .second give the tangency points at circle 1 and 2 respectively.
 * To find the tangents of a circle with a point set r2 to 0.
 * Status: tested
 */
#pragma once

int tangents(vec2d o1, double r1, vec2d o2, double r2, bool inner, vector<pair<vec2d,vec2d>> &out) {
  if (inner) r2 = -r2;
  vec2d d = o2-o1;
  double dr = r1-r2, d2 = (d.len2()), h2 = d2-dr*dr;
  if (eq(d2, 0) || lt(h2, 0)) {div0(h2); return 0;}
  for (double sign : {-1,1}) {
    vec2d v = (d*dr + (d.perp())*sqrt(h2)*sign)/d2;
    out.push_back({o1 + v*r1, o2 + v*r2});
  }
  return 1 + (gt(h2, 0));
}
