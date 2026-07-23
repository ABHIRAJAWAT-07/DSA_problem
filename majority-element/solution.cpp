class Solution {
public:
    int majorityElement(vector<int>& nums)
    {  
    // { //approach1----
    //        int n=nums.size();
    //     unordered_map<int,int>m;
    //     for(auto a:nums)
    //     {
    //         m[a]++;
    //         if(m[a]>n/2) return a;


    //     }
    //     return -1;
    //           // approach 2---  // sort(nums.begin(),nums.end());
    //     // return nums[(int)nums.size()/2];


        
    // }
    sort(nums.begin(), nums.end());
    return nums[(nums.size())/2];
    }
};