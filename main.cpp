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
#define QUIT 8
using namespace std;
Book book[12];
DB db_manager;

int main(){
    vector<Book>arry;
    int op, ID, now_ID = db_manager.readid();
    string name;
    while(true)
    {
        cin>>op;
        if(op == 0){
            Book bookinit;
            bookinit.set_ID(0);
            bookinit.name = "I just want to kill myself!";
            arry.push_back(bookinit);
            bookinit.set_ID(1);
            bookinit.name = "Save me now!";
            arry.push_back(bookinit);
            bookinit.set_ID(2);
            bookinit.name = "Don't Save The Bad Man";
            arry.push_back(bookinit);
            bookinit.set_ID(3);
            bookinit.name = "Bad but beautiful";
            arry.push_back(bookinit);
            db_manager.pool.write_books(arry);
        }else if(op == INSERT){//1
            name.clear();
            char c = getchar();
            while(c == ' ' || c == '\n')c = getchar();
            while(c != '\n'){
                name.push_back(c);
                c = getchar();
            }
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
        }else if(op == SHOW_BOOK_INFO)
        {//7
            db_manager.show_book_info();
            for(auto book:db_manager.arry)
            {
                cout<<book.name<<" "<< book.get_ID() <<endl;
            }
        }
        else if(op == QUIT)
        {//8
            db_manager.quit();
            break;
        }
        cin.sync();
    }
    return 0;
}
/*
I just want to kill myself! 0
Save me now! 1
hello 2
Don't Save The Bad Man 3
Bad but beautiful 4
An angry man 5
 * */