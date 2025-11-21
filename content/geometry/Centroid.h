/**
 * Author: N41h_dr3s
 * Description:
 * Date: 21/11/25 6:00 AM cabron
 */
#pragma once

vec2d centroid(vector<vec2d> &p) {
    int n = p.size(); vec2d c(0, 0);
    double sum = 0;
    for (int i = 0; i < n; i++) sum += cross(p[i], p[(i + 1) % n]);
    double scale = 3.0 * sum;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        c = c + (p[i] + p[j]) * cross(p[i], p[j]);
    }
    return c / scale;
}
