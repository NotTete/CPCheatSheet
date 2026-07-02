/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source: Basic math
 * Description: Signed distance from p to line through a,b (positive = left side).
 * Status: tested
 */
#pragma once

#include "Point.h"

double lineDist(const vec2d& a, const vec2d& b, const vec2d& p) {
	return cross(b-a, p-a) / (b-a).len();
}
