class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         for(int i=1; i<=n; i++)
         {  int p=0, q=0;
            for(vector<int>&t :trust){
                if(t[0]==i) 
                p++;
                else if(t[1]==i)
                q++;
            }    
            if(p==0 && q==n-1)
            return i;     
            }

        return -1;
    }
};