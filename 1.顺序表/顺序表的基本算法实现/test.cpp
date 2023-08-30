#include "SeqList.h"
void Test1() {
    struct SeqList s1;
    SeqListInit(&s1);
    SeqListPushBack(&s1, 1);
    SeqListPushBack(&s1, 2);
    SeqListPushBack(&s1, 3);
    SeqListPushBack(&s1, 4);
    SeqListPrint(&s1);//1 2 3 4
    SeqListPopFront(&s1);
    SeqListPopFront(&s1);
    SeqListPrint(&s1);//3 4
    SeqListPopBack(&s1);
    SeqListPopBack(&s1);
    SeqListPrint(&s1);//
    SeqListPushFront(&s1, 0);
    SeqListPushFront(&s1, -1);
    SeqListPrint(&s1);        //-1 0
    SeqListInsert(&s1, 1, 61);//下标为1插入一个61
    SeqListInsert(&s1, 2, 62);//下标为1插入一个62
    SeqListInsert(&s1, 3, 63);//下标为1插入一个63
    SeqListInsert(&s1, 4, 64);//下标为1插入一个64
    SeqListPrint(&s1);        //61 62 63 64 -1 0
    SeqListErase(&s1, 1);
    SeqListErase(&s1, 1);
    SeqListErase(&s1, 1);
    SeqListErase(&s1, 1);
    SeqListPrint(&s1);//-1 0
    SeqListDestroy(&s1);
}

int main() {
    Test1();
    return 0;
}