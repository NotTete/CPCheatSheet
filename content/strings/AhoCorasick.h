/**
 * Author: Jorge Hernández Palop
 * Date: 2025-11-20
 * Source: Our code
 * Description: Aho-Corasick automaton, used for multiple pattern matching.
 * Time: construction takes $O(26N)$, where $N =$ sum of length of patterns.
 * Status: Tested once
 */
#pragma once

#define FIRST 'a'
#define ALPHA 26
struct Node { int s = 0, cnt = 0, ch[ALPHA] = {}; };
vector<int> AhoCora(vector<string>& str, string& s) {
    int n = str.size();
    vector<Node> t(1);
    vector<int> idx(n);
    rep(i, 0, n) { // Build Trie
        int u = 0;
        for (char c : str[i]) {
            if (!t[u].ch[c -= FIRST]) t[u].ch[c] = t.size(), t.emplace_back();
            u = t[u].ch[c];
        }
        idx[i] = u;
    }
    vector<int> q; // Build Automaton
    rep(i, 0, ALPHA) if (t[0].ch[i]) q.push_back(t[0].ch[i]);
    rep(head, 0, q.size()) {
        int u = q[head];
        rep(i, 0, ALPHA) {
            int &v = t[u].ch[i], f = t[t[u].s].ch[i];
            if (v) t[v].s = f, q.push_back(v);
            else v = f;
        }
    }
    int u = 0; // Process text
    for (char c : s) t[u = t[u].ch[c - FIRST]].cnt++;
    for (int i = q.size(); i--; ) t[t[q[i]].s].cnt += t[q[i]].cnt;
    vector<int> res(n);
    rep(i, 0, n) res[i] = t[idx[i]].cnt;
    return res;
}
