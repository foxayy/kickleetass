class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int i = 0;
        int j = length - 1;
        int res = 0;
        int tmp = 0;
        res = min(height[i], height[j]) * (j - i);
        while(i < j) {
            if(height[i] >= height[j]) {
                j--;
            } else {
                i++;
            }
            if((tmp = ((min(height[i], height[j])) * (j - i))) > res) {
                res = tmp;
            }
        }
        return res;
    }
};
