//
// Created by pbihao on 11/23/19.
//
#include "src/DB/book.h"
#include "src/DB/binary_tree.h"

#include <string>
#include <cstdio>
using namespace std;
Book a[10];
Binary_tree T;
vector<Book>arry;

int main(){
    for(int i = 0 ; i < 5; i++){
        a[i] = Book(i);
        T.insert(a[i]);
    }
    int num, x, y;
    while(true){
        scanf("%d", &num);
        if(num == 0){
            scanf("%d", &x);
            printf("%d\n", T.query(x).get_ID());
        }else if(num == 1){
            scanf("%d", &x);
            T.erase(x);
        }else if(num == 2){
            scanf("%d", &x);
            T.insert(Book(x));
        }else if(num == 3){
            scanf("%d", &x);
            T.replace(x, Book(x));
        }else if(num == 4){
            T.run(arry);
            for( auto& y: arry){
                printf("%d\n", y.get_ID());
            }
        }
    }
    return 0;
}
