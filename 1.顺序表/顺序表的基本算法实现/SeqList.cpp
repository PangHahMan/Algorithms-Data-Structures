#include "SeqList.h"
void Test1()
{
    struct SeqList s1;
    SeqListInit(&s1);
    SeqListPushBack(&s1, 1);
    SeqListPushBack(&s1, 2);
    SeqListPushBack(&s1, 3);      
    SeqListPushBack(&s1, 4);
    SeqListPopFront(&s1);
    SeqListPopFront(&s1);
    SeqListPopBack(&s1);
    SeqListPopBack(&s1);
    SeqListPushFront(&s1, 0);
    SeqListPushFront(&s1, -1);
    SeqListInsert(&s1,1,61);  //下标为1插入一个6
    SeqListInsert(&s1,2,62);  //下标为1插入一个6
    SeqListInsert(&s1,3,63);  //下标为1插入一个6
    SeqListInsert(&s1,4,64);  //下标为1插入一个6
    SeqListErase(&s1, 1);
    SeqListErase(&s1, 1);
    SeqListErase(&s1, 1);
    SeqListErase(&s1, 1);
    SeqListPrint(&s1);  //-1 0 1 2 3 4
    SeqListDestroy(&s1);
}

int main()
{
    Test1();
    return 0;
}