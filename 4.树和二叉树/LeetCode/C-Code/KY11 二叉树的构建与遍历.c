// 描述
// 编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。
// 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
// 建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *rebulidTree(char *str, int *pi)
{
    //如果数组中内容为# 说明为NULL
    if (str[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    //malloc一个节点，将数组内容，给root赋值，在i++
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = str[(*pi)++];

    //递归左子树，右子树
    root->left = rebulidTree(str, pi);
    root->right = rebulidTree(str, pi);
    return root;
}

void InOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main()
{
    //输入字符,根据字符重建树
    char str[100];
    scanf("%s",str);

    int i = 0;
    //这里的i必须取地址，因为递归中i在堆中会被反复利用
    struct TreeNode *root = rebulidTree(str, &i);
    InOrder(root);
    return 0;
}
// https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking