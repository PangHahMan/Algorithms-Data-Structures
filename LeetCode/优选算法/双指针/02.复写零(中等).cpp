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
        int cur = 0, dest = -1;
        int n = arr.size();
        while (cur < n) {
            if (arr[cur]) {
                dest++;
            } else {
                dest += 2;
            }
            if (dest >= n - 1) {
                break;
            }
            cur++;
        }

        /* dest等于n表示在最后一次增加dest时，我们是因为原数组的cur位置是零而增加了2。这意味着原数组的最后一个零是无法复制的，因为它会超出数组末尾。所以，我们要做的是：
        1.将原数组的最后一个位置设为零。
        2.cur需要回退一个位置，因为我们不需要再复制这个无法复制的最后一个零。
        3.dest需要减去2，一是因为最后一个零不复制，二是回退到倒数第二个应该复制的位置上。 */
        if (dest == n) {
            arr[n - 1] = 0;  
            cur--;
            dest -= 2;
        }

        while (cur >= 0) {
            if (arr[cur]) {
                arr[dest--] = arr[cur--];
            } else {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }
    }
};