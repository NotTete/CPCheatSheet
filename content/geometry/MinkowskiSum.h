/**
 * Author: N41h_dr3s
 * Date: 2025
 * License: CC0
 * Description: Minkowski sum of two convex polygons (CCW, no collinear points).
 *   The result is a convex polygon with at most n+m vertices.
 * Time: O(n + m)
 */
#pragma once

vector<vec2d> minkowskiSum(vector<vec2d> P, vector<vec2d> Q) {
	// Reorder each polygon to start at its bottom-left point
	auto reorder = [](vector<vec2d>& v) {
		int idx = 0;
		for (int i = 1; i < sz(v); i++)
			if (lt(v[i].y, v[idx].y) || (eq(v[i].y, v[idx].y) && lt(v[i].x, v[idx].x)))
				idx = i;
		rotate(v.begin(), v.begin() + idx, v.end());
	};
	reorder(P); reorder(Q);
	int n = sz(P), m = sz(Q), i = 0, j = 0;
	vector<vec2d> res;
	while (i < n || j < m) {
		res.push_back(P[i%n] + Q[j%m]);
		vec2d ep = P[(i+1)%n] - P[i%n];
		vec2d eq = Q[(j+1)%m] - Q[j%m];
		uds c = cross(ep, eq);
		if      (j >= m || (i < n && gt(c, 0))) i++;
		else if (i >= n || (j < m && lt(c, 0))) j++;
		else { i++; j++; }
	}
	return res;
}
