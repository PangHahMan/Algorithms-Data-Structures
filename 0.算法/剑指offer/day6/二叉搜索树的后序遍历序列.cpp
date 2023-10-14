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

        int root = sequence[right];
        int i = left;
        while (i < right && sequence[i] < root) {
            i++;
        }

        int mid = i;
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