/* 
给定一个单词列表words和一个整数k ，返回前k个出现次数最多的单词。
返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， 按字典顺序排序。

示例 1：
输入: words = ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
注意，按字母顺序 "i" 在 "love" 之前。

示例 2：
输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
出现次数依次为4, 3, 2和1次。
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    //比较方式 小堆
    struct Com {
        bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
            //规则：单词个数相同则比较字典单词,不相同则比较出现次数
            if (a.second == b.second) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        }
    };

    vector<string> topKFrequent(vector<string> &words, int k) {
        //采用map统计每个单词出现的次数
        unordered_map<string, int> map;
        for (auto &word: words) {
            map[word]++;
        }

        //用优先级队列,小堆方式
        priority_queue<pair<string, int>, vector<pair<string, int>>, Com> q;

        //建堆小堆,超过堆的个数就pop掉堆顶,把最小的pop掉,最后留下的就是最大的K个数
        for (auto &e: map) {
            q.push(e);
            if (q.size() > k) {
                q.pop();
            }
        }

        //因为是小堆,所以反向插入到vector中
        vector<string> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = q.top().first;
            q.pop();
        }

        return ret;
    }
};

//https://leetcode.cn/problems/top-k-frequent-words/description/