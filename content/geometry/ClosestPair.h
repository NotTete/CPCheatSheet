/**
 * Author: Simon Lindholm
 * Date: 2019-04-17
 * License: CC0
 * Source: https://codeforces.com/blog/entry/58747
 * Description: Finds the closest pair of points.
 * Time: O(n \log n)
 * Status: stress-tested
 */
#pragma once

#include "Point.h"

pair<vec2d, vec2d> closest(vector<vec2d> v) {
	assert(sz(v) > 1);
	// Exact comparator by x then y for the sweep-line set
	auto cmp = [](const vec2d& a, const vec2d& b) {
		return a.x != b.x ? a.x < b.x : a.y < b.y;
	};
	set<vec2d, decltype(cmp)> S(cmp);
	sort(all(v), [](vec2d a, vec2d b) {
		return a.y < b.y || (a.y == b.y && a.x < b.x);
	});
	pair<uds, pair<vec2d, vec2d>> ret{1e18, {vec2d(), vec2d()}};
	int j = 0;
	for (vec2d p : v) {
		uds dx = 1 + sqrt(max((uds)0, ret.first));
		vec2d d{dx, 0};
		while (v[j].y <= p.y - dx) S.erase(v[j++]);
		auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);
		for (; lo != hi; ++lo)
			ret = min(ret, {dist2(*lo, p), {*lo, p}});
		S.insert(p);
	}
	return ret.second;
}
