/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source:
 * Description:\\
\begin{minipage}{75mm}
 Returns a vector with the vertices of a polygon with everything to the left of the line going from s to e cut away.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-6mm}
\includegraphics[width=\textwidth]{content/geometry/PolygonCut}
\vspace{-6mm}
\end{minipage}
 * Usage:
 * 	vector<vec2d> p = ...;
 * 	p = polygonCut(p, {0,0}, {1,0});
 * Status: tested but not extensively
 */
#pragma once

#include "Point.h"

vector<vec2d> polygonCut(const vector<vec2d>& poly, vec2d s, vec2d e) {
	vector<vec2d> res;
	rep(i,0,sz(poly)) {
		vec2d cur = poly[i], prev = i ? poly[i-1] : poly.back();
		uds a = cross(e-s, cur-s), b = cross(e-s, prev-s);
		if ((a < 0) != (b < 0))
			res.push_back(cur + (prev - cur) * (a / (a - b)));
		if (a < 0)
			res.push_back(cur);
	}
	return res;
}
