/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source:
 * Description:
 * Status: tested
 */
#pragma once

#include "Point.h"

int sideOf(vec2d s, vec2d e, vec2d p) { return sign(orient(s, e, p)); }

int sideOf(vec2d s, vec2d e, vec2d p, double eps) {
	uds a = cross(e-s, p-s);
	double l = (e-s).len() * eps;
	return (a > l) - (a < -l);
}
