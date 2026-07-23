class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> lg(n + 1);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int m = lg[n] + 1;

        vector<vector<int>> mx(m, vector<int>(n));
        vector<vector<int>> mn(m, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mx[0][i] = nums[i];
            mn[0][i] = nums[i];
        }

        for (int j = 1; j < m; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[j][i] = max(
                    mx[j - 1][i],
                    mx[j - 1][i + (1 << (j - 1))]
                );

                mn[j][i] = min(
                    mn[j - 1][i],
                    mn[j - 1][i + (1 << (j - 1))]
                );
            }
        }

        auto getValue = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int j = lg[len];

            int maxVal = max(
                mx[j][l],
                mx[j][r - (1 << j) + 1]
            );

            int minVal = min(
                mn[j][l],
                mn[j][r - (1 << j) + 1]
            );

            return 1LL * maxVal - minVal;
        };

        using T = tuple<long long, int, int>;
        priority_queue<T> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getValue(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({getValue(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }
};