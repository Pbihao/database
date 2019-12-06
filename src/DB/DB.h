//
// Created by pbihao on 11/22/19.
//

#ifndef DATABASE_DB_H
#define DATABASE_DB_H

#include <string>
#include <vector>
#include <cstdio>
#include "book.h"
#include "binary_tree.h"
#include "../indexes/search.h"
#include "../cache/pool.h"
using namespace std;

class DB {
public:
    int size;
    vector<Book> arry;
    Binary_tree binaryTree;
    Search_engine searchEngine;
    Pool pool;


};


#endif //DATABASE_DB_H
