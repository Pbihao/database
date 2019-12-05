//
// Created by pbihao on 11/23/19.
//

#ifndef DATABASE_BINARY_TREE_H
#define DATABASE_BINARY_TREE_H

#include "book.h"
#include <vector>
using namespace std;

class Binary_tree{
    struct node{
        Book book;
        node *fa, *ch[2];
        node(){fa = ch[0] = ch[1] = NULL;}
        node(Book bk){
            book = bk;
            fa = ch[0] = ch[1] = NULL;
        }
    };

public:
    node* rt = NULL;
    int Q(node* u);
    void rotate(node* u);
    void splay(node* u,node *top = NULL);
    /*
     * 插入一本新的书，传入的参数是一本书
     * 注意，这本书的所有信息应该由数据库管理系统处理，为了使得结构更加清楚，这里只是单纯地对于树进行处理
     * 而且这个书的ID应该是所有目前已有的书中最大的，否则会出错
     */
    void Insert(node* u, Book book);
    void insert(Book book){Insert(rt, book);};
    //删除一本书，传入一本书的ID
    void Erase(node* u, int ID);
    void erase(int ID){Erase(rt, ID);};
    //查询一本书，传入一本书的ID，返回这本书的类
    Book Query(node*u, int ID);
    Book query(int ID){ return Query(rt, ID);};
    //替换一本书的信息，传入这本书的ID以及需要替换成的书，函数将找到这本书并且进行替换
    void Replace(node* u, int ID, Book book);
    void replace(int ID, Book book){Replace(rt, ID, book);};
    /*
     * 遍历整个树，并且会传入一个vector的引用，将整个树的信息储存到这个vector中
     * !!:注意，在遍历整个树的时候，传进来的的arry会被清空，因此一定要注意对于原有的数据进行储存
     */
    void Run(node* u, vector<Book>& arry);
    void run(vector<Book>& arry){
        arry.clear();
        Run(rt, arry);
    };
};

int Binary_tree::Q(Binary_tree::node *u) {
    if(!u)return 0;
    return u == u->fa->ch[1];
}
void Binary_tree::rotate(Binary_tree::node *u) {
    int d = !Q(u);
    node *f = u->fa, *ff = u->fa->fa;
    if(ff)ff->ch[Q(f)] = u;
    u->fa = ff;
    if(u->ch[d])u->ch[d]->fa = f;
    f->ch[!d] = u->ch[d];
    f->fa = u;
    u->ch[d] = f;
}
void Binary_tree::splay(Binary_tree::node *u, Binary_tree::node *top) {
    while(u->fa != top){
        node *f = u->fa;
        if(f->fa == top)rotate(u);
        else{
            if(Q(f) == Q(u))rotate(f);
            else rotate(u);
            rotate(u);
        }
    }
    if(!top)rt = u;
}
void Binary_tree::Insert(Binary_tree::node *u, Book book) {
    if(!rt){
        rt = new node(book);
        return;
    }
    while(u->ch[1])u = u->ch[1];
    u->ch[1] = new node(book);
    u->ch[1]->fa = u;
    splay(u->ch[1]);
}
void Binary_tree::Erase(Binary_tree::node *u, int ID) {
    if(u == NULL)return;
    if(ID > u->book.get_ID())Erase(u->ch[1], ID);
    else if(ID < u->book.get_ID())Erase(u->ch[0], ID);
    else{
        splay(u);
        if(!u->ch[0]){
            rt = u->ch[1];
            if(u->ch[1])u->ch[1]->fa = NULL;
            delete u;
            return;
        }else if(!u->ch[1]){
            rt = u->ch[0];
            if(u->ch[0])u->ch[0]->fa = NULL;
            delete u;
            return;
        }else{
            node* ls = u->ch[0];
            node* rs = u->ch[1];
            while(ls->ch[1])ls = ls->ch[1];
            splay(ls, u);
            ls->ch[1] = rs;
            ls->fa = NULL;
            rs->fa = ls;
            rt = ls;
            delete u;
        }
    }
}
void Binary_tree::Replace(Binary_tree::node *u, int ID, Book book) {
    if(!u)return;
    if(ID > u->book.get_ID())Replace(u->ch[1], ID, book);
    else if(ID < u->book.get_ID())Replace(u->ch[0], ID, book);
    else{
        splay(u);
        u->book = book;
    }
}

Book Binary_tree::Query(Binary_tree::node *u, int ID) {
    if(!u)return Book(ERROR);
    if(ID > u->book.get_ID())return Query(u->ch[1], ID);
    else if(ID < u->book.get_ID())return Query(u->ch[0], ID);
    else return u->book;
}

void Binary_tree::Run(Binary_tree::node *u, vector<Book> &arry) {
    if(!u)return;
    if(u->ch[0])Run(u->ch[0], arry);
    arry.push_back(u->book);
    if(u->ch[1])Run(u->ch[1], arry);
}


#endif //DATABASE_BINARY_TREE_H
