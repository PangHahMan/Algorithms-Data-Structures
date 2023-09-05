#include "SList.h"
// 动态申请一个节点
SListNode *BuySListNode(SLDataType x) {
    SListNode *newnode = (SListNode *) malloc(sizeof(SListNode));//申请空间
    if (newnode == NULL) {
        perror("malloc fail");
        exit(-1);
    } else {
        newnode->data = x;   //将数据赋值到新结点的数据域
        newnode->next = NULL;//将新结点的指针域置空
        return newnode;
    }
}

// 创建n个结点
SListNode *SListCreate(int n) {
    SListNode *phead = NULL, *ptail = NULL;
    for (int i = 0; i < n; i++) {
        // scanf("%d", &x);
        // SLTNode* newnode = BuySLTNode(x);
        SListNode *newnode = BuySListNode(i);
        if (phead == NULL) {
            ptail = phead = newnode;
        } else {
            ptail->next = newnode;
            ptail = newnode;
        }
    }
    return phead;
}

// 单链表打印
void SListPrint(SListNode *plist) {
    // 不用assert  单链表为NULL 打印NULL即可
    SListNode *cur = plist;//接收头指针
    while (cur)            // cur!=NULL
    {
        printf("%d->", cur->data);
        cur = cur->next;//更新结点,走下一个结点
    }
    printf("NULL\n");
}

// 单链表尾插
void SListPushBack(SListNode **pplist, SLDataType x) {
    SListNode *newnode = BuySListNode(x);
    //如果链表为NULL,那么新插入的结点就是头结点
    if (*pplist == NULL) {
        *pplist = newnode;
    } else {
        //遍历找最后的结点
        SListNode *tail = *pplist;
        while (tail->next)// 注意：这里是找下一个，在尾插的前一个结点要设置next
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

// 单链表的头插
void SListPushFront(SListNode **pplist, SLDataType x) {
    SListNode *newnode = BuySListNode(x);//申请一个新结点
    // 头插不用判断是否为空，如果为空，那么newnode->next就为空
    newnode->next = *pplist;//新结点指向头结点
    *pplist = newnode;      //在更新头结点
}

// 尾删
void SListPopBack(SListNode **pplist) {
    assert(*pplist);
    // 创建两个结点一个指向第一个，一个指向第二个，因为删除结点要找到前一个结点的next赋值
    SListNode *prev = NULL;
    SListNode *tail = *pplist;
    // 1.只有一个节点
    // 2.两个及以上的节点
    if (tail->next == NULL) {
        free(tail);
        *pplist = NULL;
    } else {
        while (tail->next)// 如果下一个结点为空，就删除当前结点，在将prev结点的next赋值为NULL
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;
    }
}

// 头删
void SListPopFront(SListNode **pplist) {
    assert(*pplist);
    // 为NULL直接assert，不为空直接将头结点删除，下一个结点变成头结点
    SListNode *nextnode = (*pplist)->next;
    free(*pplist);
    *pplist = nextnode;
}

// 单链表查找
SListNode *SListFind(SListNode *plist, SLDataType x) {
    SListNode *cur = plist;
    while (cur) {
        if (cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

// 单链表的销毁
void SListDestroy(SListNode **pplist) {
    SListNode *cur = *pplist;
    while (cur) {
        SListNode *nextnode = cur->next;
        free(cur);
        cur = nextnode;
    }
    *pplist = NULL;
}

// x插入到pos位置之后
void SListInsertAfter(SListNode *pos, SLDataType x) {
    // pos不能为NULL
    assert(pos);
    SListNode *newnode = BuySListNode(x);
    // 将创建的新结点插入到pos之后
    newnode->next = pos->next;
    pos->next = newnode;
}

// x插入到pos位置之前
void SListInsert(SListNode **pplist, SListNode *pos, SLDataType x) {
    assert(pos);
    // 如果pos的位置在头结点的位置，逻辑就为头插，否则就插入到前面
    if (*pplist == pos) {
        SListPushFront(pplist, x);
    } else {
        // 创建一个开始的结点,然后判断prev的next是否为pos  是的话，就连接prev和newnode
        SListNode *prev = *pplist;
        while (prev->next != pos) {
            prev = prev->next;
        }
        SListNode *newnode = BuySListNode(x);
        newnode->next = prev->next;
        prev->next = newnode;
    }
}

// 删除pos之后结点
void SListEraseAfter(SListNode *pos) {
    assert(pos);
    if (pos->next == NULL) {
        return;
    } else {
        // 记录pos的后一个结点
        SListNode *nextnode = pos->next;
        pos->next = nextnode->next;
        free(nextnode);
    }
}

// 删除pos位置结点
void SListErase(SListNode **pplist, SListNode *pos) {
    assert(pos);
    assert(*pplist);
    // 如果删除pos位置等于头结点，就相当于头删，不是的话就正常删除
    if (pos == *pplist) {
        SListPopFront(pplist);
    } else {
        SListNode *prev = *pplist;
        while (prev->next != pos) {
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
    }
}