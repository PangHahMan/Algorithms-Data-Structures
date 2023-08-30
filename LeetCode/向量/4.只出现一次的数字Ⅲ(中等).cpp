/* 
给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按任意顺序返回答案。
你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。

示例 1：
输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。

示例 2：
输入：nums = [-1,0]
输出：[-1,0]

示例 3：
输入：nums = [0,1]
输出：[1,0]
 */

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        // 创建一个无序哈希表，用于存储数字和其出现频次的关系
        unordered_map<int, int> freq;

        // 遍历输入数组，统计每个数字的出现频次
        for (int num: nums) {
            freq[num]++;
        }

        vector<int> ans;

        // 遍历哈希表中的每个键值对，自动拆解为数字和频次
        for (auto num: freq) {
            if (num.second == 1) {
                ans.push_back(num.first);// 将出现频次为 1 的数字添加到结果向量中
            }
        }

        return ans;// 返回存储了只出现一次的数字的向量
    }
};

//https://leetcode.cn/problems/single-number-iii/