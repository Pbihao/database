//
// Created by pbihao on 11/23/19.
//
#include "src/DB/book.h"
#include "src/DB/binary_tree.h"
#include "src/indexes/search.h"
#include "src/DB/temp.h"
#include "src/DB/DB.h"
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
Book a[100];
Search_engine engine;
DB db;


void read(string& x){
    x.clear();
    char c = getchar();
    while(c != '\n'){
        x.push_back(c);
        c = getchar();
    }
}

int main(){
    /*
    for(int i = 0; i < 100; i++)a[i].set_ID(i);
    a[0].name = "I am iron man";
    a[1].name = "I'm super man";
    a[2].name = "Nothing is the best thing";
    a[3].name = "The art of data structure";
    a[4].name = "The angry man";
    a[5].name = "A beautiful girl";
    a[6].name = "Who can kill me";
    a[7].name = "Maybe I just want-to kill-myself";
    a[8].name = "Love for thousands years";
    a[9].name = "How to make chinese food";
    vector<Book>arry;
    for(int i = 0; i <= 9; i++)arry.push_back(a[i]);
    engine.init(arry);
    int op, ID = 9;
    string name;
    Book book;
    vector<int >ans;
    while(1) {
        scanf("%d", &op);
        getchar();
        if (op == 0) {
            read(name);
            ID++;
            book = Book(ID, name, "pbihao", 1);
            a[ID] = book;
            engine.insert(book);
        } else if (op == 1) {
            int x;
            scanf("%d", &x);
            getchar();
            engine.erase(a[x]);
        } else if (op == 2) {
            read(name);
            engine.search(name, ans);
            for (auto id: ans)cout << a[id].name << endl;
        }
    }
    //pbh test

//    for(int i = 0; i < 100; i++)a[i].set_ID(i);
//    a[0].name = "I am iron man";
//    a[1].name = "I'm super man";
//    a[2].name = "Nothing is the best thing";
//    a[3].name = "The art of data structure";
//    a[4].name = "The angry man";
//    a[5].name = "A beautiful girl";
//    a[6].name = "Who can kill me";
//    a[7].name = "Maybe I just want-to kill-myself";
//    a[8].name = "Love for thousands years";
//    a[9].name = "How to make chinese food";
//    vector<Book>arry;
//    for(int i = 0; i <= 9; i++)arry.push_back(a[i]);
//    engine.init(arry);
//    int op, ID;
//    string name;
//    vector<int >ans;

//    int step, borrowing_times, state;
//    string author;

//     while(1){
//        scanf("%d", &op);getchar();
//        if(op == 0){
//            read(name);
//            cin>>ID;getchar();
//            book = Book(ID, name, "pbihao", 1);
//            a[ID] = book;
//            engine.insert(book);
//        }else if(op == 1){
//            int x;
//            scanf("%d", &x);getchar();
//            engine.erase(a[x]);
//        }else if(op == 2){
//            read(name);
//            engine.search(name, ans);
//            for(auto id: ans)cout<<a[id].name<<endl;
//        }




    //dwl 文件管理系统测试

    /*int op;
    int i,j;
    int deletedID;

    vector<Book> books;//用户输入的书的信息
    Book book;
    Temp temp1; //将一本书的信息输出到二进制文件之前需要转为Temp类对象
    Temp temp2; //读取二进制文件中的一本书的信息后应先存入Temp类的变量中
    Book booktemp; //将一本书的信息push进vector之前要先转为Book类对象
    vector<Book> readResults;

    //录入图书信息
    string name[10] = {"I am iron man", "I'm super man", "Nothing is the best thing", "The art of data structure",
                       "The angry man", "A beautiful girl", "Who can kill me", "Maybe I just want-to kill-myself",
                       "Love for thousands years", "How to make chinese food"};
    string author[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    int borrowing_times[10] = {9, 8, 7, 6, 10, 3, 2, 1, 56, 78};
    for(i=0;i<10;i++){
        book.set_ID(i);
        book.name = name[i];
        book.author = author[i];
        book.borrowing_times = borrowing_times[i];
        books.push_back(book);
    }


    scanf("%d", &op); getchar();
    if(op == 0){
        ofstream outFile("books.dat", ios::out|ios::binary);
        //将每一本书转为temp类再写入
        for(i=0;i<10;i++){
            temp1.ID = books[i].get_ID();
            temp1.borrowing_times = books[i].borrowing_times;
            for(j=0;j<books[i].name.length();j++){
                temp1.name[j] = books[i].name[j];
            }
            temp1.name[j] = '\n';
            for(j=0;j<books[i].author.length();j++){
                temp1.author[j] = books[i].author[j];
            }
            temp1.author[j] = '\n';
            outFile.write((char*)&temp1, sizeof(Temp));
        }
        outFile.close();
    }else if(op == 1){
        ifstream inFile("books.dat", ios::in|ios::binary);
        if(!inFile){
            cout << "error" << endl;//文件打开错误
>>>>>>> f00776d926b22b73649c6882c01b3e539cdd9bca
        }
        readResults.clear();
        for(i=0;i<10;i++){
            inFile.read((char *)(&temp2), sizeof(Temp));
            booktemp.set_ID(temp2.ID);
            booktemp.name = temp2.name;
            booktemp.author = temp2.author;
            booktemp.borrowing_times = temp2.borrowing_times;
            readResults.push_back(booktemp);
        }
        inFile.close();
        cout << readResults[0].get_ID() << readResults[0].name << readResults[0].author << endl;
    }
    */

    //整个系统测试

    int i;
    Book book;
    vector<Book> bookInfo;

    //录入图书信息到bookInfo中
    string name[10] = {"I am iron man", "I'm super man", "Nothing is the best thing", "The art of data structure",
                       "The angry man", "A beautiful girl", "Who can kill me", "Maybe I just want-to kill-myself",
                       "Love for thousands years", "How to make chinese food"};
    string author[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    int borrowing_times[10] = {9, 8, 7, 6, 10, 3, 2, 1, 56, 78};
    for(i=0;i<10;i++){
        book.set_ID(i);
        book.set_book();
        book.name = name[i];
        book.author = author[i];
        book.borrowing_times = borrowing_times[i];
        bookInfo.push_back(book);
    }

    //将bookInfo的信息存到二进制文件books.dat
    db.write_books(bookInfo);

    //读取二进制文件book.dat的图书信心到arry
    db.read_books();
//    cout << db.arry[0].name << db.arry[1].name << db.arry[2].name << db.arry[3].name << db.arry[4].name << db.arry[5].name <<
//    db.arry[6].name << db.arry[7].name << db.arry[8].name << db.arry[9].name << endl;

    //搜索
    engine.init(db.arry);
    string search_name;
    vector<int >ans;

    while(1) {
     read(search_name);
     engine.search(search_name, ans);
     for (auto id: ans)cout << db.arry[id].name << endl;
    }
    return 0;
}
