#include <iostream>

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

#include <algorithm>

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
		unordered_map<int, int> dicts;
		for (const int& d : nums) {
			dicts[d]++;
		}
		priority_queue<pair<int,int>, vector<pair<int, int>>,cmp> topK;
		for (auto it : dicts) {
			topK.push(it);
			if (topK.size() > k) {
				topK.pop();
			}
		}
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
