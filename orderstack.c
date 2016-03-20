#include<stdio.h>
#define MAX 100
typedef int DataType;
typedef struct {
    DataType data[MAX];
    int top;
}SeqStack;

int main(){
    return 1;
}

SeqStack * createemptystacks(){
    //创建一个空栈
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = 0;
    return s;
}

int stackemptys(SeqStack *s){
    //判断为空
    return->top == 0;
}

int stackfulls(SeqStack *s){
    //判断栈满
    return s->top == MAX;
}

void pushs(SeqStack *s, DataType x){
    //进栈
    if(stackfulls){
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
