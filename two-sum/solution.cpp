class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> d;

        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];

            if (d.find(t) != d.end()) {
                return {d[t], i};
            }

            d[nums[i]] = i;
        }

        return {};
    }
};