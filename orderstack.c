//栈练习
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef int DataType;
typedef struct {
    DataType data[MAX];
    int top;
}SeqStack;


SeqStack * createemptystacks(){
    //创建一个空栈
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = 0;
    return s;
}

int stackemptys(SeqStack *s){
    //判断为空
    return s->top == 0;
}

int stackfulls(SeqStack *s){
    //判断栈满
    return s->top == MAX;
}

void pushs(SeqStack *s, DataType x){
    //进栈
    if(stackfulls(s)){
        printf("over flow\n");
    }else{
        s->data[s->top++] = x;   //先赋值，后加
    }
}

void pops(SeqStack *s){
    //退出栈
    if(stackemptys(s)){
        printf("underflow");
    }else{
        s->top--;
    }
}

DataType gettops(SeqStack *s){
    //栈非空时，取栈顶元素
    return s->data[s->top-1];
}

//判断字符串中{[()]}是否正确配对
int expcorre(char *b){
    char S[100]; int i, top = 0, tag = 1;
    for(i = 0; tag&&b[i]!= '\0'; i++){
        switch ( b[i] ) {
            case '(':
                S[top++] = ')';break;
                break;
            case '[':
                S[top++] = ']';break;
                break;
            case '{':
                S[top++] = '}';break;
                break;
            case ')':
            case ']':
            case '}':
                if(top == 0 || b[i] != S[--top]){
                    tag = 0;
                }
        }
    }
    return tag&&b[i] == '\0';
}

//num为无符号的十进制整数，写一个非递归的算法，依次输出对应的r进制数的各位数字
void conver(int num, int r){
    int S[100], top = 0;
    while ( num ) {
        S[top++] = num % r;
        num = num / r;
    }
    while ( top > 0 ) {
        printf("%d", S[--top]);
    }
}

//num为无符号的十进制整数，写一个递归的算法，依次输出对应的r进制数的各位数字
void conver2(int num, int r){
    if(num == 0){
        printf("\n");
    }else{
        printf("%d", num%r);
        conver2(num/r,r);
    }
}

int main(){
    conver2(1000,2);
    return 1;
}
