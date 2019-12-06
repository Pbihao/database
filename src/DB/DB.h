//
// Created by pbihao on 11/22/19.
//

#ifndef DATABASE_DB_H
#define DATABASE_DB_H

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "book.h"
#include "binary_tree.h"
#include "../indexes/search.h"
#include "temp.h"
using namespace std;

class DB {
public:
    int size;
    vector<Book> arry;
    Binary_tree binaryTree;
    Search_engine searchEngine;

    /*
     * 将books中的所有信息写入二进制文件books.dat
     * */
    void write_books(vector<Book>& books);

    /*
     * 从二进制文件中文件中读取图书信息到books中
     * */
    void read_books();

};

void DB::write_books(vector<Book>& books){
    int i, j;
    Temp temp;
    ofstream outFile("books.dat", ios::out|ios::binary);
    //将每一本书转为temp类再写入
    for(i=0;i<10;i++){
        temp.ID = books[i].get_ID();
        temp.state = books[i].get_state();
        temp.borrowing_times = books[i].borrowing_times;
        for(j=0;j<books[i].name.length();j++){
            temp.name[j] = books[i].name[j];
        }
        temp.name[j] = '\0';
        for(j=0;j<books[i].author.length();j++){
            temp.author[j] = books[i].author[j];
        }
        temp.author[j] = '\0';
        outFile.write((char*)&temp, sizeof(Temp));
    }
    outFile.close();
}

void DB::read_books() {
    int i;
    Temp temp;
    Book booktemp;
    ifstream inFile("books.dat", ios::in|ios::binary);
    if(!inFile){
        cout << "error" << endl;//文件打开错误
    }
    arry.clear();
    for(i=0;i<10;i++){
        inFile.read((char *)(&temp), sizeof(Temp));
        booktemp.set_ID(temp.ID);
        booktemp.set_book();
        booktemp.name = temp.name;
        booktemp.author = temp.author;
        booktemp.borrowing_times = temp.borrowing_times;
        arry.push_back(booktemp);
    }
    inFile.close();
}

#endif //DATABASE_DB_H
