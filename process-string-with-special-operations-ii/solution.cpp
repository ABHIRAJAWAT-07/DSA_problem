class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);
        long long cur = 0;

        // Record length after each operation
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c == '*') {
                if (cur > 0) cur--;
            } else if (c == '#') {
                cur *= 2;
            } else if (c == '%') {
                // length unchanged
            } else {
                cur++;
            }

            len[i] = cur;
        }

        if (k >= cur) return '.';

        // Backward simulation
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long sz = len[i];

            if (c == '*') {
                continue;
            } 
            else if (c == '#') {
                long long half = sz / 2;
                if (k >= half)  k -= half;
            } 
            else if (c == '%') {
                k = sz - 1 - k;
            } 
            else { // letter
                if (k == sz - 1) return c;
            }
        }

        return '.';
    }
};