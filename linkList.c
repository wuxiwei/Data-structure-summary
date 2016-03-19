#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node{
    int data;
    struct node *link;
}LNode;

LNode * locatenode(LNode *h, int x);
void insertlist(LNode *p, int x);
void deletelist(LNode *p);
LNode * createfirst();
LNode * createtail();
void delete(LNode *h, int x);
void insertb1(LNode *h, int a, int b); //在头指针为h的带表头结点的单链表中结点a之前插入结点b，若无结点a，则插入到表尾。方法一
void insertb2(LNode *h, int a, int b); //在头指针为h的带表头结点的单链表中结点a之前插入结点b，若无结点a，则插入到表尾。方法二
void showlist1(LNode *h);
void showlist2(LNode *h); 
void invert(LNode *h);
LNode * margelist1(LNode *pa, LNode *pb); //将两个升序排列的单链表（不带头指针）合并为一个按升序排列的单链表，方法一：不使用第三条链表空间
LNode * margelist2(LNode *pa, LNode *pb); //将两个升序排列的单链表（不带头指针）合并为一个按升序排列的单链表，方法一：使用第三条链表空间

int main(){
    LNode *pa, *pb, *pc;
    /* h = createfirst(); */
    /* h = createtail(); */
    /* showlist2(h); */
    /* delete(h, 4);   //删除结点值为4的结点 */
    /* showlist2(h); */
    /* insertb1(h, 5, 7); */
    /* insertb2(h, 5, 7); */
    /* showlist2(h); */
    /* invert(h); */
    /* showlist2(h); */
    clock_t begin, duration;

    pa = createfirst();
    pb = createfirst();

    begin = clock();    //开始时间
    pc = margelist1(pa, pb);
    showlist1(pc);

    duration = clock() - begin;    //结束时间
    printf( "运行时间大约为：%f\n", duration );
    return 0;
}

void showlist1(LNode *h){
    //输出不带头结点的链表
    while ( h ) {
        printf("%d\t",h->data);
        h = h->link;
    }
    printf("\n");
}

void showlist2(LNode *h){
    //输出带头结点的链表
    while ( h->link ) {
        printf("%d\t",h->link->data);
        h = h->link;
    }
    printf("\n");
}

LNode * locatenode(LNode *h, int x){
    //在头指针为h的单链表中查找节点x
    LNode *p;
    p = h;
    while ( p != NULL && p->data != x ) {
        p = p->link;
    }
    return p;
}

void insertlist(LNode *p, int x){
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->data=x;
    s->link = p->link;   //将s指向p节点的后继结点
    p->link = s;   //将p节点指向s结点
}

void deletelist(LNode *p){
    //在单链表中删除p结点的直接后继结点
    LNode *q;
    if(p->link != NULL){
        q = p->link;
        p->link = q->link;
        free(q);
    }
}

LNode * createfirst(){
    //前插法建立单链表
    LNode *s, *h;
    int x, tag;
    printf("输入结束标志：");
    scanf("%d", &tag);
    h = NULL;
    printf("输入数据：");
    scanf("%d", &x);
    while(x != tag){
        s = (LNode *)malloc(sizeof(LNode));   //申请空间
        s->data = x;  //赋值
        s->link = h;   //键指针指向头结点
        h = s;   //将头结点指向s
        scanf("%d", &x);   //继续接收输入的值
    }
    return h;
}

LNode * createtail(){
    //尾插法建立带头结点的单链表
    LNode *s, *h, *r;
    int x, tag;
    printf("请输入结束标志：");
    scanf("%d", &tag);
    h = (LNode *)malloc(sizeof(LNode));    //头结点
    h->data = tag;
    r = h;
    printf("输入元素x：");
    scanf("%d", &x);
    while(x != tag){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->link = s;
        r = s;
        scanf("%d", &x);
    }
    r->link = NULL;
    return h;
}

void delete(LNode *h, int x){
    //在带头结点的单链表h中的删除所有数据域值为x的结点
    LNode *s;
    while(h->link){
        if(h->link->data == x){
            s = h->link;
            h->link = s->link;
            free(s);
        }else{
            h = h->link;
        }
    }
}

void insertb1(LNode *h, int a, int b){
    //在头指针为h的带表头结点的单链表中结点a之前插入结点b，若无结点a，则插入到表尾。方法一
    LNode *p, *q, *s;
    s = (LNode *)malloc(sizeof(LNode *));
    s->data = b;
    p = h->link;q = h;
    while(p->data != a&&p->link != NULL){
        q = p;
        p = p->link;
    }
    if(p->data == a){
        q->link = s; s->link = p;
    }else{
        p->link = s;
        s->link = NULL;
    }
}

void insertb2(LNode *h, int a, int b){
    //在头指针为h的带表头结点的单链表中结点a之前插入结点b，若无结点a，则插入到表尾。方法二
    LNode *p, *q, *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->data = b;
    p = h->link;
    while(p->link != NULL){
        if(p->link->data == a){
            q = p->link;
            s->link = q; p->link = s;
            break;
        }
        p = p->link;
    }
    if(p->link == NULL){
        p->link = s; s->link = NULL;
    }
}

void invert(LNode *h){
    //带头结点的逆表的实现
    LNode *p, *s;
    p = h->link;
    h->link = NULL;
    while ( p != NULL ) {
       s = p;
       p = p->link;
       s->link = h->link;
       h->link = s;
    }
}

void deleteprint(LNode *h){
    //按升序打印h为头指针的单链表中各结点的值，并将打印完的节点从表中删除
    LNode *q, *p, *p1, *q1;
    while ( h != NULL ) {
        q = p = q1 = h;
        p1 = p->link;
        while ( p1 != NULL ) {
            if(p1->data < p->data){
                p=p1; q=q1;
                q1 = p1;
                p1 = p1->link;
            }
            if(p == h) h = h->link;
            else q->link=p->link;
            free(p);
        }
    }
}

LNode * margelist1(LNode *pa, LNode *pb){
    //将两个升序排列的单链表（不带头指针）合并为一个按升序排列的单链表，方法一：不使用第三条链表空间
    showlist1(pa);
    showlist1(pb);
    LNode *p, *q, *h;
    h = q = pb;
    while(pa != NULL && pb != NULL){
        p = pa;
        if(p->data < pb->data){
            pa = pa->link;
            p->link = pb;
            if(pb == q){ q = pb = p; h = pb;}
            else q->link = p;
        }else{
            q = pb;
            pb = pb->link;
        }
    }
    if(pb == NULL){
        q->link = pa;
    }
    return h;
}

LNode * margelist2(LNode *pa, LNode *pb){
    //将两个升序排列的单链表（不带头指针）合并为一个按升序排列的单链表，方法一：使用第三条链表空间
    showlist1(pa);
    showlist1(pb);
    LNode *p, *q, *pc;
    pc = (LNode *)malloc(sizeof(LNode));
    p = pc;
    while(pa != NULL && pb != NULL){
        q = (LNode *)malloc(sizeof(LNode));
        if(pb->data < pa->data){
            q->data = pb->data;
            pb = pb->link;
        }else{
            q->data = pa->data;
            if(pa->data == pb->data) pb = pb->link;
            pa = pa->link;
        }
        p->link = q;
        p = q;
    }
    if(pa == NULL){
        pa = pb;
    }
    while(pa != NULL){
        q = (LNode *)malloc(sizeof(LNode));
        q->data = pa->data;
        pa = pa->link;
        p->link = q;
        p = q;
    }
    p->link = NULL;
    p = pc;
    pc = p->link;
    free(p);
    return pc;
}
