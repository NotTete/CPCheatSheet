/**
 * Author: N41h_Dr3s
 * Date: 2025-03-16
 * Description: Given an integer it gives you $\pi$(n). 
 * Time: O(n^{3/4})
 * Status: teted only with completly multipicative functions
 */
#pragma once
int count_primes(int n) { 
    auto f = [&](int n) {return 1;}; // (f(ab) = f(a)f(b))
    auto pref = [&](int n) {return n;}; // should return sum_{i=1..n} f(i)
    vector<int> v; v.reserve((int)sqrt(n) * 2 + 20);
    int sq, k = 1;
    for (; k * k <= n; k++) v.push_back(k);
    sq = --k;
    if (k * k == n) k--;
    for (; k >= 1; k--) v.push_back(n / k);
    vector<int> s(v.size());
    for (int i = 0; i < s.size(); i++) s[i] = pref(v[i]) - 1;
    auto geti = [&](int x) {return (x<=sq? (int)x-1:(int)(v.size() - (n / x)));};
    for (int p = 2; p * p <= n; p++)
        if (s[p - 1] != s[p - 2])
            for (int i = (int)v.size() - 1; p*p <= v[i] && i >= 0; --i)
                s[i] -= (s[geti(v[i] / p)] - s[p-2]) * f(p);

    return s.back();
}