    // int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    // num[u] = low[u] = ++timedfs;
    // for (int v : adj[u]) {
    //     if (v == par) continue;
    //     if (num[v]==-1) {
    //         dfs(v, u);
    //         low[u] = min(low[u], low[v]);
    //         if (low[v] == num[v]) cau++;
    //         child++;
    //         if (0 == par) { // Nếu u là đỉnh gốc của cây DFS
    //             if (child > 1) khop[u] = true;
    //         }
    //         else if (low[v] >= num[u]) khop[u] = true;
    //     }
    //     else low[u] = min(low[u], num[v]);
    // }