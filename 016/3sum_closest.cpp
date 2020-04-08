class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < len - 2; i++) {
            int low = i + 1;
            int high = len - 1;
            while(low < high) {
                int threesum = nums[i] + nums[low] + nums[high];
                if(abs(target - threesum) < abs(target - closest)) {
                    closest = threesum;
                }
                if(threesum > target) {
                    high--;
                } else if(threesum < target) {
                    low++;
                } else {
                    return threesum;
                }
            }
        }

        return closest;
    }
};
