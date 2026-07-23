class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[17][11][11][2];
    bool vis[17][11][11][2];

    Node dfs(int pos, int p1, int p2, bool started, bool tight) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][p1][p2][started]) {
            return dp[pos][p1][p2][started];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool nStarted = started || d != 0;

            int np1 = p1, np2 = p2;
            long long add = 0;

            if (!nStarted) {
                Node nxt = dfs(pos + 1, 10, 10, false,
                               tight && d == limit);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
                continue;
            }

            if (!started) {
                np1 = d;
                np2 = 10;
            } else if (p2 == 10) {
                np2 = p1;
                np1 = d;
            } else {
                if ((p2 < p1 && p1 > d) ||
                    (p2 > p1 && p1 < d))
                    add = 1;

                np2 = p1;
                np1 = d;
            }

            Node nxt = dfs(pos + 1, np1, np2, true,
                           tight && d == limit);

            res.cnt += nxt.cnt;
            res.wav += nxt.wav + add * nxt.cnt;
        }

        if (!tight) {
            vis[pos][p1][p2][started] = true;
            dp[pos][p1][p2][started] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        auto melidroni = make_pair(num1, num2);
        return solve(num2) - solve(num1 - 1);
    }
};