/*
在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

//正常查找的过程，本质就是排除的过程，如果双循环查找，本质是一次排除一个，效率过低
//根据题面要求，我们可以采取从右上角（或左下角）进行比较（想想为什么？），这样可以做到一次排除一行或者一列
#include <vector>
using namespace std;
class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        //右上角开始i等于0，j等于array[0].size() - 1
        int i = 0;
        int j = array[0].size() - 1;
        while (i < array.size() && j >= 0)
        {
            //array[i][j]一定是当前行最大的，当前列最小的
            if(target>array[i][j])
            {
                //target > array[i][j] 排除当前行
                i++;
            }
            else if(target<array[i][j])
            {
                //target < array[i][j] 排除当前列
                j--;
            }
            else
            {
                //找到
                return true;
            }
        }
        return false;
    }
};

// https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?