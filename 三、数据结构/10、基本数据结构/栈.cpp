#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
    STDataType *arr; // 起始指针
    int capacity;    // 栈的空间大小
    int top;         // 有效数据的个数
} ST;

// 初始化
void STInit(ST *ps);

// 销毁
void STDestroy(ST *ps);

// 判空
bool STEmpty(ST *ps);

// 压栈
void STPush(ST *ps, STDataType n);

// 出栈
void STPop(ST *ps);

// 取栈顶元素
STDataType STTop(ST *ps);

// 初始化
void STInit(ST *ps)
{
    assert(ps); // 防止传空指针
    ps->arr = NULL;
    ps->capacity = ps->top = 0;
}

// 销毁
void STDestroy(ST *ps)
{
    assert(ps);          // 防止传空
    if (ps->arr != NULL) // 防止多次free
    {
        free(ps->arr);
    }
    ps->arr = NULL;
    ps->capacity = ps->top = 0;
}

// 判空
bool STEmpty(ST *ps)
{
    assert(ps);
    return ps->top == 0;
}

// 压栈
void STPush(ST *ps, STDataType n)
{
    assert(ps);
    if (ps->capacity == ps->top) // 若空间不够，则增容
    {
        int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        STDataType *tmp = (STDataType *)realloc(ps->arr, NewCapacity * sizeof(STDataType));
        if (tmp == NULL) // 内存申请失败，则直接退出程序
        {
            perror("realloc");
            exit(1);
        }
        ps->arr = tmp; // 成功则让arr指向申请好的空间
        ps->capacity = NewCapacity;
    }
    ps->arr[ps->top++] = n; // 在栈顶插入数据
}

// 出栈
void STPop(ST *ps)
{
    assert(ps);
    assert(!STEmpty(ps)); // 确保栈不为空
    ps->top--;
}

// 取栈顶元素
STDataType STTop(ST *ps)
{
    assert(ps && !STEmpty(ps));
    return ps->arr[ps->top - 1]; // 栈顶top-1的位置即为栈顶元素
}

// 测试函数
int main()
{
    ST stack;

    // 初始化栈
    STInit(&stack);
    printf("栈初始化完成\n");

    // 测试栈是否为空
    printf("栈是否为空: %s\n", STEmpty(&stack) ? "是" : "否");

    // 压栈测试
    printf("\n压栈测试:\n");
    STPush(&stack, 1);
    printf("压入: 1\n");
    STPush(&stack, 2);
    printf("压入: 2\n");
    STPush(&stack, 3);
    printf("压入: 3\n");

    // 测试栈是否为空
    printf("栈是否为空: %s\n", STEmpty(&stack) ? "是" : "否");

    // 获取栈顶元素
    printf("\n栈顶元素: %d\n", STTop(&stack));

    // 出栈测试
    printf("\n出栈测试:\n");
    printf("出栈: %d\n", STTop(&stack));
    STPop(&stack);

    printf("出栈: %d\n", STTop(&stack));
    STPop(&stack);

    printf("出栈: %d\n", STTop(&stack));
    STPop(&stack);

    // 测试栈是否为空
    printf("栈是否为空: %s\n", STEmpty(&stack) ? "是" : "否");

    // 销毁栈
    STDestroy(&stack);
    printf("\n栈销毁完成\n");

    return 0;
}