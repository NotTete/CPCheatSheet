/**
 * Author: Ulf Lundstrom
 * Date: 2009-03-21
 * License: CC0
 * Source: tinyKACTL
 * Description: Returns twice the signed area of a polygon.
 *  Clockwise enumeration gives negative area. Watch out for overflow if using int as T!
 * Status: Stress-tested and tested on kattis:polygonarea
 */
#pragma once

uds areaPolygon(vector<vec2d> p) {
  uds area = 0.0;
  for (int i = 0, n = p.size(); i < n; i++) area += cross(p[i], p[(i+1)%n]);
  return abs(area) / 2.0;
}
