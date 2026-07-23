// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
//     {  
         
//         vector <int> res(n+m);

//         int i=0;
//         int j=0;
//         int k=0;
//         while(i<=m-1 && j<=n-1)
//         {
//            if (nums1[i]<nums2[j])
//           {
//            res[k]=nums1[i];
//            i++;
        
            
//            }
//            else{
//            res[k]=nums2[j];
//            j++;
         
//            }
//            k++;
           
//         } 
//         if(i==m)
//         {
//             while(j<=n-1){
//                 res[k]=nums2[j];
                 
//                 k++;
//                 j++;
//             }
//         }
//       if(j==n) {
//          while(i<=m-1){
//                 res[k]=nums1[i];
                 
//                 k++;
//                 i++;
//             }
//         }
        

    
         
        
        
//     }
     
// };



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {  
        vector<int> res(m + n);

        int i = 0;
        int j = 0;
        int k = 0;

         
        while(i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                res[k] = nums1[i];
                i++;
            }
            else
            {
                res[k] = nums2[j];
                j++;
            }
            k++;
        }

        
        while(i < m) {
            res[k] = nums1[i];
            i++;
            k++;
        }

         
        while(j < n) {
            res[k] = nums2[j];
            j++;
            k++;
        }

         
        for (int x = 0; x < m + n; x++)
            nums1[x] = res[x];
    }
};
