#include "SList.h"
// ��̬����һ���ڵ�
SListNode *BuySListNode(SLDataType x) {
    SListNode *newnode = (SListNode *) malloc(sizeof(SListNode));//����ռ�
    if (newnode == NULL) {
        perror("malloc fail");
        exit(-1);
    } else {
        newnode->data = x;   //�����ݸ�ֵ���½���������
        newnode->next = NULL;//���½���ָ�����ÿ�
        return newnode;
    }
}

// ����n�����
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

// �������ӡ
void SListPrint(SListNode *plist) {
    // ����assert  ������ΪNULL ��ӡNULL����
    SListNode *cur = plist;//����ͷָ��
    while (cur)            // cur!=NULL
    {
        printf("%d->", cur->data);
        cur = cur->next;//���½��,����һ�����
    }
    printf("NULL\n");
}

// ������β��
void SListPushBack(SListNode **pplist, SLDataType x) {
    SListNode *newnode = BuySListNode(x);
    //�������ΪNULL,��ô�²���Ľ�����ͷ���
    if (*pplist == NULL) {
        *pplist = newnode;
    } else {
        //���������Ľ��
        SListNode *tail = *pplist;
        while (tail->next)// ע�⣺����������һ������β���ǰһ�����Ҫ����next
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

// �������ͷ��
void SListPushFront(SListNode **pplist, SLDataType x) {
    SListNode *newnode = BuySListNode(x);//����һ���½��
    // ͷ�岻���ж��Ƿ�Ϊ�գ����Ϊ�գ���ônewnode->next��Ϊ��
    newnode->next = *pplist;//�½��ָ��ͷ���
    *pplist = newnode;      //�ڸ���ͷ���
}

// βɾ
void SListPopBack(SListNode **pplist) {
    assert(*pplist);
    // �����������һ��ָ���һ����һ��ָ��ڶ�������Ϊɾ�����Ҫ�ҵ�ǰһ������next��ֵ
    SListNode *prev = NULL;
    SListNode *tail = *pplist;
    // 1.ֻ��һ���ڵ�
    // 2.���������ϵĽڵ�
    if (tail->next == NULL) {
        free(tail);
        *pplist = NULL;
    } else {
        while (tail->next)// �����һ�����Ϊ�գ���ɾ����ǰ��㣬�ڽ�prev����next��ֵΪNULL
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;
    }
}

// ͷɾ
void SListPopFront(SListNode **pplist) {
    assert(*pplist);
    // ΪNULLֱ��assert����Ϊ��ֱ�ӽ�ͷ���ɾ������һ�������ͷ���
    SListNode *nextnode = (*pplist)->next;
    free(*pplist);
    *pplist = nextnode;
}

// ���������
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

// �����������
void SListDestroy(SListNode **pplist) {
    SListNode *cur = *pplist;
    while (cur) {
        SListNode *nextnode = cur->next;
        free(cur);
        cur = nextnode;
    }
    *pplist = NULL;
}

// x���뵽posλ��֮��
void SListInsertAfter(SListNode *pos, SLDataType x) {
    // pos����ΪNULL
    assert(pos);
    SListNode *newnode = BuySListNode(x);
    // ���������½����뵽pos֮��
    newnode->next = pos->next;
    pos->next = newnode;
}

// x���뵽posλ��֮ǰ
void SListInsert(SListNode **pplist, SListNode *pos, SLDataType x) {
    assert(pos);
    // ���pos��λ����ͷ����λ�ã��߼���Ϊͷ�壬����Ͳ��뵽ǰ��
    if (*pplist == pos) {
        SListPushFront(pplist, x);
    } else {
        // ����һ����ʼ�Ľ��,Ȼ���ж�prev��next�Ƿ�Ϊpos  �ǵĻ���������prev��newnode
        SListNode *prev = *pplist;
        while (prev->next != pos) {
            prev = prev->next;
        }
        SListNode *newnode = BuySListNode(x);
        newnode->next = prev->next;
        prev->next = newnode;
    }
}

// ɾ��pos֮����
void SListEraseAfter(SListNode *pos) {
    assert(pos);
    if (pos->next == NULL) {
        return;
    } else {
        // ��¼pos�ĺ�һ�����
        SListNode *nextnode = pos->next;
        pos->next = nextnode->next;
        free(nextnode);
    }
}

// ɾ��posλ�ý��
void SListErase(SListNode **pplist, SListNode *pos) {
    assert(pos);
    assert(*pplist);
    // ���ɾ��posλ�õ���ͷ��㣬���൱��ͷɾ�����ǵĻ�������ɾ��
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