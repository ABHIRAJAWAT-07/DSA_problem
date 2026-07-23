class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int>pq(nums.begin(),nums.end());
        //  int ans=0;
        //  while(k--) //k times extract
        //  {
        //     ans=pq.top();
        //     pq.pop();
        //  }
        sort(nums.begin(),nums.end());
    int n=nums.size();
      return nums[n-k];           // MERGE SORT TC=n*log(n)

    
    
}
};