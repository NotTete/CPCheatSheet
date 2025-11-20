/**
 * Author: Dalopir
 * Date: 2025-11-20
 * Description: Hierholzer
 * Time: O(m)
 */
#pragma once

vi used, r;
void dfs(int u) {
    while (!e[u].empty()) {
        auto [v, i] = e[u].back(); e[u].pop_back();
        if (used[i]) continue; used[i] = true;
        dfs(v);
    }
    r.push_back(u);
}
