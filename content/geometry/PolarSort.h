/**
 * Author: N41h_Dr3s
 * Date: 2025-4-1
 * License: CC0
 * Source: https://codeforces.com/blog/entry/72815
 * Description: Given $N$ points in the plane, 
 * it sorts the points looking angle with center at (0,0)
 * Time: O(N \log N)
 */
#pragma once
#include<Point.h>
template <typename T>
void polarSort(vector<Point<T>> &v, Point<T> o, Point<T> u = {1, 0}) {
    sort(v.begin(), v.end(), [&](const Point<T> &a, const Point<T> &b) {
        Point<T> oa = a-o, ob = b-o;
        int xa = u.cross(oa), xb = u.cross(ob);
        if (xa == 0 && u.dot(oa) >= 0) return true; // angle(oa, u) = 0
        if (xb == 0 && u.dot(ob) >= 0) return false; // angle(ob, u) = 0
        if (xa*xb >= 0) { // Same side (up/down)
            int x = ob.cross(oa);
            if (x < 0) return true;
            else if (x > 0) return false;
            return oa.dist2() < ob.dist2();
        }
        return xa > 0;
    });
}