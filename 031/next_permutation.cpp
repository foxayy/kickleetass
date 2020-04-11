class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 2;
        while(0 <= i) {
            if(nums[i] >= nums[i + 1]){
                i--;
            } else {
                break;
            }
        }
        if(0 <= i) {
            int j = len - 1;
            while(j >= 0 && nums[j] <= nums[i]) j--;
            swap(nums[j], nums[i]);
        }
        reverse(nums, i + 1, len - 1);
    }

private:
    void reverse(vector<int>& nums, int start, int end) {
        int i = start;
        int j = end;
        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
