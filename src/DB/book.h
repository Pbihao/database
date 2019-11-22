//
// Created by pbihao on 11/22/19.
//

#ifndef DATABASE_BOOK_H
#define DATABASE_BOOK_H

#include <string>
#define NEW_BOOK 0
#define EDIT_BOOK 1
#define DEL_BOOK 2
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

    int get_ID(){
        return ID;
    }

    string get_name(){
        return name;
    }
    void set_name(string Name){
        state = EDIT_BOOK;
        name = Name;
    }

    string get_author(){
        return author;
    }
    void set_author(string Author){
        state = EDIT_BOOK;
        author = Author;
    }

    int get_borrow_times(){
        return borrowing_times;
    }
    void set_borrow_times(int ntimes){
        state = EDIT_BOOK;
        borrowing_times = ntimes;
    }

    void del_book(){
        state = DEL_BOOK;
    }
};


#endif //DATABASE_BOOK_H
