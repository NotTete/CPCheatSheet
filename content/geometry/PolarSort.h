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
int p(int x, int y){return x>0^y>0|2*(y>0);}
sort(v.begin(), v.end(), 
    [](const Point<int>& a,const Point<int>& b) {
        return p(a.x,a.y) == p(b.x,b.y) ? a.x*b.y > a.y*b.x : p(a.x,a.y) < p(b.x,b.y);
    }
);