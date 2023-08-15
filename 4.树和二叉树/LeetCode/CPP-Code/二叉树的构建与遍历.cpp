#include <iostream>
#include <string>

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *rebuildTree(const std::string &str, int &pi)
{
    // If the string content is '#', return nullptr
    if (str[pi] == '#')
    {
        pi++;
        return nullptr;
    }

    // Allocate a node, assign string content to root->val, and increment pi
    TreeNode *root = new TreeNode;
    root->val = str[pi++];

    // Recursively build left and right subtrees
    root->left = rebuildTree(str, pi);
    root->right = rebuildTree(str, pi);
    return root;
}

void inOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    inOrder(root->left);
    std::cout << root->val << " ";
    inOrder(root->right);
}

int main()
{
    // Input characters and rebuild the tree based on characters
    std::string str;
    std::cin >> str;

    int i = 0;
    TreeNode *root = rebuildTree(str, i);
    inOrder(root);

    return 0;
}
