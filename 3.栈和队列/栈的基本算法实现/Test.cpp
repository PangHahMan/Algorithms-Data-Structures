#include "Stack.h"
int main()
{
    Stack st;
    StackInit(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);
    StackPush(&st, 5);
    printf("%d", StackTop(&st));
    StackDestroy(&st);
    return 0;
}