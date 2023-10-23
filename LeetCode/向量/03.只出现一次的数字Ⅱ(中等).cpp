/* 
给你一个整数数组nums ，除某个元素仅出现一次外，其余每个元素都恰出现三次。请你找出并返回那个只出现了一次的元素。

示例 1：
输入：nums = [2,2,3,2]
输出：3

示例 2：
输入：nums = [0,1,0,1,0,1,99]
输出：99
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


//方法2 异或
class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        //1.整体异或
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result ^= nums[i];
        }

        //2.分解找到第一个比特位为1
        int flag = 1;
        int length = sizeof(int);
        for (int i = 0; i < length; i++) {
            if ((flag << i) & result) {
                flag <<= i;//找到1的位置
                break;
            }
        }

        //3.分组异或
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & flag) {
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }

        return {num1, num2};
    }
};

//https://leetcode.cn/problems/single-number-ii/description/