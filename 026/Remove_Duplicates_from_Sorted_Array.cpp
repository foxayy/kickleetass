class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        int i = 0;
        for(int j = i + 1; j < len; j++) {
            if(nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        i++;
        return i;
    }
};
