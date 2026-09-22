class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int left=0;
        int right=n-1;
        int ind=n-1;
        while(left<=right){
            if(abs(nums[left])<abs(nums[right])){
                ans[ind]=nums[right]*nums[right];
                right--;

            }
            else{
                ans[ind]=nums[left]*nums[left];
                left++;

            }
            ind--;

        }
        return ans;
    }
};