//
// Created by 杜玮玲 on 2019-12-06.
//

#ifndef DATABASE_QUEUE_H
#define DATABASE_QUEUE_H

#include "../DB/book.h"

class Queue {
    /*定义队列结点的数据结构*/
    struct QNode{
        QNode *next; // 指针域，指向下一个结点
        Book data; //数据域，存储队列信息
    };

    /*定义队列的数据结构*/
    struct LinkQueue {
        int queue_size;
        QNode *front; //队首指针，指向QNode类型的指针
        QNode *rear; //队尾指针
    };

public:
    LinkQueue books;

    /*构造一个空的队列*/
    void InitQueue(LinkQueue &Q);

    /*判断队列是否为空，空则返回1*/
    int IsEmpty(LinkQueue &Q);

    /*从队列尾部插入一个结点*/
    void EnQueue(LinkQueue &Q, Book e);

    /*从队列首部删除一个结点*/
    void DeQueue(LinkQueue &Q, Book &e);





    /*判断队列是否满，满则返回1*/
    int IsEnough(LinkQueue &Q);
};


/*构造一个空的队列*/
void Queue::InitQueue(LinkQueue &Q){
    Q.queue_size = 0;
    QNode *q;
    q = new QNode;
    q->next = NULL;
    Q.front = q;
    Q.rear = q;
}

/*判断队列是否为空，空则返回1*/
int Queue::IsEmpty(LinkQueue &Q){
    if(Q.rear == Q.front)
        return 1;
    else
        return 0;
}

/*从队列尾部插入一个结点*/
void Queue::EnQueue(LinkQueue &Q, Book e){
    Q.queue_size++;
    QNode *p;
    p = new QNode;
    p->next = NULL;
    p->data = e;
    Q.rear->next = p;
    Q.rear = p;
}

/*从队列首部删除一个结点*/
void Queue::DeQueue(LinkQueue &Q, Book &e){
    Q.queue_size--;
    QNode *p;
    p = Q.front->next;
    e = p->data; //保存要出队列的数据
    Q.front->next = p->next;
    if(Q.rear == p) //如果删除的元素即为尾结点，则将头指针赋予尾指针，一同指向头
        Q.rear = Q.front;
    delete p;
}

/*判断队列是否满*/
int Queue::IsEnough(LinkQueue &Q){
    if(Q.queue_size == 20){
        return 1;
    }else{
        return 0;
    }
}
#endif //DATABASE_QUEUE_H
