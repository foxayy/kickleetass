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

    //思路:动态维护topK，遍历完所有数据TopK记录就是结果
    // 1.遍历数据，并记录出现次数
    // 2.若当前数据出现在topK记录中更新topK记录；
    //  若未出现
    //      若topK记录未满，添加新记录
    //      若topK记录已满，与最小值比较
    //          若大于最小值，去掉最小值，添加新记录
    //          若小于最小值，不做任何改变
    // 3.topK排序输出
    // 时间复杂度 O（n*k）+ O（k log k）
    // 空间复杂度 O（n）+ Q（k）* 2
    vector<string> topKFrequent1(vector<string>& words, int k) {
        map<string,int> dicts;
        map<string,int> topK;
        for(int i=words.size()-1;i>=0;--i){
            dicts[words[i]]+=1;
            if(topK.find(words[i])!=topK.end()){
                topK[words[i]]+=1;
            }else{
                if(topK.size()<k){
                    topK[words[i]]=dicts[words[i]];
                }else{
                    string minKey;
                    for(auto it=topK.begin();it!=topK.end();it++){
                        if(minKey.empty()){
                            minKey = it->first;
                            continue;
                        }
                        if(topK[it->first]>topK[minKey])
                            continue;
                        if(topK[it->first]<topK[minKey]){
                            minKey = it->first;
                            continue;
                        }
                        if(it->first>minKey){
                            minKey = it->first;
                        }
                    }
                    if(topK[minKey]>dicts[words[i]]){
                        continue;
                    }
                    if(topK[minKey]<dicts[words[i]]){
                        topK.erase(minKey);
                        topK[words[i]]=dicts[words[i]];
                        continue;
                    }
                    if(minKey>words[i]){
                        topK.erase(minKey);
                        topK[words[i]]=dicts[words[i]];
                        continue;
                    }
                }
            }
        }
        vector<KV> data;
        for(auto it=topK.begin();it!=topK.end();it++){
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
    //todo:优化代码及算法

};
int main(int argc, char *argv[])
{
    vector<string> data={"i", "love", "leetcode", "i", "love", "coding"};
    int k=2;

    Solution s;
    auto res = s.topKFrequent1(data,k);

    for(auto it = res.begin();it!=res.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
