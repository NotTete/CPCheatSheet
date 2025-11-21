/**
 * Author: Victor Lecomte, chilli
 * Date: 2019-05-05
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf
 * Description:
 * Status: stress-tested, and tested through half-plane tests
 */
#pragma once

#include "Point.h"

bool inter(line l1, line l2, vec2d &out) {
  uds d = cross(l1.v, l2.v);
  if (eq(d, 0)) return false; // Parallel or equivalent
  return out = (l2.v*l1.c - l1.v*l2.c)/d, true;
}
