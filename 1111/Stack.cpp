#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		int d = 0,i=0;
        vector<int> ans(seq.size());
        for (const char& c : seq)
            if (c == '(') {
                ++d;
                ans[i++]=d % 2;
            }
            else {
                ans[i++]=d % 2;
                --d;
            }
        return ans;
	}
};

int main(int argc, char *argv[])
{
    string data=  "(()())";

    Solution s;
    auto res = s.maxDepthAfterSplit(data);

    for(auto it = res.begin();it!=res.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
