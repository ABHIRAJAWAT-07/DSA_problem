class Solution {
private:
    long long solve(vector<int>& Astart, vector<int>& Adur,
                    vector<int>& Bstart, vector<int>& Bdur) {

        int m = Bstart.size();

        vector<pair<int, int>> rides(m);
        for (int i = 0; i < m; ++i)
            rides[i] = {Bstart[i], Bdur[i]};

        sort(rides.begin(), rides.end());

        vector<int> start(m);
        vector<long long> prefMinDur(m), sufMinFinish(m);

        start[0] = rides[0].first;
        prefMinDur[0] = rides[0].second;

        for (int i = 1; i < m; ++i) {
            start[i] = rides[i].first;
            prefMinDur[i] = min(prefMinDur[i - 1],
                                (long long)rides[i].second);
        }

        sufMinFinish[m - 1] =
            (long long)rides[m - 1].first + rides[m - 1].second;

        for (int i = m - 2; i >= 0; --i) {
            sufMinFinish[i] = min(
                sufMinFinish[i + 1],
                (long long)rides[i].first + rides[i].second
            );
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < (int)Astart.size(); ++i) {
            long long finishA = (long long)Astart[i] + Adur[i];

            int pos = upper_bound(
                start.begin(),
                start.end(),
                finishA
            ) - start.begin();

            long long best = LLONG_MAX;

            if (pos > 0)
                best = finishA + prefMinDur[pos - 1];

            if (pos < m)
                best = min(best, sufMinFinish[pos]);

            ans = min(ans, best);
        }

        return ans;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long landThenWater =
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration);

        long long waterThenLand =
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration);

        return (int)min(landThenWater, waterThenLand);
    }
};