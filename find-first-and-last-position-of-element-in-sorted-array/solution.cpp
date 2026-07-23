 class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>res(2,-1);
        int beg=0;
        int end=n-1;
       while(beg<=end)
        {
            int mid=beg+(end-beg)/2;
            if(target==nums[mid])
                 {
                    res[0]=mid;
                    end = mid - 1; }
            
            else if(target>nums[mid])
                beg=mid+1;  
            else 
               end=mid-1;
    }
    beg=0;
    end=n-1;
    while(beg<=end)
        {
            int mid=beg+(end-beg)/2;
            if(target==nums[mid])
                 {
                    res[1]=mid; 
                     beg = mid + 1; 
                 }
            else if(target<nums[mid])
               end=mid-1;
            else 
               beg=mid+1; 
    }
        return res;
    }
};