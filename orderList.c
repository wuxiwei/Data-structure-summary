/*
 *顺序表结构简单，便于随机访问表中任意数据元素，但是插入和删除运不便，每进行一次插入或删除操作
 *平均移动约一半的数据元素。由于顺序表需要一组地址连续的存储单元，对于可变的线性表就需要预先分配足够的空间
 *有可能使一部分存储空间长期闲置不能充分利用，也可能估算不足，当表长超过预期的空间而造成溢出,又难于扩充连续的存储空间。
 */
#include<stdio.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int n;
}SList;
void creat(SList *L);//新建线性表
void show(SList *L);//显示线性表
int insert(SList *L, int x, int i);//第i个元素前插入数据元素x
int delete(SList *L, int i);//删除第i个元素
int main(){
    SList L;
    L.n = 0;
    creat(&L);
    show(&L);
    insert(&L, 14, 2);
    show(&L);
    delete(&L, 3);
    show(&L);
    return 0;
}

void creat(SList *L){
    int a;
    int i=0;
    printf("请输入要创建的元素的个数：\t");
    scanf("%d",&a);
    for(; i<a; i++){
        L->data[i] = i;
        L->n++;
    }
}

int delete(SList *L, int i){
    int j;
    if(i<i||i>L->n){
        printf("position error");
        return 0;
    }
    for(j=i;j<L->n;j++){
        L->data[j-1]=L->data[j];
    }
    L->n--;
    return 1;
}

int insert(SList *L, int x, int i){
    int j;
    if(L->n == MAX){
        printf("over flow\n");
        return 0;
    }
    if(i<1||i>L->n){
        printf("position error\n");
        return 0;
    }
    for(j=L->n;j>=i;j--){
        L->data[j]=L->data[j-1];
    }
    L->data[j]=x;
    L->n++;
    return 1;
}

void show(SList *L){
    int i=0;
    printf("线性表中的元素为：\n");
    for(; i<L->n; i++){
        printf("%d\t", L->data[i]);
    }
    printf("\n");
}
