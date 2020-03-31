#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

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
