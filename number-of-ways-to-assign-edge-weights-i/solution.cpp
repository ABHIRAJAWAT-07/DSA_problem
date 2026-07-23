class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1, depth = 0;

        vector<vector<int>> g(n + 1);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        auto dfs = [&](auto&& self, int u, int p, int d) -> void {
            depth = max(depth, d);
            for (int v : g[u])
                if (v != p)
                    self(self, v, u, d + 1);
        };

        dfs(dfs, 1, 0, 0);

        long long ans = 1, base = 2, exp = depth -1;
        while (exp > 0) {
            if (exp & 1) ans = ans * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }

        return ans;
    }
};