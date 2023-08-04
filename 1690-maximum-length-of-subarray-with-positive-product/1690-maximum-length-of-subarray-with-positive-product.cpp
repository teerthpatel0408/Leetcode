class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int res=0;
        int sz=nums.size();
        for(int i=0;i<sz;i++){     
              int n_s=-1,n_e=-1,n=0,p=0,j;
              for(j=i;j<sz;j++){    
                  if(nums[j]<0) n++;
                  if(nums[j]>0)p++;
                  if(nums[j]<0&&n_s==-1) { n_s=j;} 
                  if(nums[j]<0) n_e=j;             
                  if(nums[j]==0) break;            
              }
             
             if(n%2==0) res=max(res,n+p);
             if(n%2==1)
             {
                  res=max(j-n_s-1,res);
                  res=max(n_e-i,res);
             }

           i=j; 
        }
         
        
        return res;
    }
};