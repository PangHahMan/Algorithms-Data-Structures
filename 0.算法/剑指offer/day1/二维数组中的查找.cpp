/*描述：
在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

/* 
[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]
给定 target = 7，返回 true。
给定 target = 3，返回 false。
 */

/* 示例1
输入：
7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
返回值：
true
说明：
存在7，返回true    

实例2：
输入：
1,[[2]]
返回值：
false

示例3
输入：
3,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
返回值：
false
说明：
不存在3，返回false  
*/

/* 数组操作问题
解决思路：
如数组样式如下：
1 2 3 4
2 3 4 5
3 4 5 6
正常查找的过程，本质就是排除的过程，如果双循环查找，本质是一次排除一个，效率过低
根据题面要求，我们可以采取从右上角（或左下角）进行比较（想想为什么？），这样可以做到一次排除一行或者一列 */
#include <vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int>> &array) {
        int i = 0, j = array[0].size() - 1;
        while (i < array.size() && j >= 0) {
            //array[i][j]一定是当前行最大的，当前列最小的
            //如果target比array[i][j]还要小,那么target的值一定在array[i][j]的左边,j--即可(排除当前列)
            if (target < array[i][j]) {
                j--;
            }
            //如果target比array[i][j]要大,因为array[i][j]一定是当前行最大的，当前列最小的,所以i++即可,找当前列的下一行(排除当前行)
            else if (target > array[i][j]) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
};
//https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?