class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length=nums.size();
        int i,j;
        for(i=0;i<length;i++){
            int flag=0;
            for(j=i+1;j<length;j++){
                if(nums[i]==nums[j]){
                    flag=1;
                    nums.erase(nums.begin()+j);
                    length=length-1;
                }
            }
            if(flag==1){
                nums.erase(nums.begin()+i);
                i=i-1;
                length=length-1;
            }
        }
        return nums[0];
    }
};