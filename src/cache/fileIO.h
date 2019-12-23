//
// Created by 杜玮玲 on 2019-12-22.
//

#ifndef DATABASE_FILEIO_H
#define DATABASE_FILEIO_H


#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "../DB/book.h"
#include "temp.h"
#include "queue.h"


class Fileio{
public:
    /*将books中的所有信息写入二进制文件books.dat*/
    void io_write_books(vector<Book>& books);

    /*从二进制文件中文件中读取图书信息到books中*/
    void io_read_books(vector<Book>& books);

    /*打开二进制文件books.dat进行图书的增删改操作*/
    void io_file_operation(Queue queue);
};


void Fileio::io_file_operation(Queue queue){
    int i,j;
    Book book;
    Temp temp;
    Temp temp_find;
    fstream ioFile("books.dat", ios::in|ios::out);//用既读又写的方式打开文件
    if(!ioFile){
        cout << "error" << endl;//文件打开错误
    }
    for(i=0;i<queue.books.queue_size;i++){

        queue.DeQueue(queue.books, book);//从队列里取出一本书

        /*在二进制文件中增加这本书的信息*/
        if(book.get_state() == 1){

            //先转为Temp类
            temp.ID = book.get_ID();
            temp.state = book.get_state();
            temp.borrowing_times = book.borrowing_times;
            for(j=0;j<book.name.length();j++){
                temp.name[j] = book.name[j];
            }
            temp.name[j] = '\0';
            for(j=0;j<book.author.length();j++){
                temp.author[j] = book.author[j];
            }
            temp.author[j] = '\0';

            //定位写指针到文件末尾
            ioFile.seekp(0, ios::end);

            //将这本书的信息写入文件
            ioFile.write((char*)&temp, sizeof(Temp));
        }

        /*在二进制文件中删除这本书的信息*/
        else if(book.get_state() == 2){
            Temp temp_del;
            temp_del.name[0] = '\0';
            int L = 0; //折半查找范围内第一个记录的序号
            int R; //折半查找范围内最后一个记录的序号

            ioFile.seekg(0, ios::end); //移动读指针到文件尾部
            R = ioFile.tellg() / sizeof(Temp) - 1; //计算最后一个记录的序号

            //折半查找到对应id的书本信息，进行更新
            do{
                int mid = (L + R) / 2;
                ioFile.seekg(mid * sizeof(Temp), ios::beg);
                ioFile.read((char *)(&temp_find), sizeof(Temp));
                if(temp_find.ID == book.get_ID()){
                    ioFile.seekg(mid * sizeof(Temp), ios::beg);
                    ioFile.write((char*)&temp_del, sizeof(temp));
                    break;
                }else if(temp_find.ID > temp.ID){
                    R = mid - 1;
                }else{
                    L = mid + 1;
                }
            }while (L <= R);

        }

        /*在二进制文件中修改这本书的信息*/
        else if(book.get_state() == 3){

            int L = 0; //折半查找范围内第一个记录的序号
            int R; //折半查找范围内最后一个记录的序号

            //先转为Temp类
            temp.ID = book.get_ID();
            temp.state = book.get_state();
            temp.borrowing_times = book.borrowing_times;
            for(j=0;j<book.name.length();j++){
                temp.name[j] = book.name[j];
            }
            temp.name[j] = '\0';
            for(j=0;j<book.author.length();j++){
                temp.author[j] = book.author[j];
            }
            temp.author[j] = '\0';

            ioFile.seekg(0, ios::end); //移动读指针到文件尾部
            R = ioFile.tellg() / sizeof(Temp) - 1; //计算最后一个记录的序号

            //折半查找到对应id的书本信息，进行更新
            do{
                int mid = (L + R) / 2;
                ioFile.seekg(mid * sizeof(Temp), ios::beg);
                ioFile.read((char *)(&temp_find), sizeof(Temp));
                if(temp_find.ID == temp.ID){
                    ioFile.seekg(mid * sizeof(Temp), ios::beg);
                    ioFile.write((char*)&temp, sizeof(temp));
                    break;
                }else if(temp_find.ID > temp.ID){
                    R = mid - 1;
                }else{
                    L = mid + 1;
                }
            }while (L <= R);
        }
    }
}

void Fileio::io_write_books(vector<Book>& books){
    int i, j;
    Temp temp;

    ofstream outFile("books.dat", ios::out|ios::binary);

    for(i=0;i<books.size();i++){
        //将每一本书转为temp类再写入
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

        //写入
        outFile.write((char*)&temp, sizeof(Temp));
    }
    outFile.close();
}

void Fileio::io_read_books(vector<Book>& books){
    int i;
    Temp temp;
    Book booktemp;
    int book_size;

    ifstream inFile("books.dat", ios::in|ios::binary);
    if(!inFile){
        cout << "error" << endl;//文件打开错误
    }

    inFile.seekg(0, ios::end);//将文件读指针移到末尾
    book_size = inFile.tellg()/ sizeof(Temp);//计算书的数量
    inFile.seekg(0, ios::beg);//将文件读指针移到开头
    books.clear();

    for(i=0;i<book_size;i++){
        inFile.read((char *)(&temp), sizeof(Temp));
        if(temp.name[0] != '\0'){
            booktemp.set_ID(temp.ID);
            booktemp.set_book();
            booktemp.name = temp.name;
            booktemp.author = temp.author;
            booktemp.borrowing_times = temp.borrowing_times;
            books.push_back(booktemp);
        }
    }
    inFile.close();
}


#endif //DATABASE_FILEIO_H
