#include <stddef.h>
struct Node
{
    int val;
    struct Node *next;
    struct Node *random;
};

// 思路：复制每一个链表到后面，设置各值域，然后解绑，尾插到新链表
struct Node *copyRandomList(struct Node *head)
{
    // 1.复制链表
    struct Node *cur = head;
    while (cur)
    {
        // copynode是复制的节点
        struct Node *copynode = (struct Node *)malloc(sizeof(struct Node));
        // nextnode是记录下一个节点
        struct Node *nextnode = cur->next;
        copynode->val = cur->val;

        cur->next = copynode;
        copynode->next = nextnode;

        cur = nextnode;
    }

    // 2.设置random - 这里注意random要另外设置，因为random指向随机，必须在第一次循环复制完在设置random值
    cur = head;
    while (cur)
    {
        struct Node *copynode = cur->next;
        struct Node *nextnode = copynode->next;
        if (cur->random == NULL)
        {
            copynode->random = NULL;
        }
        else
        {
            copynode->random = cur->random->next;
        }
        cur = nextnode;
    }

    // 尾插到新链表
    cur = head;
    struct Node *copyhead = NULL;
    struct Node *copytail = NULL;

    while (cur)
    {
        // 找插入链表
        struct Node *copynode = cur->next;
        struct Node *nextnode = copynode->next;
        // 尾插
        if (copyhead == NULL)
        {
            copyhead = copytail = copynode;
        }
        else
        {
            copytail->next = copynode;
            copytail = copytail->next;
        }
        cur->next = nextnode;
        cur = nextnode;
    }
    return copyhead;
}
// https://leetcode.cn/problems/copy-list-with-random-pointer/