//
// Created by 杜玮玲 on 2019-12-03.
//

#ifndef DATABASE_TEMP_H
#define DATABASE_TEMP_H

#include <string>
#include <cstring>
#define NEW_BOOK 0
#define EDIT_BOOK 1
#define DEL_BOOK 2
#define DONT_CHANGE 3
#define ERROR -1
using namespace std;

class Temp {
public:
    int ID;
    int state;
    char name[100];
    char author[30];
    int borrowing_times;

    Temp(){};
    Temp(int id, char Name[], char Author[], int Borrowing_times){
        ID = id;
        strcpy(name, Name);
        strcpy(author, Author);
        borrowing_times = Borrowing_times;
        state = NEW_BOOK;
    }
};



#endif //DATABASE_TEMP_H
