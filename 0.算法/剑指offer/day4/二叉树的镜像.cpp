/* 描述
操作给定的二叉树，将其变换为源二叉树的镜像。 
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *Mirror(TreeNode *pRoot) {
        if (pRoot == nullptr) {
            return nullptr;
        }

        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;

        Mirror(pRoot->left);
        Mirror(pRoot->right);

        return pRoot;
    }
};


//https://www.nowcoder.com/practice/a9d0ecbacef9410ca97463e4a5c83be7