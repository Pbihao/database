//
// Created by pbihao on 11/23/19.
//

#include "sort_times.h"

bool cmp(const Book& a, const Book& b){
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
            if(cmp(T[u], T[u >> 1])){
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
            if((u<<1|1) <= size && cmp(T[u<<1|1], T[u]) && cmp(T[u<<1|1],T[u<<1])){
                swap(T[u<<1|1],T[u]);
                u = u << 1 | 1;
            }else if(cmp(T[u<<1], T[u])){
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