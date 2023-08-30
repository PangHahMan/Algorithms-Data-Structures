/* 
给定整数数组nums和整数k，请返回数组中第k个最大的元素。
请注意，你需要找的是数组排序后的第k个最大的元素，而不是第k个不同的元素。

示例 1:
输入: [3,2,1,5,6,4], k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
*/

#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> p{nums.begin(), nums.end()};//默认大堆

        while (k--) {
            p.pop();
        }

        p.top();
    }
};


// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/