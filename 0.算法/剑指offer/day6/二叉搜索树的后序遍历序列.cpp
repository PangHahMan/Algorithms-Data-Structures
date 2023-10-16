/* 描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true ,否则返回false 。假设输入的数组的任意两个数字都互不相同。
 */
#include <vector>
using namespace std;

class Solution {
public:
    //后序遍历根的左子树小于根 根的右子树大于根
    bool VerifySquenceOfBSTCore(vector<int> &sequence, int left, int right) {
        if (left >= right) {
            return true;
        }
        //记录根节点
        int root = sequence[right];
        int i = left;
        //寻找根的左子树,找中间值
        while (i < right && sequence[i] < root) {
            i++;
        }

        int mid = i;
        //从这里开始就是右子树了，只要右子树的节点一直大于根，直到i和right相等，说明右子树的节点的值都大于根，就可以证明是一个二叉搜索树
        while (i < right && sequence[i] > root) {
            i++;
        }

        return i == right && VerifySquenceOfBSTCore(sequence, left, mid - 1) && VerifySquenceOfBSTCore(sequence, mid, right - 1);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        return sequence.empty() ? false : VerifySquenceOfBSTCore(sequence, 0, sequence.size() - 1);
    }
};


//https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?