//
// Created by 杜玮玲 on 2019-11-29.
//

#ifndef DATABASE_POOL_H
#define DATABASE_POOL_H

#include <string>
#include <vector>
#include "../DB/book.h"
#include "temp.h"
#include "queue.h"
#include "fileIO.h"
using namespace std;

class Pool {
public:
    Queue queue;
    Fileio operation;
    /*将books中的所有信息写入二进制文件books.dat*/
    void write_books(vector<Book>& books);

    /*从二进制文件中文件中读取图书信息到books中*/
    void read_books(vector<Book>& books);

    /*将要插入的书放入队列里*/
    void insert(Book book);

    /*将要删除的书放入队列里*/
    void erase(Book book);

    /*将要更新信息的书放入队列里*/
    void update(Book book);

    /*当系统关闭时，对队列中的书进行操作，无论队列是否满*/
    void quit();

    /*获得数据库最大id*/
    int readid();

};

void Pool::write_books(vector<Book>& books){
    operation.io_write_books(books);
}

void Pool::read_books(vector<Book>& books) {
    operation.io_read_books(books);
}

void Pool::insert(Book book){
    book.set_book();
    if(queue.IsEmpty(queue.books)){
        queue.InitQueue(queue.books);
        queue.EnQueue(queue.books, book);

    }else{
        queue.EnQueue(queue.books, book);
    }
    if(queue.IsEnough(queue.books)){
        operation.io_file_operation(queue);
    }
}

void Pool::erase(Book book){
    book.del_book();
    if(queue.IsEmpty(queue.books)){
        queue.InitQueue(queue.books);
        queue.EnQueue(queue.books, book);
    }else{
        queue.EnQueue(queue.books, book);
    }
    if(queue.IsEnough(queue.books)){
        operation.io_file_operation(queue);
    }
}

void Pool::update(Book book){
    book.update_book();
    if(queue.IsEmpty(queue.books)){
        queue.InitQueue(queue.books);
        queue.EnQueue(queue.books, book);
    }else{
        queue.EnQueue(queue.books, book);
    }
    if(queue.IsEnough(queue.books)){
        operation.io_file_operation(queue);
    }

}

void Pool::quit(){
    operation.io_file_operation(queue);
}

int Pool::readid() {
    operation.io_readid();
}
#endif //DATABASE_DB_H
