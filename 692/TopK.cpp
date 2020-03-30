#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    struct KV{
        string key;
        int value;
    };
    //时间复杂度：O(N)*2+O(NlogN)
    //空间复杂度：O(N)*2
    //思路：暴力算法
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::map<string,int> dicts;
        for(int i=words.size()-1;i>=0;i--){
            dicts[words[i]]+=1;
        }
        std::vector<KV> data;
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
    //Todo:优化算法
    // O(n log k) 时间复杂度和 O(n) 空间复杂度

};
int main(int argc, char *argv[])
{
    vector<string> data={"i", "love", "leetcode", "i", "love", "coding"};
    int k=2;
    Solution s;
    auto res = s.topKFrequent(data,k);
    for(auto it = res.begin();it!=res.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
