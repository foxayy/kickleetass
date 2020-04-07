#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// 692. 前K个高频单词
// 给一非空的单词列表，返回前 k 个出现次数最多的单词。
// 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

// 示例 1：
// 输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// 输出: ["i", "love"]
// 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//     注意，按字母顺序 "i" 在 "love" 之前。

// 示例 2：
// 输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// 输出: ["the", "is", "sunny", "day"]
// 解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//     出现次数依次为 4, 3, 2 和 1 次。

// 注意：
//     假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
//     输入的单词均由小写字母组成。
//  

// 扩展练习：
//     尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/top-k-frequent-words
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    struct KV{
        string key;
        int value;
    };

    //思路：暴力算法
    // 1.记录每个字符串出现次数
    // 2.排序，找到topk
    //时间复杂度：O(N)*2+O(NlogN)
    //空间复杂度：O(N)*2
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> dicts;
        for(int i=words.size()-1;i>=0;i--){
            dicts[words[i]]+=1;
        }
        vector<KV> data;
        for(auto it=dicts.begin();it!=dicts.end();it++){
            KV kv;
            kv.key=it->first;
            kv.value=it->second;
            data.push_back(kv);
        }
        sort(data.begin(),data.end(),[](const KV& d1,const KV& d2){
            if(d1.value>d2.value)
                return true;
            if(d1.value < d2.value)
                return false;
            if(d1.key<d2.key)
                return true;
            return false;
        });
        vector<string> res;
        for(int i=0;i<k && i<data.size();i++){
            res.push_back(data[i].key);
        }
        return res;
    }

    struct cmp
    {
        bool operator()(pair<int,string>& p1,pair<int,string>& p2){
            if(p1.first!=p2.first){
                return p1.first<p2.first;
            }else{
                return p1.second>p2.second;
            }
        }
    };

    //思路：优先队列+哈希表
    //  优先队列的底层实现是一个堆
    //  unordered_map底层实现为哈希表，map是红黑树
    //时间复杂度：Q(NlogN)
    //空间复杂度：Q(N)
    vector<string> topKFrequent2(vector<string>& words, int k) {
        
        unordered_map<string,int> dicts;
        for(auto it:words){
            dicts[it]+=1;
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> topK;
        for(auto it:dicts){
            topK.push(pair<int,string>(it.second,it.first));
        }

        vector<string> res;
        while (k--)
        {
            res.push_back(topK.top().second);
            topK.pop();
        }
        return res;
    }

};
int main(int argc, char *argv[])
{
    vector<string> data={"i", "love", "leetcode", "i", "love", "coding"};
    int k=2;

    Solution s;
    auto res = s.topKFrequent2(data,k);

    for(auto it = res.begin();it!=res.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
