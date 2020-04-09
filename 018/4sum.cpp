class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        int low = 0;
        int high = len - 3;
        vector<vector<int>> result;
        //sort
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 3; i++) {
            int new_target = target - nums[i];
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            for(int j = i + 1; j < len - 2; j++) {
                if(j > i + 1 && nums[j - 1] == nums[j]) continue;
                low = j + 1;
                high = len - 1;
                while(low < high) {
                    if(nums[j] + nums[low] + nums[high] == new_target) {
                        result.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while(low < len - 1 && nums[low] == nums[low + 1]) low++;
                        while(high > 0 && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                    } else if(nums[j] + nums[low] + nums[high] > new_target) {
                        while(high > 0 && nums[high] == nums[high - 1]) high--;
                        high--;
                    } else {
                        while(low < len - 1 && nums[low] == nums[low + 1]) low++;
                        low++;
                    }
                }
            }
        }
        return result;
    }
};
