class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int max=nums[0];
        int pos=0;
        int cont=0;
        for(auto &i : nums){
            if(i>max){
                max=i;
                pos=cont;
            }
            cont++;
        }
        if(k==1)
            return max;
        else{
            nums.erase(nums.begin()+pos);
            return findKthLargest(nums,k-1);
        }
    }
};
