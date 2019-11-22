//
// Created by pbihao on 11/23/19.
//
#include "src/DB/DB.h"
#include "src/algorithm/sort_times.h"
#include <string>
#include <cstdio>
using namespace std;
string ep = "a";

int main(){
    DB db;
    db.arry.emplace_back(0,ep,ep,3);
    db.arry.emplace_back(0,ep,ep,2);
    db.arry.emplace_back(0,ep,ep,33);
    db.arry.emplace_back(0,ep,ep,34);
    db.arry.emplace_back(0,ep,ep,23);
    db.arry.emplace_back(0,ep,ep,90);
    db.arry.emplace_back(0,ep,ep,1);

    sort_times(&db);
    for(const auto& x:db.arry){
        printf("%d\n", x.borrowing_times);
    }
    return 0;
}
