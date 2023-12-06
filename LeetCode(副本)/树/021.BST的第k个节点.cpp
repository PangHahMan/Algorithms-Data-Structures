/*描述
给定一棵结点数为n 二叉搜索树，请找出其中的第 k 小的TreeNode结点值。
1.返回第k小的节点值即可
2.不能查找的情况，如二叉树为空，则返回-1，或者k大于n等等，也返回-1
3.保证n个节点的值不一样
*/

#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int KthNode(TreeNode *proot, int k) {
        if (proot == nullptr || k <= 0) {
            return -1;
        }

        stack<TreeNode *> st;
        TreeNode *cur = proot;
        //使用循环来模拟中序遍历,递归的效率比较低
        while (cur || !st.empty()) {
            //左子树全部入栈
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            //根
            cur = st.top();
            st.pop();
            //返回最小值
            if (--k == 0){
                return cur->val;
            }
            //右子树
            cur = cur->right;
        }

        return -1;
    }
};

//https://www.nowcoder.com/practice/57aa0bab91884a10b5136ca2c087f8ff?tpId=13&tqId=2305268&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13