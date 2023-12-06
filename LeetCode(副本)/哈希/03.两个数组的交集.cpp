/* 
给定两个数组 nums1 和 nums2 ，返回它们的交集 。输出结果中的每个元素一定是唯一的。我们可以不考虑输出结果的顺序 。
示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
 */

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        //1.先将nums1和nums2进行去重
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        vector<int> ret;  
        //2.进行查找，判断st2中的值是否在st1中存在，存在则存放在ret中
        for (auto &st: st2) {
            if (st1.find(st) != st1.end()) {
                ret.push_back(st);
            }
        }

        return ret;
    }
};
//https://leetcode.cn/problems/intersection-of-two-arrays/description/