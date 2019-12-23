//
// Created by pbihao on 11/23/19.
//
#include <string>
#include <cstdio>
#include <iostream>
#include "src/DB/DB.h"
#define INSERT_BOOKS 0
#define INSERT 1
#define UPDATE 2
#define ERASE 3
#define FIND_BY_ID 4
#define SEARCH 5
#define FIND_MAX_BORROWED 6
#define SHOW_BOOK_INFO 7
using namespace std;
Book book[12];
DB db_manager;

int main(){
    book[0] = Book(0, "I just want to kill myself!", "pbihao", 190);
    book[1] = Book(1, "Save me now!", "pbihao", 10);
    book[2] = Book(2, "Angry Coward? It's funny", "pbihao", 0);
    book[3] = Book(3, "Don't Save The Bad Man", "pbihao", 19);
    book[4] = Book(4, "Bad but beautiful", "pbihao", 9);
    book[5] = Book(5, "An angry man", "pbihao", 19);
    vector<Book>arry;
    for(int i = 0; i <= 5; i++)arry.push_back(book[i]);
    db_manager.insert_books(arry);
    int op, ID, now_ID = 6;
    string name;
    while(true){
        cin>>op;
        if(op == INSERT){//1
            cin>>name;
            db_manager.insert(Book(now_ID++, name));
        }else if(op == UPDATE){//2
            cin>>ID>>name;
            db_manager.update(Book(ID, name));
        }else if(op == ERASE){//3
            cin>>ID;
            db_manager.erase(db_manager.find_by_ID(ID));
        }else if(op == FIND_BY_ID){//4
            cin>>ID;
            cout<<"name:"<<db_manager.find_by_ID(ID).name<<endl;
        }else if(op == SEARCH){//5
            cin>>name;
            db_manager.search(name);
            for(auto book:db_manager.arry){
                cout<<book.name<<endl;
            }
        }else if(op == FIND_MAX_BORROWED){//6
            db_manager.find_max_borrowed();
            for(auto book:db_manager.arry){
                cout<<book.name<<endl;
            }
        }else if(op == SHOW_BOOK_INFO){//7
            db_manager.show_book_info();
            for(auto book:db_manager.arry){
                cout<<book.name<<endl;
            }
        }
        cin.sync();
    }
    return 0;
}
