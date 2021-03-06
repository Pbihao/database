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
    int size, now_ID;
    vector<Book> arry;
    vector<int> arry_ID;
    Binary_tree binaryTree;
    Search_engine searchEngine;
    Pool pool;

    DB(){
        arry.clear();
        pool.read_books(arry);
        for(auto book: arry){
            binaryTree.insert(book);
            searchEngine.insert(book);
            size++;
        }


    }

    //向数据库加入很多本书
    void insert_books(vector<Book>& books);

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

    //从展示数据库的所有图书信息
    void show_book_info();

    //关闭数据库
    void quit();

    int readid();

};

void DB::insert_books(vector<Book>& books){
        for(const auto& book: books){
            binaryTree.insert(book);
            searchEngine.insert(book);
            size++;
            pool.insert(book);
        }
};

void DB::insert(Book book) {
    size++;
    binaryTree.insert(book);
    searchEngine.insert(book);
    pool.insert(book);
}

void DB::erase(Book book) {
    size--;
    binaryTree.erase(book.get_ID());
    searchEngine.erase(book);
    pool.erase(book);
}

void DB::update(Book book) {
    searchEngine.erase(binaryTree.query(book.get_ID()));
    binaryTree.replace(book.get_ID(), book);
    searchEngine.insert(book);
    pool.update(book);
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

void DB::show_book_info(){
    //pool.read_books(arry);
    binaryTree.run(arry);
}

void DB::quit() {
    pool.quit();
}

int DB::readid(){
    return pool.readlength();
}
#endif //DATABASE_DB_H
