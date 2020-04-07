#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// 42. 接雨水
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/trapping-rain-water
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
// 题解链接：https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int m = 0;
        for(int i=height.size()-1;i>=0;i--)
            if(height[m]<height[i])
                m = i;
        int res = 0;
        //左边
        for(int i=0,low=height[0];i<m;i++)
        {
            if(height[i]>low)
            {
                low = height[i];
            }else
            {
                res += height[i]-low;    
            }
        }
        //右边
        for(int i=height.size()-1,low = height[height.size()-1];i>m;i--)
        {
            if(height[i]>low)
            {
                low = height[i];
            }else
            {
                res += height[i]-low;    
            }
        }
        return -res;
    }
};

int main(int argc, char *argv[])
{
	vector<int> data={0,1,0,2,1,0,1,3,2,1,2,1};
    
	Solution s;
	cout<<s.trap(data)<<endl;

	return 0;
}