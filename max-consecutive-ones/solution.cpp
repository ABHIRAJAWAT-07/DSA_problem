class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int max_element=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                max_element=max(max_element,cnt);
                cnt=0;
            }
            else
            {
                cnt++;
            }
        }
        max_element=max(max_element,cnt);
        return max_element;

    
         
        
    }
};