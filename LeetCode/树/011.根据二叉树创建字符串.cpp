/* 
给你二叉树的根节点root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。
空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

题目的意思是子节点需要用()来包裹。举例来说，二叉树[root,left,right]，则转换为root(left)(right)。如果只有left为空节点，则输出root()(right)；如果只有right为空节点则可以忽略右节点的()，输出为root(left)。

*/

#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    string tree2str(TreeNode *root) {
        if (root == nullptr)
            return "";

        string str = to_string(root->val);
        // 1.走左子树，左子树两种情况，
        // 1是左子树为空，省略()
        // 2是左子树为空，右子树不为空，则不省略()
        if (root->left) {
            str += '(';
            str += tree2str(root->left);
            str += ')';
        }

        if (root->left == nullptr && root->right) {
            str += '(';
            str += "";
            str += ')';
        }

        //2.走右子树
        if (root->right) {
            str += '(';
            str += tree2str(root->right);
            str += ')';
        }

        return str;
    }
};

// https://leetcode.cn/problems/construct-string-from-binary-tree/