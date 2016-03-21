//设计一个用前插法建立单链表h的算法
Lnode * create(int tag){
    Lnode *p, *h = NULL;
    printf("input x: ");
    scanf("%d",&x);
    while ( x != tag ) {
        p = (Lnode *)malloc(sizeof(Lnode));
        p->data = x;
        p->next = h;
        h = p;
        scanf("%d", x);
    }
    return h;
}

//设计在单链表h中查找第i个结点的算法
Lnode * search(Lnode *h, int i){
    int j = 0;
    while ( h ) {
        if(h->data == i){
            break;
        }
        h = h->next;
    }
    return h;
}

//设计在单链表h的第i个位置插入数据域值为x的结点的算法
Lnode * insertix(Lnode *h, int i, int x){
    Lnode *s, *p;
    s = (Lnode *)malloc(sizeof(Lnode));
    s->data = x;
    if(i == 1){
        s->next = h;
        h = s;
    }else{
        if(p){ //如果存在
            p = search(h, i-1);
            s->next = p->next;
            p->next = s;
        }else{
            free(s);
            printf("position i error");
        }
    }
    return h;
}

//设计在单链表h中删除第i个结点的算法
Lnode * deletei(Lnode *h, int i){
    Lnode *q, *p = h;
    if(!h){
        printf("list empty");
    }else{
        if(i == 1){
            h = h->next;
            free(p);
        }else{
            p = search(h, i-1);
            if(p){
                q = p->next;
                p->next = q->next;
                free(q);
            }else{
                printf("position i error");
            }
        }
    }
    return h;
}

//设计用尾插法建立带头结点的单链表h的算法
Lnode * createht(int tag){
    int x;
    Lnode *p, *r, *h = (Lnode *)malloc(sizeof(Lnode));
    r = h;
    printf("input x:");
    scanf("%d", &x);
    while( x != tag ){
        p = (Lnode *)malloc(sizeof(Lnode));
        p->data = x;
        r->next = p;
        scanf("%d", x);
    }
    r->next = NULL;
    return h;
}

//设计一个在带表头结点的单链表中删除所有结点x的算法
void deletex(Lnode *h, int x){
    Lnode *p, *q = h;
    while ( q&&q->next ) {
        if(p->next->data == x){
            q = p->next;
            p->next = q->next;
            free(q);
        }else{
            p = p->next;
        }
    }
}

//在带头结点的非空链表h中，p结点不是第一个结点，设计删除p结点的直接前驱结点。
//方案一
void deletepre1(Lnode *h,Lnode *p){
    Lnode *q = h;
    while ( q->next->next != p ) {
        q = q->next;
        p = q->next;
        q->next = p->next;
        free(p);
    }
}
//方案二
void deletepre2(Lnode *h,Lnode *p){
    Lnode *q = h->next;int x;
    while(q->next != p){
        q = q->next;
    }
    x = p->data;
    p->data = q->data;
    q->data = x;
    q->next = q->next;
    free(p);
}

//在带头结点的非空链表h中，p结点不是第一个结点，设计p结点之前插入x。
//方案一
void insertpre1(Lnode *h, Lnode *p, int x){
    Lnode *q = h, *s;
    while(q->next != p){
        q = q->next;
    }
    s = (Lnode *)malloc(sizeof(Lnode));
    s->data = x;
    s->next = p;
    q->next = s;
}
//方案二
void insertpre2(Lnode *h, Lnode *p, int x){
    Lnode *s = (Lnode *)malloc(sizeof(Lnode));
    int x1;
    s->data = x;
    s->next = p->next;
    p->next = s;
    x1 = s->data;
    s->data = p->data;
    p->data = x1;
}

//设计将两个从小到大排序的链表合并成一个从大到小排序的单链表。
Lnode * merge(Lnode *ha, Lnode *hb){
    Lnode *p, *q, *hc = NULL;
    while ( ha&&hb ) {
        if(ha->data < hb->data){
            p = ha;
            ha = ha->next;
        }else{
            p = hb;
            hb = hb->next;
        }
        p->next = hc;
        hc = p;
    }
    if(ha == NULL) ha = hb;
    while(ha){
        p = ha;
        ha = ha->next;
        p->next = hc;
        hc = p;
    }
    return hc;
}

//设计将带头结点的单链表中重复的值的结点删除
Lnode * delesame(Lnode *h){
    Lnode *p, *q, *r;
    p = h->next;
    while(p){
        q = p->next;
        r = p;
        while(q){
            if(q->data == p->data){
                r->next = q->next;
                free(q);
                q = r->next;
            }else{
                r = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}

//设有一个数据域值为整数的带表头结点的单链表h，设计将数据域为负数的结点链入到另一个带表头的结点的单链表中。且头结点
//的数据域存放表中的结点的个数
Lnode * split(Lnode *h){
    Lnode *hf, *p, *q = h->next;
    hf = (Lnode *)malloc(sizeof(Lnode));
    hf->next = NULL; hf->data = 0;
    h->next = NULL; h->data = 0;
    while ( p ) {
        q = p; p = p->next;
        if(q->data < 0){
            hf->data++;
            q->next = hf->next;
            hf->next = q;
        }else{
            h->data++;
            q->next = h->next;
            h->next = q;
        }
    }
    return hf;
}

//将单链表h就地逆置
Lnode * revelist(Lnode *h){
    Lnode *p, *q = NULL;
    while(h){
        p = h->next;
        h->next = q;
        q = h;
        h = p;
    }
    return q;
}

//在表长大于1的单循环链表中，查找p结点的直接前驱结点。
Lnode * prior(Lnode *p){
    Lnode *q = p->next;
    while ( q->next != p ) {
        q = q->next;
    }
    return q;
}

//带表头结点的双循环链表中，数据域从小到大顺序排序，将x插入该循环表中
void insertdx(DLnode *h, int x){
    DLnode *s, *p = h->next;
    s = (DLnode *)malloc(sizeof(DLnode));
    s->data = x;
    while( p != h ){
        if(p->data < x){
            p = p->next;
        }else{
            break;
        }
    }
    s->prior = p->prior;
    p->prior->next = s;
    p->prior = s;
    s->next = p;
}

//删除带表头结点的双向循环链表所有结点x;
void deletedx(DLnode *h, int x){
    DLnode *q, *p = h->next;
    while(p != h){
        q = p; p = p->next;
        if(q -> data == x){
            q->prior->next = p;
            p->prior = q->prior;
            free(q);
        }
    }
}

//带表头的双向循环链表，实现所有负数结点放到正数结点之前
void move(DLnode *h){
    DLnode *p = h->next; *q = h->prior;
    int x;
    while(p != q&&q->next != p){
        while(p->data < 0 && p != h){
            p = p->next;
        }
        while(q->data > 0 && q != h){
            q = q->prior;
        }
        if(p != q){
            x = p->data;
            p->data = q->data;
            q->data = x;
            p = p->next;
            q = q->prior;
        }
    }
}
