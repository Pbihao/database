//
// Created by pbihao on 11/22/19.
//

#ifndef DATABASE_DB_H
#define DATABASE_DB_H

#include <string>
#include <vector>
#include "book.h"
#include "binary_tree.h"
#include "../indexes/search.h"
using namespace std;

class DB {
public:
    int size;
    vector<Book> arry;
    Binary_tree binaryTree;
    Search_engine searchEngine;
    //读入数据库里面所有的书籍信息
    void read_books(){
        return;
    }
    //写入数据库里面的所有信息
    void write_books(){
        return;
    }
};


#endif //DATABASE_DB_H
