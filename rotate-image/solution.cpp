class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0;i<=n-1;i++)
        {
            for(int j=i+1;j<=n-1;j++){
                int temp = mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
        for(int k=0;k<n;k++)
        {
           int i=0;
           int j=n-1;
           while(i<=j){
            int temp =mat[k][i];
            mat[k][i]=mat[k][j];
            mat[k][j]=temp;
            i++;
            j--;
           }
            
        }
       
         return;

    }
    
};