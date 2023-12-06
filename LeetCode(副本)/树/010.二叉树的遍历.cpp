/* 描述
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

输入描述：
输入包括1行字符串，长度不超过100。

输出描述：
可能有多组测试数据，对于每组数据， 输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。 每个输出结果占一行。

示例1
输入：
abc##de#g##f###
输出：
c b e g d f a 
*/

#include <iostream>
#include <string>

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *rebuildTree(const std::string &str, int &pi) {
    // If the string content is '#', return nullptr
    if (str[pi] == '#') {
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

void inOrder(TreeNode *root) {
    if (root == nullptr)
        return;

    inOrder(root->left);
    std::cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    std::string str;
    std::cin >> str;

    int i = 0;
    TreeNode *root = rebuildTree(str, i);
    inOrder(root);

    return 0;
}

//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking