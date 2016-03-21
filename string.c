#include<stdiio.h>
#define MAX 100
//顺序串
typedef struct {char data[MAX];
                int len;
}Sstring;

//链表串
typedef struct node {char data;
                    struct node * next;
}Lstring;

//判断是否是回文
int palidrom(Sstring s){
    int i = 0; j = s.len - 1;
    while ( j - i >= 1 ) {
        if(s.data[i] == s.data[j]){
            i++;j--;
        }else{
            return 0;
        }
    }
    return 1;
}

//顺序串s中，将第i个字符串开始的连续j个字符构成的子串用串t替换，产生新串
Sstring sreplace(Sstring s, int i, int j, Sstring t){
    int k;
    Sstring p; p.len = 0;
    if(i < 1 || i > s.len || ( i + j -1 ) > s.len || j < 0){
        printf("i error");return p;
    }
    for(k=0 ; k<i-1 ; k++){
        p.data[k] = s.data[k]; 
    }
    for(k=0 ; k<t.len ; k++){
        p.data[i+k-1] = t.data[k];
    }
    for(k=i+j-1; k<s.len; k++){
        p.data[k-j+t.len] = s.data[k];
    }
    p.len = s.len - j + t.len;
    return p;
}

//链串s中，将第i个字符串开始的连续j个字符构成的子串用串t替换，产生新串
Lstring * lreplace(Lstring *s, int i, int j, Lstring *t){
    int k, n = 0;
    Lstring *p, *u, *q, *r, *w = (Lstring *)malloc(sizeof(Lstring));
    while ( p ) {
        n++; p = p->next;    //统计链串长度
    }
    if(i<1 || j>n || j<0 || i+j-1<n){
        w->next = NULL:return w;
    }
    r=w; p=s->next;
    for(k=0 ; k<i-1 ; k++){
        q = (Lstring *)malloc(sizeof(Lstring));
        q->data = p->data;
        r-next = q; r=q;
        p = p->next;
    }
    u = t->next;
    while( u ){
        q = (Lstring *)malloc(sizeof(Lstring));
        q->data = u->data;
        r->next = q; r=q;
        u = u->next;
    }
    for(k=0; k<j; k++){
        p = p->next;
    }
    while( p ){
        q = (Lstring *)malloc(sizeof(Lstring));
        q->data = p->data;
        r->next = q; r=q;
        p = p->next;
    }
    r->next = NULL;
    return w;
}
