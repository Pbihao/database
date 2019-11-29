//
// Created by pbihao on 11/23/19.
//

#ifndef DATABASE_SORT_TIMES_H
#define DATABASE_SORT_TIMES_H

#include "../DB/DB.h"
/**
 * 传入一个数据库的类，将数据库类中的所有的图书按照被借阅的次数从大到小
 * 从大到小地进行排序
 * @param database
 */
void sort_times(DB* database);

bool cmp_sort_times_h(const Book& a, const Book& b){
    return a.borrowing_times > b.borrowing_times;
}

struct Heap{
    vector<Book> T;
    int size = 0;
    Heap(){T.emplace_back();}
    void insert(Book x){
        T.push_back(x);
        size++;
        int u = size;
        bool not_be_root = true;
        while (not_be_root && u != 1){
            if(cmp_sort_times_h(T[u], T[u >> 1])){
                swap(T[u], T[u >> 1]);
                u = u >> 1;
            }else not_be_root = false;
        }
    }
    Book pop(){
        int u = 1;
        Book ans = T[1];
        swap(T[1], T.back());
        T.pop_back();
        size--;
        bool ok = true;
        while(ok && u << 1 <= size){
            if((u<<1|1) <= size && cmp_sort_times_h(T[u<<1|1], T[u]) && cmp_sort_times_h(T[u<<1|1],T[u<<1])){
                swap(T[u<<1|1],T[u]);
                u = u << 1 | 1;
            }else if(cmp_sort_times_h(T[u<<1], T[u])){
                swap(T[u<<1], T[u]);
                u = u << 1;
            }else ok = false;
        }
        return ans;
    }
    bool empty(){
        return size == 0;
    }
};

void sort_times(DB* database){
    Heap heap;
    for(const auto& book : database->arry){
        heap.insert(book);
    }
    database->arry.clear();
    while(!heap.empty()){
        database->arry.push_back(heap.pop());
    }
}

#endif //DATABASE_SORT_TIMES_H
