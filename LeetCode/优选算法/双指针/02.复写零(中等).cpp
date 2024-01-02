/* https://leetcode.cn/problems/duplicate-zeros/description/
给你一个长度固定的整数数组 arr ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
注意：请不要在超过该数组长度的位置写入元素。请对输入的数组就地进行上述修改，不要从函数返回任何东西。

示例 1：
输入：arr = [1,0,2,3,0,4,5,0]
输出：[1,0,0,2,3,0,0,4]
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]

示例 2：
输入：arr = [1,2,3]
输出：[1,2,3]
解释：调用函数后，输入的数组将被修改为：[1,2,3]
*/

#include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int> &arr) {
        int n = arr.size();
        int zeroCount = 0;

        // 首先计算我们需要复写的零的个数
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zeroCount++;
            }
        }

        // 从后向前复写零，同时考虑数组边界
        for (int i = n - 1, j = n + zeroCount - 1; i < j; i--, j--) {
            if (arr[i] != 0) {
                if (j < n) {
                    arr[j] = arr[i];
                }// 只有当j在数组边界内时才复制
            } else {
                if (j < n) {
                    arr[j] = arr[i];
                }// 复制零
                j--;
                if (j < n) {
                    arr[j] = arr[i];
                }// 复制零第二次
            }
        }
    }
};
