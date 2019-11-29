//
// Created by pbihao on 11/23/19.
//
#include "src/DB/book.h"
#include "src/DB/binary_tree.h"
#include "src/indexes/search.h"
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
Book a[100];
Search_engine engine;

void read(string& x){
    x.clear();
    char c = getchar();
    while(c != '\n'){
        x.push_back(c);
        c = getchar();
    }
}

int main(){

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
    int op, ID;
    string name;
    Book book;
    vector<int >ans;
    while(1){
        scanf("%d", &op);getchar();
        if(op == 0){
            read(name);
            cin>>ID;getchar();
            book = Book(ID, name, "pbihao", 1);
            a[ID] = book;
            engine.insert(book);
        }else if(op == 1){
            int x;
            scanf("%d", &x);getchar();
            engine.erase(a[x]);
        }else if(op == 2){
            read(name);
            engine.search(name, ans);
            for(auto id: ans)cout<<a[id].name<<endl;
        }
    }

    return 0;
}
