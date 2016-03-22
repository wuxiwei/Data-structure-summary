#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct node {char data;
                    struct node *lchild,
                                *rchild;
}BTNode;

typedef BTNode * DataType;
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

void preorder(BTNode *t){
    //先序遍历二叉树的递归算法
    if(t != NULL){
        printf("%c\t", t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void preorder1(BTNode *t){
    //先序遍历二叉树的非递归算法
    SeqStack *st;
    BTNode *p;
    if(t == NULL) return;
    st = createemptystacks();
    p = t;
    do{
        while( p ){
           printf("%c\t", p->data);
           if(p->rchild) pushs(st, p->rchild);
           p = p->lchild;
        }
        if(!stackemptys(st)){
        p = gettops(st);
        pops(st);
    }
            
  }while(!stackemptys(st) || p);
}

void inorder(BTNode *t){
    //中序遍历二叉树的递归算法
    if(t != NULL){
        preorder(t->lchild);
        printf("%c\t", t->data);
        preorder(t->rchild);
    }
}

void inorder1(BTNode *t){
    //中序遍历二叉树的非递归算法
    
}
void posorder(BTNode *t){
    //后序遍历二叉树的递归算法
    if(t != NULL){
        preorder(t->lchild);
        preorder(t->rchild);
        printf("%c\t", t->data);
    }
}

BTNode * createbintree(){
    //基于先序遍历构造二叉树
    BTNode *t;
    char x;
    scanf("%c", &x);
    if(x == '#') t=NULL;
    else{
        t = (BTNode *)malloc(sizeof(BTNode));
        t->data = x;
        t->lchild = createbintree();
        t->rchild = createbintree();
    }
    return t;
}

int leaf(BTNode *t, int n){
    //计算叶子结点数
    if(t != NULL){
        if(t->lchild == NULL && t->rchild == NULL){
            n++;
        }
        n = leaf(t->lchild, n);
        n = leaf(t->rchild, n);
    }
    return n;
}

int high(BTNode *t){
    //求树高
    int h, lh, rh;
    if(t == NULL) h = 0;
    else{
        lh = high(t->lchild);
        rh = high(t->rchild);
        h = lh>rh ? lh+1 : rh+1;
    }
}

int main(){
    int n = 0; 
    int h = 0;
    BTNode *t = createbintree();
    preorder1(t);
    printf("\n");
    n = leaf(t, n);
    printf("%d", n);
    printf("\n");
    h = high(t);
    printf("%d", h);
    printf("\n");
    return 0;
}
