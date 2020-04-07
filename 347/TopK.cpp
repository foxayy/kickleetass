#include <iostream>

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

#include <algorithm>

// 347. 前 K 个高频元素
// 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
// 示例 1:
// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
//
// 示例 2:
// 输入: nums = [1], k = 1
// 输出: [1]
// 说明：
// 	你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
// 	你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/top-k-frequent-elements
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//TopK问题
//思路：哈希表 + 限制优先队列（堆）
//时间复杂度：O(NlogK)
//空间复杂度：O(N)
using namespace std;
class Solution {
public:
	struct cmp {
		bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
			return p1.second > p2.second;
		}
	};
	vector<int> topKFrequent(vector<int>& nums, int k) {

		//统计整数对应出现次数，O（N）
		unordered_map<int, int> dicts;
		for (const int& d : nums) {
			dicts[d]++;
		}

		//建立优先队列（小根堆），O（NlogK）
		priority_queue<pair<int,int>, vector<pair<int, int>>,cmp> topK;
		for (auto it : dicts) {
			topK.push(it);
			if (topK.size() > k) {//堆的大小超过K，移除当前最小值
				topK.pop();
			}
		}

		//读出结果
		vector<int> res(k);
		while (!topK.empty()) {
			res[--k] = topK.top().first;
			topK.pop();
		}
		return res;
	}
};
int main(int argc, char *argv[])
{
	vector<int> data = { 4,1,-1,2,-1,2,3};
	int k = 2;
	Solution s;
	auto res = s.topKFrequent(data,k);
	for (auto it = res.begin(); it != res.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
