//
// Created by pbihao on 11/22/19.
//

#ifndef DATABASE_BOOK_H
#define DATABASE_BOOK_H

#include <string>
#include <cstdio>
#define NEW_BOOK 1
#define DEL_BOOK 2
#define EDIT_BOOK 3
#define DONT_CHANGE 3
#define ERROR -1
using namespace std;

class Book {
private:
    int ID;
    int state;
public:
    string name;
    string author;
    int borrowing_times;

    Book(){}
    Book(int id):ID(id){}//当一本书的ID为-1时代表这是一个错误类
    Book(int id, string Name, string Author, int Borrowing_times){
        ID = id;
        name = Name;
        author = Author;
        borrowing_times = Borrowing_times;
        state = NEW_BOOK;
    }
    Book(int id, string Name){
        ID = id;
        name = Name;
        borrowing_times = rand() % 100;
        state = NEW_BOOK;
    }

    int get_ID(){
        return ID;
    }

    int get_state(){
        return state;
    }

    string get_name(){
        return name;
    }

    string get_author(){
        return author;
    }

    int get_borrow_times(){
        return borrowing_times;
    }

    void del_book(){
        state = DEL_BOOK;
    }

    void set_book(){
        state = NEW_BOOK;
    }
    void update_book(){
        state = EDIT_BOOK;
    }





    void set_name(string Name){
        state = EDIT_BOOK;
        name = Name;
    }

    void set_ID(int x){
        this->ID = x;
    }

    void set_author(string Author){
        state = EDIT_BOOK;
        author = Author;
    }


    void set_borrow_times(int ntimes){
        state = EDIT_BOOK;
        borrowing_times = ntimes;
    }


};


#endif //DATABASE_BOOK_H
