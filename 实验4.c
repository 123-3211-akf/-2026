#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//定义结构体
#define MAX 100
    typedef struct {
        int top;//栈顶指针
        int data[MAX];//栈的存储空间
    } SqStack;
//初始化栈
    void InitStack(SqStack *S) {
        S->top = -1;
    }
//出栈
bool Pop(SqStack *S, int *x) //出栈 删除栈顶元素
{
        if (S->top == -1)
            return false; //栈空，出栈失败
        *x = S->data[S->top]; //让x等于栈顶元素
        S->top = S->top - 1; //栈顶指针往下移动一位
        return true; //出栈成功
    }
//入栈
bool Push(SqStack *S, int x) //入栈
{
        if (S->top == MAX - 1)
            return false; //栈满，入栈失败
        S->top = S->top + 1; //栈顶指针往上移动
        S->data[S->top] = x; //将x放入栈顶
        return true; //入栈成功
    }
//返回栈顶元素
bool GetTop(SqStack *S, int *x) //返回栈顶元素
{
        if (S->top == -1)
            return false; //栈空，返回失败
        *x = S->data[S->top]; //让x等于栈顶元素
        return true; //返回成功
    }
//输出栈中所有元素
void PrintStack(SqStack *S) {
        if (S->top == -1) {
            printf("栈为空\n");
            return;
        }
        printf("栈中元素为（栈顶->栈底）：");
        for (int i = S->top; i >= 0; i--) {
            printf("%d ", S->data[i]);
        }
        printf("\n");
    }
//销毁栈
void DestroyStack(SqStack *S) {
        S->top = -1; //将栈顶指针置为-1，表示栈为空
    }


  //主函数
int main() {
    SqStack S;
    InitStack(&S); //初始化栈
    int choice, x;

    printf("1.入栈  2.出栈  3.取栈顶元素  4.输出栈中所有元素  0.退出\n");
    while (1) {
        printf("请选择操作：");
        scanf("%d", &choice);
        switch (choice) {
        case 1: //入栈
            printf("请输入要入栈的元素：");
            scanf("%d", &x);
            if (Push(&S, x))
                printf("入栈成功：%d\n", x);
            else
                printf("栈满，入栈失败\n");
            break;
        case 2: //出栈
            if (Pop(&S, &x))
                printf("出栈元素为：%d\n", x);
            else
                printf("栈空，出栈失败\n");
            break;
        case 3: //取栈顶元素
            if (GetTop(&S, &x))
                printf("栈顶元素为：%d\n", x);
            else
                printf("栈为空，无法获取栈顶元素\n");
            break;
        case 4: //输出栈中所有元素
            PrintStack(&S);
            break;
        case 0: //退出
            DestroyStack(&S); //销毁栈
            printf("程序结束\n");
            return 0;
        default:
            printf("无效选择，请重新输入\n");
        }
    }
}
