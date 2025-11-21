/**
 * Author: N41h_dr3s
 * Description:
 * Date: 21/11/25 6:00 AM cabron
 */
#pragma once

struct segment {
  vec2d a, b;
  segment(vec2d a, vec2d b) : a(a), b(b) {}
};
bool inDisk(segment s, vec2d p) { return dot(s.a-p, s.b-p) <= 0; }
bool onSegment(segment s, vec2d p) { return eq(orient(s.a, s.b, p), 0) && inDisk(s, p); }
