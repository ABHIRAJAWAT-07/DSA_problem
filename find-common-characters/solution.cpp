class Solution {
public:
   void fillCountArray(string &word, int count[26])
{
for(char &ch:word)
{
count[ch-'a']++;
}
 }// Word:[bella,label,roller]
// [word[0],word[1],word[2])
vector<string> commonChars(vector<string>& word)
{
vector<string>result;
int n=word.size();
int count[26]={0};
fillCountArray(word[0],count);
for(int i=1;i<n;i++)
{
int temp[26]={0};
fillCountArray(word[i],temp);//
for(int j=0;j<26;j++)
{
count[j]=min(count[j],temp[j]);

}
}
for(int i=0;i<26;i++)
{
int c=count[i];
while(c--)
{
// character representating the ith index
result.push_back(string(1,i+'a'));
}
}
return result;

}
};
     

        
    
