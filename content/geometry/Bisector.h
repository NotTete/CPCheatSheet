/**
 * Author: N41h_dr3s
 * Description:
 * Date: 21/11/25 6:00 AM cabron
 */
#pragma once

bool bisector(line l1, line l2, bool interior, line &out) {
  if (cross(l1.v, l2.v) == 0) return false;
  int s = interior ? 1 : -1;
  out = {l2.v/l2.v.len() + l1.v/l1.v.len()*s,
       l2.c/l2.v.len() + l1.c/l1.v.len()*s};
  return true;
}
