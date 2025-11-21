/**
 * Author: N41h_dr3s
 * Description:
 * Date: 21/11/25 6:00 AM cabron
 */
#pragma once

// returns the circle such that for all points w on the circumference of the circle
// dist(w, a) : dist(w, b) = rp : rq
// rp != rq
// https://en.wikipedia.org/wiki/Circles_of_Apollonius
pair<vec2d, double> apollonius(vec2d p, vec2d q, double rp, double rq){
  rq *= rq ;
  rp *= rp ;
  double a = rq - rp ;
  assert(sign(a));
  double g = rq * p.x - rp * q.x ; g /= a ;
  double h = rq * p.y - rp * q.y ; h /= a ;
  double c = rq * p.x * p.x - rp * q.x * q.x + rq * p.y * p.y - rp * q.y * q.y ;
  c /= a ;
  vec2d o(g, h);
  double r = g * g + h * h - c ;
  return {o,sqrt(r)};
}
