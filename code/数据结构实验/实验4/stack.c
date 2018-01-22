#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE  100
static char stack[MAX_SIZE];
static int top = -1;

#define IS_empty()    (top == -1)
#define IS_full()     (top == (MAX_SIZE - 1))
#define Push(x)    stack[++top] = (x)
#define Pop()    (stack[top--])


// 获取优先级
int get_priority(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '(':
            return -1;
            break;
        case ')':
            return 3;
            break;
        default:
            return 0;
            break;
    }
}

// 处理操作符
void deal_operator(char ch)
{

    char temp = ' ';
    while (!IS_empty() && get_priority(temp = Pop()) >= get_priority(ch))
    {
        printf("%c", temp);
    }
    if (temp != ' ' && get_priority(temp) < get_priority(ch))
    {
        Push(temp);
    }
    Push(ch);
}

// 处理括号
void deal_brackets(char brackets)
{
    if (brackets == '(')
    {
        Push(brackets);
    }
    else
    {
        char temp = '(';
        while (!IS_empty() && get_priority(temp = Pop()) != -1)
        {
            printf("%c", temp);
        }

        if (temp != '(')
        {
            Push(temp);
        }
    }
}

// 处理数字
void deal_number(char number)
{
    if ((int)number >= 48 && (int)number <= 57)
        printf("%c", number);
    else
    {
        printf("your enter is wrong.\n");
        exit(0);
    }

}

void print_stack()
{
    while (!IS_empty())
        printf("%c", Pop());
}

void convert_infix_to_postfix(char* str, int len)
{
    for (int i = 0; i < len; ++i)
    {
        switch (str[i])
        {
            case '+':
            case '-':
            case '*':
            case '/':
                deal_operator(str[i]);
                break;
            case '(':
            case ')':
                deal_brackets(str[i]);
                break;
            default:
                deal_number(str[i]);
                break;
        }
    }
    print_stack();

}

int main(int argc, char const *argv[])
{
    char test[] = "1+2*3+(4*5+6)*7";
    convert_infix_to_postfix(test, 15);

}

