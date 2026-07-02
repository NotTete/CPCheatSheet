/**
 * Author: chilli, Takanori MAEHARA
 * Date: 2019-10-31
 * License: CC0
 * Source: https://github.com/spaghetti-source/algorithm/blob/master/geometry/_geom.cc#L744
 * Description: Returns the area of the intersection of a circle with a
 * ccw polygon.
 * Time: O(n)
 * Status: Tested on GNYR 2019 Gerrymandering, stress-tested
 */
#pragma once

#define arg(p, q) atan2(cross(p, q), dot(p, q))
double circlePoly(vec2d c, double r, vector<vec2d> ps) {
	auto tri = [&](vec2d p, vec2d q) {
		auto r2 = r * r / 2;
		vec2d d = q - p;
		auto a = dot(d, p)/d.len2(), b = (p.len2()-r*r)/d.len2();
		auto det = a * a - b;
		if (det <= 0) return arg(p, q) * r2;
		auto s = max(0., -a-sqrt(max(0., det))), t = min(1., -a+sqrt(max(0., det)));
		if (t < 0 || 1 <= s) return arg(p, q) * r2;
		vec2d u = p + d * s, v = q + d * (t-1);
		return arg(p,u) * r2 + cross(u, v)/2 + arg(v,q) * r2;
	};
	auto sum = 0.0;
	rep(i,0,sz(ps))
		sum += tri(ps[i] - c, ps[(i + 1) % sz(ps)] - c);
	return sum;
}
