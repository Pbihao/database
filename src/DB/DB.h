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
#include "../algor/sort_times.h"
using namespace std;

class DB {
public:
    int size;
    vector<Book> arry;
    vector<int> arry_ID;
    Binary_tree binaryTree;
    Search_engine searchEngine;
    Pool pool;

    //向数据库加入很多本书
    void insert_books(const vector<Book>& books);
    //向数据库中加入一本书
    void insert(Book book);
    //向数据库修改一本书的信息
    void  update(Book book);
    //数据库中删除一本书
    void erase(Book book);
    //提供ID查找一本书的信息
    Book find_by_ID(int ID);
    //给出一个书名进行搜索,返回最接近的十个答案
    void search(string search_name);
    //找到被借阅次数最多的十本书
    void find_max_borrowed();
};

void DB::insert_books(const vector<Book>& books){
        for(const auto& book: books){
            binaryTree.insert(book);
            searchEngine.insert(book);
            size++;
        }
};

void DB::insert(Book book) {
    size++;
    binaryTree.insert(book);
    searchEngine.insert(book);
}

void DB::erase(Book book) {
    size--;
    binaryTree.erase(book.get_ID());
    searchEngine.erase(book);
}

void DB::update(Book book) {
    searchEngine.erase(binaryTree.query(book.get_ID()));
    binaryTree.replace(book.get_ID(), book);
    searchEngine.insert(book);
}

Book DB::find_by_ID(int ID) {
    return binaryTree.query(ID);
}

void DB::search(string search_name) {
    arry_ID.clear();
    arry.clear();
    searchEngine.search(search_name, arry_ID);
    for(const auto x: arry_ID)arry.push_back(binaryTree.query(x));
}

void DB::find_max_borrowed() {
    arry.clear();
    binaryTree.run(arry);
    sort_times(arry);
}

#endif //DATABASE_DB_H
