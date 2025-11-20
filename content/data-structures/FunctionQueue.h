/**
 * Author: Dalopir
 * Date: 2025-11-20
 * Description: A queue where you can query any Commutative and Asociative function
 * Time: O(1)
 */
#pragma once

using T = int;
T f(T a, T b) { return min(a, b); }
struct QueueFn {
    vector<pair<T, T>> l, r;
    void dump() {
        if (!l.empty()) return;
        while (!r.empty()) {
            T v = r.back().first; r.pop_back();
            l.push_back({v, !l.empty() ? f(l.back().second, v) : v});
        }
    }
    T query() {
        if (l.empty()) return r.back().second;
        if (r.empty()) return l.back().second;
        return f(l.back().second, r.back().second);
    }
    void push(T v) { r.push_back({v, !r.empty() ? f(r.back().second, v) : v}); }
    void pop() { dump(); l.pop_back(); }
    T front() { dump(); return l.back().first; }
    T back() { return !r.empty() ? r.back().first : l.front().first; }
    int size() { return l.size()+r.size(); }
    bool empty() { return size() == 0; }
};
