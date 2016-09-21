#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node{
	char data;
	struct node *lchild;
	struct node *rchild;
}BiNode, *BiTree;

typedef struct  node1{
	BiTree data[30];
	int top;
}Stack;

void createTree(BiTree &T){
	char ch;
	cin.get(ch).get();
	if(ch==' ')T=NULL;
	else{
		T = (BiTree)malloc(sizeof(BiNode));
		T->data = ch;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}

void initstack(Stack *&st){
	st=(Stack *)malloc(sizeof(Stack));
	st->top = -1;
}

bool isempty(Stack *st){
	return st->top == -1;
}

bool isfull(Stack *st){
	return st->top == 19;
}

void push(Stack *st, BiTree T){
	if(!isfull(st)){
		st->data[++st->top] = T;
	}else{
		cout << "已满" <<endl; 
	}
}

BiTree pop(Stack *st){
	if(!isempty(st)){
		return st->data[st->top--];
	}
}

BiTree gettop(Stack *st){
	if(!isempty(st)){
		return st->data[st->top];
	}
}

//前序遍历
void preOrderNoRe(BiTree T){
	Stack *st;
	initstack(st);
	BiTree p;
	p = T;
	while(p!=NULL||!isempty(st)){
		while(p!=NULL){
			cout<<p->data<<" ";
			push(st, p);
			p=p->lchild; 
		}
		if(!isempty(st)){
			p = pop(st);
			p=p->rchild;
		} 
	}
}

//先序遍历递归
void preOrder(BiTree T){
	if(T != NULL){
		cout << T->data << " ";
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
} 

//中序遍历
void inOrderNoRe(BiTree T){
	Stack *st;
	initstack(st);
	BiTree p;
	p = T;
	while(p!=NULL||!isempty(st)){
		while(p!=NULL){
			push(st, p);
			p=p->lchild; 
		}
		if(!isempty(st)){
			p = pop(st);
			cout<<p->data<<" ";
			p=p->rchild;
		} 
	}
}

//中序遍历递归
void inOrder(BiTree T){
	if(T != NULL){
		inOrder(T->lchild);
		cout << T->data << " ";
		inOrder(T->rchild);
	}
} 

//后续遍历
void postOrderNoRe(BiTree T){
	BiTree p;
	Stack *st;
	initstack(st);
	p = T;
	int Tag[20];	//栈，用于标识从左0或从右1返回
	while(p!=NULL || !isempty(st)){
		while(p!=NULL){
			push(st, p);
			Tag[st->top] = 0;
			p=p->lchild;
		}
		
		while(!isempty(st)&&Tag[st->top] == 1){
			p=pop(st);
			cout<<p->data<<" ";
		}
		if(!isempty(st)){
			Tag[st->top] = 1;	//设置标记右子树已经访问
			p=gettop(st);
			p=p->rchild; 
		}else{
			break;
		}
		
	} 
} 

//后序遍历递归
void postOrder(BiTree T){
	if(T != NULL){
		postOrder(T->lchild);
		postOrder(T->rchild);
		cout << T->data << " ";
	}
} 

int main(){
	cout<<"Enter char one by one"<<endl;
	BiNode *T;
	createTree(T);
	cout<<endl;
	cout<<"preOrderNoRe:";preOrderNoRe(T);cout<<endl;cout<<"preOrder:";preOrder(T);cout<<endl;
	cout<<"inOrderNoRe:";inOrderNoRe(T);cout<<endl;cout<<"inOrder:";inOrder(T);cout<<endl;
	cout<<"postOrderNoRe:";postOrderNoRe(T);cout<<endl;cout<<"postOrder:";postOrder(T);cout<<endl;
}
