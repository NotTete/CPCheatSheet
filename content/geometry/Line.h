/**
 * Author: N41h_dr3s
 * Description:
 * Date: 21/11/25 6:00 AM cabron
 */
#pragma once

struct line {
  vec2d v; uds c; // Vector and offset (ax+by=c)
  line(vec2d v, uds c) : v(v), c(c) { div0(v.len2()); }
  line(uds a, uds b, uds c) : line({b, -a}, c) {}
  line(vec2d p, vec2d q) : line(q-p, cross(q-p, p)) {}

  line translate(vec2d t) { return {v, c+cross(v, t)}; }
  line shiftPerp(uds d) { return {v, c + d*v.len()}; }
  bool cmpProj(vec2d p, vec2d q) { return dot(v,p) < dot(v,q); }
};

uds side(vec2d p, line l) { return cross(l.v, p)-l.c; }
uds dist2(vec2d p, line l) { uds s = side(p, l); return s*s/l.v.len2(); }
double dist(vec2d p, line l) { return abs(side(p, l))/l.v.len(); }
vec2d proj(vec2d p, line l) { return p + l.v.perp()  *side(p, l)/l.v.len2(); }
vec2d refl(vec2d p, line l) { return p + l.v.perp()*2*side(p, l)/l.v.len2(); }
