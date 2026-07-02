/**
 * Author: N41h_Dr3s
 * Date: 2025-4-1
 * License: CC0
 * Source: https://codeforces.com/blog/entry/72815
 * Description: Given $N$ points in the plane,
 * it sorts the points looking angle with center at o, reference direction u.
 * Time: O(N \log N)
 */
#pragma once
void polarSort(vector<vec2d> &v, vec2d o, vec2d u = {1, 0}) {
    sort(v.begin(), v.end(), [&](const vec2d &a, const vec2d &b) {
        vec2d oa = a-o, ob = b-o;
        // Store signs to avoid precision issues from large products
        int xa = sign(cross(u, oa)), xb = sign(cross(u, ob));
        if (xa == 0 && ge(dot(u, oa), 0)) return true;  // angle(oa,u) = 0
        if (xb == 0 && ge(dot(u, ob), 0)) return false; // angle(ob,u) = 0
        if (xa == xb) { // Same half-plane
            int xc = sign(cross(ob, oa));
            if (xc != 0) return xc > 0;
            return lt(oa.len2(), ob.len2());
        }
        return xa > 0;
    });
}
