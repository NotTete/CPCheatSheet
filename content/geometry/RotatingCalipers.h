/**
 * Author: N41h_dr3s (adapted from Bacherikov, chilli)
 * Date: 2025
 * License: CC0
 * Source: https://codeforces.com/blog/entry/48868
 * Description: Generic Rotating Calipers on a convex hull (CCW, no collinear/duplicate points).
 *   hullDiameter returns the pair of antipodal points at maximum distance.
 *   Replaces HullDiameter.h with eps-safe comparisons.
 * Time: O(n)
 * Status: stress-tested
 */
#pragma once

pair<vec2d, vec2d> hullDiameter(vector<vec2d> S) {
	int n = sz(S), j = n < 2 ? 0 : 1;
	uds best = 0;
	pair<vec2d, vec2d> res = {S[0], S[0]};
	rep(i, 0, j)
		for (;; j = (j + 1) % n) {
			uds d = dist2(S[i], S[j]);
			if (gt(d, best)) { best = d; res = {S[i], S[j]}; }
			// advance j while rotating the caliper increases cross product
			if (ge(cross(S[(j+1)%n] - S[j], S[(i+1)%n] - S[i]), 0)) break;
		}
	return res;
}
