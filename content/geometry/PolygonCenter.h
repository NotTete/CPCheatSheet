/**
 * Author: Ulf Lundstrom
 * Date: 2009-04-08
 * License: CC0
 * Source:
 * Description: Returns the centroid (center of mass) of a polygon.
 * Time: O(n)
 * Status: Tested
 */
#pragma once

#include "Point.h"

vec2d polygonCenter(const vector<vec2d>& v) {
	vec2d res; uds A = 0;
	for (int i = 0, j = sz(v) - 1; i < sz(v); j = i++) {
		uds c = cross(v[j], v[i]);
		res = res + (v[i] + v[j]) * c;
		A += c;
	}
	return res / A / 3;
}
