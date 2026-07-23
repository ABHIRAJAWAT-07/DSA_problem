class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        int x = calc(landStartTime, landDuration,
                     waterStartTime, waterDuration);

        int y = calc(waterStartTime, waterDuration,
                     landStartTime, landDuration);

        return min(x, y);
    }

private:
    int calc(vector<int>& start1, vector<int>& dur1,
             vector<int>& start2, vector<int>& dur2) {

        int minEnd = INT_MAX;

        for (int i = 0; i < start1.size(); i++) {
            minEnd = min(minEnd, start1[i] + dur1[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < start2.size(); i++) {
            ans = min(ans,
                      max(minEnd, start2[i]) + dur2[i]);
        }

        return ans;
    }
};