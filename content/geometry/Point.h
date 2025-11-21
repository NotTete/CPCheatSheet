/**
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Class to handle points in the plane.
 * 	T can be e.g. double or long long. (Avoid int.)
 * Status: Works fine, used a lot
 */
#pragma once

typedef double uds;
const uds EPS = 1e-12;
int sign(uds x) { return x < -EPS ? -1 : x > EPS; }
bool eq(uds a, uds b) { return abs(a-b) <= EPS; }
bool lt(uds a, uds b) { return a < b && abs(a-b) > EPS; }
bool gt(uds a, uds b) { return a > b && abs(a-b) > EPS; }
bool le(uds a, uds b) { return !gt(a, b); }
bool ge(uds a, uds b) { return !lt(a, b); }
#define div0(v) assert(!eq(v, 0))

struct vec2d {
  uds x, y;
  vec2d(): x(0), y(0) {}
  vec2d(uds x, uds y): x(x), y(y) {}

  vec2d operator+ (vec2d o) const { return {x+o.x, y+o.y}; }
  vec2d operator- (vec2d o) const { return {x-o.x, y-o.y}; }
  vec2d operator* (  uds k) const { return {x*k  , y*k  }; }
  vec2d operator/ (  uds k) const { div0(k); return {x/k  , y/k  }; }
  bool operator==(const vec2d o) const { return eq(x, o.x) && eq(y, o.y); }
  bool operator!=(const vec2d o) const { return !(*this == o); }
  bool operator<(const vec2d o) const { return lt(x, o.x) || eq(x, o.x) && lt(y, o.y); }

  uds len2() const { return x*x + y*y; }
  double len() const { return sqrt(len2()); }

  vec2d perp() { return {y, -x}; }
};
uds dot(vec2d a, vec2d b) { return a.x*b.x + a.y*b.y; }
uds cross(vec2d a, vec2d b) { return a.x*b.y - a.y*b.x; }
vec2d proj(vec2d u, vec2d v) { return u*dot(u, v)/dot(u, u); }
uds orient(vec2d a, vec2d b, vec2d c) { return cross(b-a, c-a); }
uds dist2(vec2d a, vec2d b) {return dot(a-b,a-b);}
double dist(vec2d a, vec2d b) {return sqrt(dist2(a,b)); }
int orientation(vec2d a, vec2d b, vec2d c){return sign(orient(a,b,c));}
