// ����
// ��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
// �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
// ������˶������Ժ��ٶԶ������������������������������

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
    //�������������Ϊ# ˵��ΪNULL
    if (str[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    //mallocһ���ڵ㣬���������ݣ���root��ֵ����i++
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = str[(*pi)++];

    //�ݹ���������������
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
    //�����ַ�,�����ַ��ؽ���
    char str[100];
    scanf("%s",str);

    int i = 0;
    //�����i����ȡ��ַ����Ϊ�ݹ���i�ڶ��лᱻ��������
    struct TreeNode *root = rebulidTree(str, &i);
    InOrder(root);
    return 0;
}
// https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking